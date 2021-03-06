/*
 * "Small Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It requires a STDOUT  device in your system's hardware.
 *
 * The purpose of this example is to demonstrate the smallest possible Hello
 * World application, using the Nios II HAL library.  The memory footprint
 * of this hosted application is ~332 bytes by default using the standard
 * reference design.  For a more fully featured Hello World application
 * example, see the example titled "Hello World".
 *
 * The memory footprint of this example has been reduced by making the
 * following changes to the normal "Hello World" example.
 * Check in the Nios II Software Developers Manual for a more complete
 * description.
 *
 * In the SW Application project (small_hello_world):
 *
 *  - In the C/C++ Build page
 *
 *    - Set the Optimization Level to -Os
 *
 * In System Library project (small_hello_world_syslib):
 *  - In the C/C++ Build page
 *
 *    - Set the Optimization Level to -Os
 *
 *    - Define the preprocessor option ALT_NO_INSTRUCTION_EMULATION
 *      This removes software exception handling, which means that you cannot
 *      run code compiled for Nios II cpu with a hardware multiplier on a core
 *      without a the multiply unit. Check the Nios II Software Developers
 *      Manual for more details.
 *
 *  - In the System Library page:
 *    - Set Periodic system timer and Timestamp timer to none
 *      This prevents the automatic inclusion of the timer driver.
 *
 *    - Set Max file descriptors to 4
 *      This reduces the size of the file handle pool.
 *
 *    - Check Main function does not exit
 *    - Uncheck Clean exit (flush buffers)
 *      This removes the unneeded call to exit when main returns, since it
 *      won't.
 *
 *    - Check Don't use C++
 *      This builds without the C++ support code.
 *
 *    - Check Small C library
 *      This uses a reduced functionality C library, which lacks
 *      support for buffering, file IO, floating point and getch(), etc.
 *      Check the Nios II Software Developers Manual for a complete list.
 *
 *    - Check Reduced device drivers
 *      This uses reduced functionality drivers if they're available. For the
 *      standard design this means you get polled UART and JTAG UART drivers,
 *      no support for the LCD driver and you lose the ability to program
 *      CFI compliant flash devices.
 *
 *    - Check Access device drivers directly
 *      This bypasses the device file system to access device drivers directly.
 *      This eliminates the space required for the device file system services.
 *      It also provides a HAL version of libc services that access the drivers
 *      directly, further reducing space. Only a limited number of libc
 *      functions are available in this configuration.
 *
 *    - Use ALT versions of stdio routines:
 *
 *           Function                  Description
 *        ===============  =====================================
 *        alt_printf       Only supports %s, %x, and %c ( < 1 Kbyte)
 *        alt_putstr       Smaller overhead than puts with direct drivers
 *                         Note this function doesn't add a newline.
 *        alt_putchar      Smaller overhead than putchar with direct drivers
 *        alt_getchar      Smaller overhead than getchar with direct drivers
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#include <system.h>
#include <sys/alt_stdio.h>
#include <io.h>
#include <unistd.h>

//#include "alt_getch.h"
//#include "alt_putch.h"
#include "alt_getch_jtag_uart.h"
#include "alt_putch_jtag_uart.h"
#include "alt_putstr_jtag_uart.h"
#include "alt_getch_rs232_uart.h"
#include "alt_putch_rs232_uart.h"
#include "alt_putstr_rs232_uart.h"

int eth_getch(int eth);
int eth_putstr(int eth, char *str, void (* const in_loop_callback)(void));
int eth_putchar(int eth, int c);
int eth_send(int eth, int addr, int port);
int jtag_uart_getch(void);
int rs232_uart_getch(void);
void header(void);
int msnibble(int n);
int cmdexec(void);
int cmdread(void);
int cmdwrite(void);
int cmdecho(void);
void printhex(int n, int len);
int output_putstr(char *s);
int output_putchar(int c);
int output_send(void);
int cmdinit(void);
void W4(int addr, int dat);
int R4(int addr);
void idle_function(void);
int wait(int counter);
#define  DELAY(t_us)  wait(2 * (t_us))

/*********************************************************************/
/*********************************************************************/

int io_stream;
int sts;
int argflag;
int arg[4];
int narg;
int dat;
int rdata;
int cmd0;
int cmd1;
int jtag_uart_ready;
int rs232_uart_ready;
int echo_flag;
int echo_eth;
int echo_addr;
int echo_port;
int eth_srcaddr;
int eth_srcport;

/*********************************************************************/
/*********************************************************************/

/*

Ethernet PHY Marvell 88E1111

Configuration for RGMII mode (dev boards CycloneIII,StratixIII)

Reg27 = 0x808B (RGMII/MII to copper)
Reg24 = 0x4108 --> led_link1000 as global link indicator
Reg20 = 0x0C6B --> Tx enabled, RGMII tx delay ON
Reg20 = 0x0CEB --> Tx+Rx enabled, RGMII rx delay ON

W4 810 25B
W4 818 808B

W4 810 258
W4 818 4108

tx delay
W4 810 254
W4 818 C6B

tx+rx delay
W4 810 254
W4 818 CEB

Reset pulse using default config (auto-negotiation ON, any speed accepted)

Reg0 = 1001 0001 01xx xxxx = 0x9140 (bit msb = sw reset)
Reg0 = 0001 0001 01xx xxxx = 0x1140 (with auto-negotiation)

W4 810 240
W4 818 9140
W4 818 1140

Now all LEDs ON: LED_LINK_1000 low, link actived

------- all cmds ------
W4 810 25B
W4 818 808B
W4 810 258
W4 818 4108
W4 810 254
W4 818 CEB
W4 810 240
W4 818 9140
W4 818 1140

!!! NOTA: nuovi indirizzi --> il vecchio base address 810 deve essere sositutito con b00 !!!

*/

/*********************************************************************/
/*********************************************************************/


//
// Simple wait loop (NIOS2 small, 50MHz, delay = 2 * Time_us)
//
int wait(int counter)
{
   int a = 0;
   volatile int b;

   while (counter--)
   {
      a = a + b;
   }

   return (a);
}


void W4(int addr, int dat)
{
   //usleep(5000);
   DELAY(5000);
   IOWR_32DIRECT(addr, 0, dat);
   DELAY(5000);
   //usleep(5000);
   /* Note: some commands cannot be sent too fast (i.e. MDIO r/w access) --> 5ms pause interval */
}


int R4(int addr)
{
   return (IORD_32DIRECT(addr, 0));
}


int cmdinit(void)
{
   /* Configuration for RGMII mode */
   /* Note: SGMII mode --> config skipped, power on defaults to sgmii
   W4(0x810, 0x25B );
   W4(0x818, 0x808B);
   W4(0x810, 0x258 );
   W4(0x818, 0x4108);
   W4(0x810, 0x254 );
   W4(0x818, 0xCEB );
   W4(0x810, 0x240 );
   W4(0x818, 0x9140);
   W4(0x818, 0x1140);
   */

   // Software Reset
/* // !! Debug !! Reset skipped !!
   W4(0xb00, 0x9140);
   W4(0xb08, 0x1140);
   W4(0xb10, 0x9140);
   W4(0xb18, 0x1140);
   W4(0xb20, 0x9140);
   W4(0xb28, 0x1140);
   W4(0xb30, 0x9140);
   W4(0xb38, 0x1140);
   W4(0xb40, 0x9140);
   W4(0xb48, 0x1140);
   W4(0xb50, 0x9140);
   W4(0xb58, 0x1140);
   W4(0xb60, 0x9140);
   W4(0xb68, 0x1140);
   W4(0xb70, 0x9140);
   W4(0xb78, 0x1140);
*/ // !! Debug !! Reset skipped !!

   // CPU_TXPORT enabled (reg1.15 = wena, reg1.10..0 = wframelen = 256)
   W4(0x844, 0x8100); // eth0
   W4(0x884, 0x8100); // eth1
   W4(0x8C4, 0x8100); // eth2
   W4(0x904, 0x8100); // eth3
   W4(0x944, 0x8100); // eth4
   W4(0x984, 0x8100); // eth5
   W4(0x9C4, 0x8100); // eth6
   W4(0xA04, 0x8100); // eth7

   // CPU_RXPORT enabled (reg15.15 = rena)
   W4(0x87C, 0x8000); // eth0
   W4(0x8BC, 0x8000); // eth1
   W4(0x8FC, 0x8000); // eth2
   W4(0x93C, 0x8000); // eth3
   W4(0x97C, 0x8000); // eth4
   W4(0x9BC, 0x8000); // eth5
   W4(0x9FC, 0x8000); // eth6
   W4(0xA3C, 0x8000); // eth7

   return 0;
}


//
// idle_function called by blocking operations
//
void idle_function(void)
{
   alt_getch_rs232_uart(0);
   // NOTE: rs232 chars captured by function 'alt_getch_rs232_uart'
   // (rs232 uart does not have hardware buffer and interrupts are not in use,
   // data is accumulated into function 'alt_getch_rs232_uart()' static buffer)

   //alt_getch_jtag_uart();
   // NOTE: jtag uart has tx/rx hardware buffers so callback not needed
}


#define ETH_REG0  (0x840)
#define ETH_REG1  (0x844)
#define ETH_REG14 (0x878)
#define ETH_REG15 (0x87C)

int eth_getch(int eth)
{
   int r;
   int s;
   int c;
   int REG14;
   int REG15;

   REG14 = ETH_REG14 + ((eth & 0x7) << 6);
   REG15 = ETH_REG15 + ((eth & 0x7) << 6);

   s = IORD_32DIRECT(REG15, 0);
   if ((s & 0xC0000000) == 0x80000000)
   {
      // Frame Ready (rready, not reoframe) : read pulse
      IOWR_32DIRECT(REG15, 0, (s |  0x00001000));
      IOWR_32DIRECT(REG15, 0, (s & ~0x00001000));
      r = IORD_32DIRECT(REG14, 0);
      eth_srcaddr = (r & 0x0000FF00) >> 8;
      eth_srcport = (r & 0x000F0000) >> 16;
      c = r & 0xFF;
      if (c == 0)
      {
         // End of string: flush remaining data using ack pulse
         IOWR_32DIRECT(REG15, 0, (s |  0x00002000));
         IOWR_32DIRECT(REG15, 0, (s & ~0x00002000));
         return (-1);
      }
      return (c);
   }
   else if ((s & 0xC0000000) == 0xC0000000)
   {
      // End of frame: ack pulse
      IOWR_32DIRECT(REG15, 0, (s |  0x00002000));
      IOWR_32DIRECT(REG15, 0, (s & ~0x00002000));
      return (-1);
   }

   return (-1);
}


int eth_putchar(int eth, int c)
{
   int s;
   int REG0;
   int REG1;

   REG0 = ETH_REG0 + ((eth & 0x7) << 6);
   REG1 = ETH_REG1 + ((eth & 0x7) << 6);

   s = IORD_32DIRECT(REG1, 0);
   if ((s & 0xA0000000) == 0x80000000)
   {
      // Ready + NotFull: write pulse
      IOWR_32DIRECT(REG0, 0, (c & 0xFF));
      IOWR_32DIRECT(REG1, 0, (s & ~0x00007000));
      s = IORD_32DIRECT(REG1, 0);
      IOWR_32DIRECT(REG1, 0, (s |  0x00001000));
      return (1);
   }
   else
   {
      return (0);
   }
}


int eth_putstr(int eth, char *str, void (* const in_loop_callback)(void))
{
   int len;
   int e;

   len = 0;
   while (*str)
   {
      if (in_loop_callback != NULL)
         (in_loop_callback)();

      e = eth_putchar(eth, ((*str) & 0xFF));
      if (e < 0)
         return (e);

      len++;
      str++;
   }

   return (len);
}


int eth_send(int eth, int addr, int port)
{
   int s;
   int REG1;

   REG1 = ETH_REG1 + ((eth & 0x7) << 6);

   s = IORD_32DIRECT(REG1, 0);
   if ((s & 0x80008000) == 0x80008000)
   {
      // Ready + Enabled: send to eth_srcaddr/srcport
      IOWR_32DIRECT(REG1, 0, (s & ~0x000007FF) | (256)); // constant framelen
      s = IORD_32DIRECT(REG1, 0);
      IOWR_32DIRECT(REG1, 0, (s & ~0x00FF0000) | ((addr & 0xFF) << 16));
      s = IORD_32DIRECT(REG1, 0);
      IOWR_32DIRECT(REG1, 0, (s & ~0x0F000000) | ((port & 0x0F) << 24));
      //
      s = IORD_32DIRECT(REG1, 0);
      IOWR_32DIRECT(REG1, 0, (s & ~0x00007000));
      s = IORD_32DIRECT(REG1, 0);
      IOWR_32DIRECT(REG1, 0, (s |  0x00002000));
      return (0);
   }
   else
   {
      return (-1);
   }
}


//
// jtag/rs232 high level getch() functions
//
// - data is locally accumulated until a complete line is received
// - main FSM applies a common parser logic for all interfaces:
//   data is processed one character at the time from the same
//   io_stream (getch() functions must generate a continuous
//   sequence of characters when a line is ready)
//
int jtag_uart_getch(void)
{
   static unsigned char buf[32];
   static int buflen;
   static int wrindex;
   static int rdindex;
   static int flagfull;
   int c;

   if (buflen <= 0)
   {
      // empty buffer: jtag uart test
      c = alt_getch_jtag_uart();
      if (c >= 0)
      {
         if (wrindex < (sizeof(buf)/sizeof(buf[0])))
         {
            buf[wrindex++] = (unsigned char) c;
         }
         else
         {
            flagfull = 1;
         }

         if (c == 0 || c == '\n' || c == '\r')
         {
            // end of line detected: buffer ready
            buflen = wrindex;
            if (flagfull)
            {
               //// errfull indicator
               //buf[0] = '!';
               //buf[1] = '!';
               //buf[2] = '!';

               // errfull: forced end-of-line
               buf[wrindex - 1] = (unsigned char) c;
            }
            wrindex = 0;
            rdindex = 0;
            flagfull = 0;
         }

         // local echo for nios2-terminal
         alt_putch_jtag_uart(c, 0, NULL);
      }
   }

   if (buflen > 0)
   {
      // getch from buffer
      buflen--;
      c = buf[rdindex++];
      return (c);
   }

   return (-1);
}
//
//
int rs232_uart_getch(void)
{
   static unsigned char buf[32];
   static int buflen;
   static int wrindex;
   static int rdindex;
   static int flagfull;
   int nloop;
   int c;

   if (buflen <= 0)
   {
      // empty buffer: rs232 uart test
      nloop = alt_getch_rs232_uart(0);
      while (nloop > 0)
      {
         c = alt_getch_rs232_uart(1);
         if (c < 0)
            break;

         if (wrindex < (sizeof(buf)/sizeof(buf[0])))
         {
            buf[wrindex++] = (unsigned char) c;
         }
         else
         {
            flagfull = 1;
         }

         if (c == 0 || c == '\n' || c == '\r')
         {
            // end of line detected: buffer ready
            buflen = wrindex;
            if (flagfull)
            {
               //// errfull indicator
               //buf[0] = '!';
               //buf[1] = '!';
               //buf[2] = '!';

               // errfull: forced end-of-line
               buf[wrindex - 1] = (unsigned char) c;
            }
            wrindex = 0;
            rdindex = 0;
            flagfull = 0;
            break;
         }

         //// local echo for nios2-terminal
         //alt_putch_rs232_uart(c, 0, NULL);

         nloop--;
      }
   }

   if (buflen > 0)
   {
      // getch from buffer
      buflen--;
      c = buf[rdindex++];
      return (c);
   }

   return (-1);
}


int output_putchar(int c)
{
   int e;

   e = 0;

   if (io_stream == 0)
   {
      /* jtag_uart selected: blocking putch() */
      // NOTE: we use a blocking putch() to guarantee complete data transmission
      // when slow jtag_uart interface and tx hardware buffer is full
      e = alt_putch_jtag_uart(c, 1, &idle_function);

      /* echo */
      if (echo_flag)
         e = eth_putchar(echo_eth, c);
   }
   else if (io_stream == 1)
   {
      /* rs232_uart selected: blocking putch() */
      // NOTE: we must use a blocking putch() because rs232_uart does not have any
      // form of transmission buffer
      e = alt_putch_rs232_uart(c, 1, &idle_function);

      /* echo */
      if (echo_flag)
         e = eth_putchar(echo_eth, c);
   }
   else if (io_stream >= 2 && io_stream <= 9)
   {
      /* eth interface selected: non-blocking putchar() */
      // NOTE: all functions eth_putchar/eth_putstr are non-blocking by
      // default (eth interface has big rx/tx buffers and we assume txport
      // always ready --> when txport not ready or buffer full condition data
      // is simply discarded)
      e = eth_putchar(io_stream - 2, c);
   }

   return (e);
}


int output_putstr(char *s)
{
   int e;

   e = 0;

   if (io_stream == 0)
   {
      e = alt_putstr_jtag_uart(s, 1, &idle_function);

      /* echo */
      if (echo_flag)
         e = eth_putstr(echo_eth, s, &idle_function);
   }
   if (io_stream == 1)
   {
      e = alt_putstr_rs232_uart(s, 1, &idle_function);

      /* echo */
      if (echo_flag)
         e = eth_putstr(echo_eth, s, &idle_function);
   }
   if (io_stream >= 2 && io_stream <= 9)
   {
      e = eth_putstr(io_stream - 2, s, &idle_function);
   }

   return (e);
}


int output_send(void)
{
   int e = 0;

   if (io_stream == 0 || io_stream == 1)
   {
      // uart terminator/prompt
      output_putstr("ready\n");
      // uart-echo send
      if (echo_flag)
         e = eth_send(echo_eth, echo_addr, echo_port);
   }
   else if (io_stream >= 2 && io_stream <= 9)
   {
      // eth send
      e = eth_send(io_stream - 2, eth_srcaddr, eth_srcport);
   }

   return (e);
}


int msnibble(int n)
{
   n = (n >> 28) & 0xF;
   if (n >= 0xA && n <= 0xF)
      return ('A' + n - 0xA);
   return ('0' + n);

   /*
   n = n & 0xF0000000;
   if (n == 0xF0000000) return 'F';
   if (n == 0xE0000000) return 'E';
   if (n == 0xD0000000) return 'D';
   if (n == 0xC0000000) return 'C';
   if (n == 0xB0000000) return 'B';
   if (n == 0xA0000000) return 'A';
   if (n == 0x90000000) return '9';
   if (n == 0x80000000) return '8';
   if (n == 0x70000000) return '7';
   if (n == 0x60000000) return '6';
   if (n == 0x50000000) return '5';
   if (n == 0x40000000) return '4';
   if (n == 0x30000000) return '3';
   if (n == 0x20000000) return '2';
   if (n == 0x10000000) return '1';
   return '0';
   */
}


void printhex(int n, int len)
{
   /*
   output_putchar(msnibble(n <<  0));
   output_putchar(msnibble(n <<  4));
   output_putchar(msnibble(n <<  8));
   output_putchar(msnibble(n << 12));
   output_putchar(msnibble(n << 16));
   output_putchar(msnibble(n << 20));
   output_putchar(msnibble(n << 24));
   output_putchar(msnibble(n << 28));
   */

   int i;

   for (i = 8; i > 0; i--)
   {
      if (i <= len)
         output_putchar(msnibble(n));

      n = n << 4;
   }
}

/*********************************************************************/
/*********************************************************************/

int cmdread(void)
{
   int e = 0;

   if (cmd1 == '1')
   {
      rdata = IORD_8DIRECT(arg[0], 0);
   }
   else if (cmd1 == '2')
   {
      rdata = IORD_16DIRECT(arg[0], 0);
   }
   else if (cmd1 == '4')
   {
      rdata = IORD_32DIRECT(arg[0], 0);
   }
   else
   {
      e = -1;
   }

   if (e == 0)
   {
      output_putchar('\n');
      output_putchar(cmd0);
      output_putchar(cmd1);
      output_putstr(" = 0x");
      printhex(rdata, 8);
      output_putstr(" (Addr = 0x");
      printhex(arg[0], 8);
      output_putstr(")\n");
      output_send();
   }

   //output_send();
   return (e);
}


int cmdwrite(void)
{
   int e = 0;

   if (cmd1 == '1')
   {
      IOWR_8DIRECT(arg[0], 0, arg[1]);
   }
   else if (cmd1 == '2')
   {
      IOWR_16DIRECT(arg[0], 0, arg[1]);
   }
   else if (cmd1 == '4')
   {
      IOWR_32DIRECT(arg[0], 0, arg[1]);
   }
   else
   {
      e = -1;
   }

   if (e == 0)
   {
      output_putchar('\n');
      output_putchar(cmd0);
      output_putchar(cmd1);
      output_putstr(" = 0x");
      printhex(arg[1], 8);
      output_putstr(" (Addr = 0x");
      printhex(arg[0], 8);
      output_putstr(")\n");
   }

   output_send();
   return (e);
}


int cmdecho(void)
{
   int e = 0;

   if (cmd1 == '0' || (cmd1 == '1' && (narg == 0 || narg == 3)))
   {
      if (cmd1 == '0')
      {
         // echo OFF
         echo_flag = 0;
         output_putstr("\nE0 : ECHO OFF");
      }
      else if (cmd1 == '1')
      {
         // echo ON
         echo_flag = 1;
         if (narg == 3)
         {
            // echo params updated
            echo_eth  = arg[0] & 0x7;
            echo_addr = arg[1] & 0xFF;
            echo_port = arg[2] & 0xF;
         }
         output_putstr("\nE1 : ECHO ON");
      }
      // echo params
      output_putstr(" (eth=0x");
      printhex(echo_eth, 1);
      output_putstr(",addr=0x");
      printhex(echo_addr, 2);
      output_putstr(",port=0x");
      printhex(echo_port, 1);
      output_putstr(")\n");
      output_send();
   }
   else
      e = -1;

   return (e);
}


void header(void)
{
   output_putstr("Hello from Nios II!\n");
   output_putstr("Avalon r/w interface (v1.0):\n\n");
   output_putstr("{R1|R2|R4} {addr}        --> Rn = Read 1|2|4 bytes\n");
   output_putstr("{W1|W2|W4} {addr} {data} --> Wn = Write 1|2|4 bytes\n");
   output_putstr("{E0}|{E1 eth addr port}  --> ETH ECHO On/Off\n");
   output_send();
}


int cmdexec(void)
{
   int e = -1;

   if (sts == 0)
   {
      // nop
      output_putstr("nop\n");
      output_send();
      e = 0;
   }
   else if (sts == 99 + 2)
   {
      // standard command with invalid char on args: command not executed
   }
   else if ((cmd0 == 'r' || cmd0 == 'R') && (cmd1 == '1' || cmd1 == '2' || cmd1 == '4'))
   {
      if (narg == 1)
      {
         e = cmdread();
      }
   }
   else if ((cmd0 == 'w' || cmd0 == 'W') && (cmd1 == '1' || cmd1 == '2' || cmd1 == '4'))
   {
      if (narg == 2)
      {
         e = cmdwrite();
      }
   }
   else if ((cmd0 == 'e' || cmd0 == 'E') && (cmd1 == '0' || cmd1 == '1'))
   {
      e = cmdecho();
   }
   else if (cmd0 == '?')
   {
      header();
      e = 0;
   }

   if (e)
   {
      output_putstr("???\n");
      output_send();
   }

   return (e);
}

/*********************************************************************/
/*********************************************************************/

int main()
{
   int c;
   int blank;

   // init commands
   cmdinit();

   // hello msg
   header();

   // main endless loop
   while (1)
   {
 	   // getchar loop
      do
 	   {
         idle_function();

         if (io_stream == 0)
         {
            // jtag_uart test
            c = jtag_uart_getch();
         }
         else if (io_stream == 1)
         {
            // rs232_uart test
            c = rs232_uart_getch();
         }
         else
         {
            // eth test
            c = eth_getch(io_stream - 2);
         }
         //
         if (c < 0)
         {
            // current io_stream not ready: switch to next
            io_stream++;
            if (io_stream > 9)
               io_stream = 0;
            // line-parser-FSM restarts
            sts = 0;
         }
      } while (c < 0);

      // echo to current io_stream
      output_putchar(c);

      // blank filter
      blank = 0;
      if ((c == 0) || (c == ' ') || (c == '\t') || (c == '\n') || (c == '\r'))
      {
         blank = 1;
         // note: eol ('\n' or '\r') mapped as blank char
      }

      // line-parser-FSM
      switch (sts)
      {
      case 0:
         // cmd0
         cmd0 = 0;
         if (!blank)
         {
            cmd0 = c;
            sts = 1;
         }
         break;

      case 1:
         // cmd1
         if (!blank)
         {
            cmd1 = c;
            sts = 2;
         }
         else
         {
            // single char command detected
            sts = 99 + 0;
         }
         break;

      case 2:
         // blank check
         if (blank)
         {
            narg = 0;
            dat = 0;
            argflag = 0;
            sts = 3;
         }
         else
         {
            // command with 3 or more consecutive chars detected
            sts = 99 + 1;
         }
         break;

      case 3:
         // 2 chars standard command: arg0..N decoded
         if (blank)
         {
            if (argflag == 0)
            {
               // extra blank ignored
            }
            else if (narg < sizeof(arg)/sizeof(arg[0]))
            {
               arg[narg] = dat;
               narg++;
               dat = 0;
               argflag = 0;
            }
         }
         else if (((c >= '0') && (c <= '9')))
         {
            dat = (dat << 4) | (c - '0');
            argflag = 1;
         }
         else if ((c >= 'A') && (c <= 'F'))
         {
            dat = (dat << 4) | (c - 'A' + 10);
            argflag = 1;
         }
         else if ((c >= 'a') && (c <= 'f'))
         {
            dat = (dat << 4) | (c - 'a' + 10);
            argflag = 1;
         }
         else
         {
            // invalid char on args: command line error signaled
            sts = 99 + 2;
         }
         break;

      default:
         // error: line-parser-FSM stops (next 'cmdexec()' will decode errors)
         break;
      }

      // command exec when eol
      if (c == 0 || c == '\n' || c == '\r')
      {
         // command exec
         cmdexec();
         // line-parser-FSM restarts
         sts = 0;
      }
   }
}

