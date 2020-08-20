/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios_cpu' in SOPC Builder design 'testbench_ls'
 * SOPC Builder design path: ../../testbench_ls.sopcinfo
 *
 * Generated: Wed Aug 19 14:05:39 CEST 2020
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x80100820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 200000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x20
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x80080020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 200000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 1
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_EXTRA_EXCEPTION_INFO
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x20
#define ALT_CPU_NAME "nios_cpu"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x80080000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x80100820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 200000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x20
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x80080020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 1
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_EXTRA_EXCEPTION_INFO
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x20
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x80080000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_TIMER
#define __ALTERA_MEM_IF_DDR2_EMIF
#define __ALTERA_MSGDMA
#define __ALTERA_NIOS2_GEN2


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Stratix IV"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag"
#define ALT_STDERR_BASE 0x801011c0
#define ALT_STDERR_DEV jtag
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag"
#define ALT_STDIN_BASE 0x801011c0
#define ALT_STDIN_DEV jtag
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag"
#define ALT_STDOUT_BASE 0x801011c0
#define ALT_STDOUT_DEV jtag
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "testbench_ls"


/*
 * ctrl_sig configuration
 *
 */

#define ALT_MODULE_CLASS_ctrl_sig altera_avalon_pio
#define CTRL_SIG_BASE 0x80101150
#define CTRL_SIG_BIT_CLEARING_EDGE_REGISTER 0
#define CTRL_SIG_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CTRL_SIG_CAPTURE 0
#define CTRL_SIG_DATA_WIDTH 4
#define CTRL_SIG_DO_TEST_BENCH_WIRING 0
#define CTRL_SIG_DRIVEN_SIM_VALUE 0
#define CTRL_SIG_EDGE_TYPE "NONE"
#define CTRL_SIG_FREQ 200000000
#define CTRL_SIG_HAS_IN 0
#define CTRL_SIG_HAS_OUT 1
#define CTRL_SIG_HAS_TRI 0
#define CTRL_SIG_IRQ -1
#define CTRL_SIG_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CTRL_SIG_IRQ_TYPE "NONE"
#define CTRL_SIG_NAME "/dev/ctrl_sig"
#define CTRL_SIG_RESET_VALUE 0
#define CTRL_SIG_SPAN 16
#define CTRL_SIG_TYPE "altera_avalon_pio"


/*
 * ddr2_ram configuration
 *
 */

#define ALT_MODULE_CLASS_ddr2_ram altera_mem_if_ddr2_emif
#define DDR2_RAM_BASE 0x0
#define DDR2_RAM_IRQ -1
#define DDR2_RAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DDR2_RAM_NAME "/dev/ddr2_ram"
#define DDR2_RAM_SPAN 1073741824
#define DDR2_RAM_TYPE "altera_mem_if_ddr2_emif"


/*
 * ddr2_ram_1 configuration
 *
 */

#define ALT_MODULE_CLASS_ddr2_ram_1 altera_mem_if_ddr2_emif
#define DDR2_RAM_1_BASE 0x40000000
#define DDR2_RAM_1_IRQ -1
#define DDR2_RAM_1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DDR2_RAM_1_NAME "/dev/ddr2_ram_1"
#define DDR2_RAM_1_SPAN 1073741824
#define DDR2_RAM_1_TYPE "altera_mem_if_ddr2_emif"


/*
 * dma_fifo_subsystem_1_dma_csr configuration
 *
 */

#define ALT_MODULE_CLASS_dma_fifo_subsystem_1_dma_csr altera_msgdma
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_BASE 0x80101080
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_BURST_ENABLE 1
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_BURST_WRAPPING_SUPPORT 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_CHANNEL_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_CHANNEL_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_CHANNEL_WIDTH 8
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_DATA_FIFO_DEPTH 2048
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_DATA_WIDTH 256
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_DESCRIPTOR_FIFO_DEPTH 128
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_DMA_MODE 1
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_ENHANCED_FEATURES 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_ERROR_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_ERROR_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_ERROR_WIDTH 8
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_IRQ 2
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_MAX_BURST_COUNT 4
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_MAX_BYTE 4096
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_MAX_STRIDE 1
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_NAME "/dev/dma_fifo_subsystem_1_dma_csr"
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_PACKET_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_PACKET_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_PREFETCHER_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_PROGRAMMABLE_BURST_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_RESPONSE_PORT 2
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_SPAN 32
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_STRIDE_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_STRIDE_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_TRANSFER_TYPE "Full Word Accesses Only"
#define DMA_FIFO_SUBSYSTEM_1_DMA_CSR_TYPE "altera_msgdma"


/*
 * dma_fifo_subsystem_1_dma_descriptor_slave configuration
 *
 */

#define ALT_MODULE_CLASS_dma_fifo_subsystem_1_dma_descriptor_slave altera_msgdma
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_BASE 0x80101190
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_BURST_ENABLE 1
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_BURST_WRAPPING_SUPPORT 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_CHANNEL_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_CHANNEL_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_CHANNEL_WIDTH 8
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_DATA_FIFO_DEPTH 2048
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_DATA_WIDTH 256
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_DESCRIPTOR_FIFO_DEPTH 128
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_DMA_MODE 1
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_ENHANCED_FEATURES 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_ERROR_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_ERROR_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_ERROR_WIDTH 8
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_IRQ -1
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_MAX_BURST_COUNT 4
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_MAX_BYTE 4096
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_MAX_STRIDE 1
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_NAME "/dev/dma_fifo_subsystem_1_dma_descriptor_slave"
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_PACKET_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_PACKET_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_PREFETCHER_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_PROGRAMMABLE_BURST_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_RESPONSE_PORT 2
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_SPAN 16
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_STRIDE_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_STRIDE_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_TRANSFER_TYPE "Full Word Accesses Only"
#define DMA_FIFO_SUBSYSTEM_1_DMA_DESCRIPTOR_SLAVE_TYPE "altera_msgdma"


/*
 * dma_fifo_subsystem_2_dma_csr configuration
 *
 */

#define ALT_MODULE_CLASS_dma_fifo_subsystem_2_dma_csr altera_msgdma
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_BASE 0x80101060
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_BURST_ENABLE 1
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_BURST_WRAPPING_SUPPORT 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_CHANNEL_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_CHANNEL_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_CHANNEL_WIDTH 8
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_DATA_FIFO_DEPTH 2048
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_DATA_WIDTH 256
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_DESCRIPTOR_FIFO_DEPTH 128
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_DMA_MODE 1
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_ENHANCED_FEATURES 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_ERROR_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_ERROR_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_ERROR_WIDTH 8
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_IRQ 3
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_MAX_BURST_COUNT 4
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_MAX_BYTE 4096
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_MAX_STRIDE 1
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_NAME "/dev/dma_fifo_subsystem_2_dma_csr"
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_PACKET_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_PACKET_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_PREFETCHER_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_PROGRAMMABLE_BURST_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_RESPONSE_PORT 2
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_SPAN 32
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_STRIDE_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_STRIDE_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_TRANSFER_TYPE "Full Word Accesses Only"
#define DMA_FIFO_SUBSYSTEM_2_DMA_CSR_TYPE "altera_msgdma"


/*
 * dma_fifo_subsystem_2_dma_descriptor_slave configuration
 *
 */

#define ALT_MODULE_CLASS_dma_fifo_subsystem_2_dma_descriptor_slave altera_msgdma
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_BASE 0x80101180
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_BURST_ENABLE 1
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_BURST_WRAPPING_SUPPORT 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_CHANNEL_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_CHANNEL_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_CHANNEL_WIDTH 8
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_DATA_FIFO_DEPTH 2048
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_DATA_WIDTH 256
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_DESCRIPTOR_FIFO_DEPTH 128
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_DMA_MODE 1
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_ENHANCED_FEATURES 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_ERROR_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_ERROR_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_ERROR_WIDTH 8
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_IRQ -1
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_MAX_BURST_COUNT 4
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_MAX_BYTE 4096
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_MAX_STRIDE 1
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_NAME "/dev/dma_fifo_subsystem_2_dma_descriptor_slave"
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_PACKET_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_PACKET_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_PREFETCHER_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_PROGRAMMABLE_BURST_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_RESPONSE_PORT 2
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_SPAN 16
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_STRIDE_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_STRIDE_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_TRANSFER_TYPE "Full Word Accesses Only"
#define DMA_FIFO_SUBSYSTEM_2_DMA_DESCRIPTOR_SLAVE_TYPE "altera_msgdma"


/*
 * dma_fifo_subsystem_3_dma_csr configuration
 *
 */

#define ALT_MODULE_CLASS_dma_fifo_subsystem_3_dma_csr altera_msgdma
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_BASE 0x80101040
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_BURST_ENABLE 1
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_BURST_WRAPPING_SUPPORT 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_CHANNEL_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_CHANNEL_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_CHANNEL_WIDTH 8
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_DATA_FIFO_DEPTH 2048
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_DATA_WIDTH 256
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_DESCRIPTOR_FIFO_DEPTH 128
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_DMA_MODE 1
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_ENHANCED_FEATURES 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_ERROR_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_ERROR_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_ERROR_WIDTH 8
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_IRQ 4
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_MAX_BURST_COUNT 4
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_MAX_BYTE 4096
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_MAX_STRIDE 1
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_NAME "/dev/dma_fifo_subsystem_3_dma_csr"
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_PACKET_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_PACKET_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_PREFETCHER_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_PROGRAMMABLE_BURST_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_RESPONSE_PORT 2
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_SPAN 32
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_STRIDE_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_STRIDE_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_TRANSFER_TYPE "Full Word Accesses Only"
#define DMA_FIFO_SUBSYSTEM_3_DMA_CSR_TYPE "altera_msgdma"


/*
 * dma_fifo_subsystem_3_dma_descriptor_slave configuration
 *
 */

#define ALT_MODULE_CLASS_dma_fifo_subsystem_3_dma_descriptor_slave altera_msgdma
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_BASE 0x80101170
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_BURST_ENABLE 1
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_BURST_WRAPPING_SUPPORT 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_CHANNEL_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_CHANNEL_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_CHANNEL_WIDTH 8
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_DATA_FIFO_DEPTH 2048
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_DATA_WIDTH 256
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_DESCRIPTOR_FIFO_DEPTH 128
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_DMA_MODE 1
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_ENHANCED_FEATURES 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_ERROR_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_ERROR_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_ERROR_WIDTH 8
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_IRQ -1
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_MAX_BURST_COUNT 4
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_MAX_BYTE 4096
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_MAX_STRIDE 1
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_NAME "/dev/dma_fifo_subsystem_3_dma_descriptor_slave"
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_PACKET_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_PACKET_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_PREFETCHER_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_PROGRAMMABLE_BURST_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_RESPONSE_PORT 2
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_SPAN 16
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_STRIDE_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_STRIDE_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_TRANSFER_TYPE "Full Word Accesses Only"
#define DMA_FIFO_SUBSYSTEM_3_DMA_DESCRIPTOR_SLAVE_TYPE "altera_msgdma"


/*
 * dma_fifo_subsystem_4_dma_csr configuration
 *
 */

#define ALT_MODULE_CLASS_dma_fifo_subsystem_4_dma_csr altera_msgdma
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_BASE 0x80101020
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_BURST_ENABLE 1
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_BURST_WRAPPING_SUPPORT 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_CHANNEL_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_CHANNEL_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_CHANNEL_WIDTH 8
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_DATA_FIFO_DEPTH 2048
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_DATA_WIDTH 256
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_DESCRIPTOR_FIFO_DEPTH 128
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_DMA_MODE 1
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_ENHANCED_FEATURES 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_ERROR_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_ERROR_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_ERROR_WIDTH 8
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_IRQ 5
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_MAX_BURST_COUNT 4
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_MAX_BYTE 4096
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_MAX_STRIDE 1
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_NAME "/dev/dma_fifo_subsystem_4_dma_csr"
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_PACKET_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_PACKET_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_PREFETCHER_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_PROGRAMMABLE_BURST_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_RESPONSE_PORT 2
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_SPAN 32
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_STRIDE_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_STRIDE_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_TRANSFER_TYPE "Full Word Accesses Only"
#define DMA_FIFO_SUBSYSTEM_4_DMA_CSR_TYPE "altera_msgdma"


/*
 * dma_fifo_subsystem_4_dma_descriptor_slave configuration
 *
 */

#define ALT_MODULE_CLASS_dma_fifo_subsystem_4_dma_descriptor_slave altera_msgdma
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_BASE 0x80101160
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_BURST_ENABLE 1
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_BURST_WRAPPING_SUPPORT 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_CHANNEL_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_CHANNEL_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_CHANNEL_WIDTH 8
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_DATA_FIFO_DEPTH 2048
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_DATA_WIDTH 256
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_DESCRIPTOR_FIFO_DEPTH 128
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_DMA_MODE 1
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_ENHANCED_FEATURES 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_ERROR_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_ERROR_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_ERROR_WIDTH 8
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_IRQ -1
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_MAX_BURST_COUNT 4
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_MAX_BYTE 4096
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_MAX_STRIDE 1
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_NAME "/dev/dma_fifo_subsystem_4_dma_descriptor_slave"
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_PACKET_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_PACKET_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_PREFETCHER_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_PROGRAMMABLE_BURST_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_RESPONSE_PORT 2
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_SPAN 16
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_STRIDE_ENABLE 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_STRIDE_ENABLE_DERIVED 0
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_TRANSFER_TYPE "Full Word Accesses Only"
#define DMA_FIFO_SUBSYSTEM_4_DMA_DESCRIPTOR_SLAVE_TYPE "altera_msgdma"


/*
 * dma_fifo_susbystem_dma_csr configuration
 *
 */

#define ALT_MODULE_CLASS_dma_fifo_susbystem_dma_csr altera_msgdma
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_BASE 0x801010a0
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_BURST_ENABLE 1
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_BURST_WRAPPING_SUPPORT 0
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_CHANNEL_ENABLE 0
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_CHANNEL_ENABLE_DERIVED 0
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_CHANNEL_WIDTH 8
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_DATA_FIFO_DEPTH 2048
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_DATA_WIDTH 256
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_DESCRIPTOR_FIFO_DEPTH 128
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_DMA_MODE 1
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_ENHANCED_FEATURES 0
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_ERROR_ENABLE 0
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_ERROR_ENABLE_DERIVED 0
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_ERROR_WIDTH 8
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_IRQ 1
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_MAX_BURST_COUNT 4
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_MAX_BYTE 4096
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_MAX_STRIDE 1
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_NAME "/dev/dma_fifo_susbystem_dma_csr"
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_PACKET_ENABLE 0
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_PACKET_ENABLE_DERIVED 0
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_PREFETCHER_ENABLE 0
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_PROGRAMMABLE_BURST_ENABLE 0
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_RESPONSE_PORT 2
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_SPAN 32
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_STRIDE_ENABLE 0
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_STRIDE_ENABLE_DERIVED 0
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_TRANSFER_TYPE "Full Word Accesses Only"
#define DMA_FIFO_SUSBYSTEM_DMA_CSR_TYPE "altera_msgdma"


/*
 * dma_fifo_susbystem_dma_descriptor_slave configuration
 *
 */

#define ALT_MODULE_CLASS_dma_fifo_susbystem_dma_descriptor_slave altera_msgdma
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_BASE 0x801011a0
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_BURST_ENABLE 1
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_BURST_WRAPPING_SUPPORT 0
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_CHANNEL_ENABLE 0
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_CHANNEL_ENABLE_DERIVED 0
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_CHANNEL_WIDTH 8
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_DATA_FIFO_DEPTH 2048
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_DATA_WIDTH 256
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_DESCRIPTOR_FIFO_DEPTH 128
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_DMA_MODE 1
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_ENHANCED_FEATURES 0
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_ERROR_ENABLE 0
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_ERROR_ENABLE_DERIVED 0
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_ERROR_WIDTH 8
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_IRQ -1
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_MAX_BURST_COUNT 4
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_MAX_BYTE 4096
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_MAX_STRIDE 1
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_NAME "/dev/dma_fifo_susbystem_dma_descriptor_slave"
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_PACKET_ENABLE 0
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_PACKET_ENABLE_DERIVED 0
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_PREFETCHER_ENABLE 0
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_PROGRAMMABLE_BURST_ENABLE 0
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_RESPONSE_PORT 2
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_SPAN 16
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_STRIDE_ENABLE 0
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_STRIDE_ENABLE_DERIVED 0
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_TRANSFER_TYPE "Full Word Accesses Only"
#define DMA_FIFO_SUSBYSTEM_DMA_DESCRIPTOR_SLAVE_TYPE "altera_msgdma"


/*
 * from_ETH_to_DDR_ETH_DMA_csr configuration
 *
 */

#define ALT_MODULE_CLASS_from_ETH_to_DDR_ETH_DMA_csr altera_msgdma
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_BASE 0x801010c0
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_BURST_ENABLE 0
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_BURST_WRAPPING_SUPPORT 0
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_CHANNEL_ENABLE 0
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_CHANNEL_ENABLE_DERIVED 0
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_CHANNEL_WIDTH 8
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_DATA_FIFO_DEPTH 64
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_DATA_WIDTH 256
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_DESCRIPTOR_FIFO_DEPTH 128
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_DMA_MODE 2
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_ENHANCED_FEATURES 0
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_ERROR_ENABLE 0
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_ERROR_ENABLE_DERIVED 0
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_ERROR_WIDTH 8
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_IRQ 0
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_MAX_BURST_COUNT 2
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_MAX_BYTE 2048
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_MAX_STRIDE 1
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_NAME "/dev/from_ETH_to_DDR_ETH_DMA_csr"
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_PACKET_ENABLE 1
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_PACKET_ENABLE_DERIVED 1
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_PREFETCHER_ENABLE 0
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_PROGRAMMABLE_BURST_ENABLE 0
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_RESPONSE_PORT 2
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_SPAN 32
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_STRIDE_ENABLE 0
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_STRIDE_ENABLE_DERIVED 0
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_TRANSFER_TYPE "Aligned Accesses"
#define FROM_ETH_TO_DDR_ETH_DMA_CSR_TYPE "altera_msgdma"


/*
 * from_ETH_to_DDR_ETH_DMA_descriptor_slave configuration
 *
 */

#define ALT_MODULE_CLASS_from_ETH_to_DDR_ETH_DMA_descriptor_slave altera_msgdma
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_BASE 0x801011b0
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_BURST_ENABLE 0
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_BURST_WRAPPING_SUPPORT 0
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_CHANNEL_ENABLE 0
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_CHANNEL_ENABLE_DERIVED 0
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_CHANNEL_WIDTH 8
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_DATA_FIFO_DEPTH 64
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_DATA_WIDTH 256
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_DESCRIPTOR_FIFO_DEPTH 128
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_DMA_MODE 2
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_ENHANCED_FEATURES 0
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_ERROR_ENABLE 0
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_ERROR_ENABLE_DERIVED 0
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_ERROR_WIDTH 8
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_IRQ -1
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_MAX_BURST_COUNT 2
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_MAX_BYTE 2048
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_MAX_STRIDE 1
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_NAME "/dev/from_ETH_to_DDR_ETH_DMA_descriptor_slave"
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_PACKET_ENABLE 1
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_PACKET_ENABLE_DERIVED 1
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_PREFETCHER_ENABLE 0
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_PROGRAMMABLE_BURST_ENABLE 0
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_RESPONSE_PORT 2
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_SPAN 16
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_STRIDE_ENABLE 0
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_STRIDE_ENABLE_DERIVED 0
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_TRANSFER_TYPE "Aligned Accesses"
#define FROM_ETH_TO_DDR_ETH_DMA_DESCRIPTOR_SLAVE_TYPE "altera_msgdma"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK SYS_TIMER
#define ALT_TIMESTAMP_CLK SYS_TIMER


/*
 * input_IO configuration
 *
 */

#define ALT_MODULE_CLASS_input_IO altera_avalon_pio
#define INPUT_IO_BASE 0x80101130
#define INPUT_IO_BIT_CLEARING_EDGE_REGISTER 1
#define INPUT_IO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define INPUT_IO_CAPTURE 1
#define INPUT_IO_DATA_WIDTH 8
#define INPUT_IO_DO_TEST_BENCH_WIRING 0
#define INPUT_IO_DRIVEN_SIM_VALUE 0
#define INPUT_IO_EDGE_TYPE "RISING"
#define INPUT_IO_FREQ 200000000
#define INPUT_IO_HAS_IN 1
#define INPUT_IO_HAS_OUT 0
#define INPUT_IO_HAS_TRI 0
#define INPUT_IO_IRQ -1
#define INPUT_IO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define INPUT_IO_IRQ_TYPE "NONE"
#define INPUT_IO_NAME "/dev/input_IO"
#define INPUT_IO_RESET_VALUE 0
#define INPUT_IO_SPAN 16
#define INPUT_IO_TYPE "altera_avalon_pio"


/*
 * input_IO_0 configuration
 *
 */

#define ALT_MODULE_CLASS_input_IO_0 altera_avalon_pio
#define INPUT_IO_0_BASE 0x80101120
#define INPUT_IO_0_BIT_CLEARING_EDGE_REGISTER 1
#define INPUT_IO_0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define INPUT_IO_0_CAPTURE 1
#define INPUT_IO_0_DATA_WIDTH 8
#define INPUT_IO_0_DO_TEST_BENCH_WIRING 0
#define INPUT_IO_0_DRIVEN_SIM_VALUE 0
#define INPUT_IO_0_EDGE_TYPE "RISING"
#define INPUT_IO_0_FREQ 200000000
#define INPUT_IO_0_HAS_IN 1
#define INPUT_IO_0_HAS_OUT 0
#define INPUT_IO_0_HAS_TRI 0
#define INPUT_IO_0_IRQ -1
#define INPUT_IO_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define INPUT_IO_0_IRQ_TYPE "NONE"
#define INPUT_IO_0_NAME "/dev/input_IO_0"
#define INPUT_IO_0_RESET_VALUE 0
#define INPUT_IO_0_SPAN 16
#define INPUT_IO_0_TYPE "altera_avalon_pio"


/*
 * input_IO_1 configuration
 *
 */

#define ALT_MODULE_CLASS_input_IO_1 altera_avalon_pio
#define INPUT_IO_1_BASE 0x80101110
#define INPUT_IO_1_BIT_CLEARING_EDGE_REGISTER 1
#define INPUT_IO_1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define INPUT_IO_1_CAPTURE 1
#define INPUT_IO_1_DATA_WIDTH 8
#define INPUT_IO_1_DO_TEST_BENCH_WIRING 0
#define INPUT_IO_1_DRIVEN_SIM_VALUE 0
#define INPUT_IO_1_EDGE_TYPE "RISING"
#define INPUT_IO_1_FREQ 200000000
#define INPUT_IO_1_HAS_IN 1
#define INPUT_IO_1_HAS_OUT 0
#define INPUT_IO_1_HAS_TRI 0
#define INPUT_IO_1_IRQ -1
#define INPUT_IO_1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define INPUT_IO_1_IRQ_TYPE "NONE"
#define INPUT_IO_1_NAME "/dev/input_IO_1"
#define INPUT_IO_1_RESET_VALUE 0
#define INPUT_IO_1_SPAN 16
#define INPUT_IO_1_TYPE "altera_avalon_pio"


/*
 * input_IO_2 configuration
 *
 */

#define ALT_MODULE_CLASS_input_IO_2 altera_avalon_pio
#define INPUT_IO_2_BASE 0x80101100
#define INPUT_IO_2_BIT_CLEARING_EDGE_REGISTER 1
#define INPUT_IO_2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define INPUT_IO_2_CAPTURE 1
#define INPUT_IO_2_DATA_WIDTH 8
#define INPUT_IO_2_DO_TEST_BENCH_WIRING 0
#define INPUT_IO_2_DRIVEN_SIM_VALUE 0
#define INPUT_IO_2_EDGE_TYPE "RISING"
#define INPUT_IO_2_FREQ 200000000
#define INPUT_IO_2_HAS_IN 1
#define INPUT_IO_2_HAS_OUT 0
#define INPUT_IO_2_HAS_TRI 0
#define INPUT_IO_2_IRQ -1
#define INPUT_IO_2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define INPUT_IO_2_IRQ_TYPE "NONE"
#define INPUT_IO_2_NAME "/dev/input_IO_2"
#define INPUT_IO_2_RESET_VALUE 0
#define INPUT_IO_2_SPAN 16
#define INPUT_IO_2_TYPE "altera_avalon_pio"


/*
 * input_IO_3 configuration
 *
 */

#define ALT_MODULE_CLASS_input_IO_3 altera_avalon_pio
#define INPUT_IO_3_BASE 0x801010f0
#define INPUT_IO_3_BIT_CLEARING_EDGE_REGISTER 1
#define INPUT_IO_3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define INPUT_IO_3_CAPTURE 1
#define INPUT_IO_3_DATA_WIDTH 8
#define INPUT_IO_3_DO_TEST_BENCH_WIRING 0
#define INPUT_IO_3_DRIVEN_SIM_VALUE 0
#define INPUT_IO_3_EDGE_TYPE "RISING"
#define INPUT_IO_3_FREQ 200000000
#define INPUT_IO_3_HAS_IN 1
#define INPUT_IO_3_HAS_OUT 0
#define INPUT_IO_3_HAS_TRI 0
#define INPUT_IO_3_IRQ -1
#define INPUT_IO_3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define INPUT_IO_3_IRQ_TYPE "NONE"
#define INPUT_IO_3_NAME "/dev/input_IO_3"
#define INPUT_IO_3_RESET_VALUE 0
#define INPUT_IO_3_SPAN 16
#define INPUT_IO_3_TYPE "altera_avalon_pio"


/*
 * input_IO_4 configuration
 *
 */

#define ALT_MODULE_CLASS_input_IO_4 altera_avalon_pio
#define INPUT_IO_4_BASE 0x801010e0
#define INPUT_IO_4_BIT_CLEARING_EDGE_REGISTER 1
#define INPUT_IO_4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define INPUT_IO_4_CAPTURE 1
#define INPUT_IO_4_DATA_WIDTH 8
#define INPUT_IO_4_DO_TEST_BENCH_WIRING 0
#define INPUT_IO_4_DRIVEN_SIM_VALUE 0
#define INPUT_IO_4_EDGE_TYPE "RISING"
#define INPUT_IO_4_FREQ 200000000
#define INPUT_IO_4_HAS_IN 1
#define INPUT_IO_4_HAS_OUT 0
#define INPUT_IO_4_HAS_TRI 0
#define INPUT_IO_4_IRQ -1
#define INPUT_IO_4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define INPUT_IO_4_IRQ_TYPE "NONE"
#define INPUT_IO_4_NAME "/dev/input_IO_4"
#define INPUT_IO_4_RESET_VALUE 0
#define INPUT_IO_4_SPAN 16
#define INPUT_IO_4_TYPE "altera_avalon_pio"


/*
 * jtag configuration
 *
 */

#define ALT_MODULE_CLASS_jtag altera_avalon_jtag_uart
#define JTAG_BASE 0x801011c0
#define JTAG_IRQ 6
#define JTAG_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_NAME "/dev/jtag"
#define JTAG_READ_DEPTH 64
#define JTAG_READ_THRESHOLD 8
#define JTAG_SPAN 8
#define JTAG_TYPE "altera_avalon_jtag_uart"
#define JTAG_WRITE_DEPTH 64
#define JTAG_WRITE_THRESHOLD 8


/*
 * pilot_sig configuration
 *
 */

#define ALT_MODULE_CLASS_pilot_sig altera_avalon_pio
#define PILOT_SIG_BASE 0x80101140
#define PILOT_SIG_BIT_CLEARING_EDGE_REGISTER 1
#define PILOT_SIG_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PILOT_SIG_CAPTURE 1
#define PILOT_SIG_DATA_WIDTH 8
#define PILOT_SIG_DO_TEST_BENCH_WIRING 0
#define PILOT_SIG_DRIVEN_SIM_VALUE 0
#define PILOT_SIG_EDGE_TYPE "RISING"
#define PILOT_SIG_FREQ 200000000
#define PILOT_SIG_HAS_IN 1
#define PILOT_SIG_HAS_OUT 0
#define PILOT_SIG_HAS_TRI 0
#define PILOT_SIG_IRQ 8
#define PILOT_SIG_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PILOT_SIG_IRQ_TYPE "EDGE"
#define PILOT_SIG_NAME "/dev/pilot_sig"
#define PILOT_SIG_RESET_VALUE 0
#define PILOT_SIG_SPAN 16
#define PILOT_SIG_TYPE "altera_avalon_pio"


/*
 * sys_timer configuration
 *
 */

#define ALT_MODULE_CLASS_sys_timer altera_avalon_timer
#define SYS_TIMER_ALWAYS_RUN 0
#define SYS_TIMER_BASE 0x80101000
#define SYS_TIMER_COUNTER_SIZE 32
#define SYS_TIMER_FIXED_PERIOD 0
#define SYS_TIMER_FREQ 200000000
#define SYS_TIMER_IRQ 7
#define SYS_TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SYS_TIMER_LOAD_VALUE 199999
#define SYS_TIMER_MULT 0.001
#define SYS_TIMER_NAME "/dev/sys_timer"
#define SYS_TIMER_PERIOD 1
#define SYS_TIMER_PERIOD_UNITS "ms"
#define SYS_TIMER_RESET_OUTPUT 0
#define SYS_TIMER_SNAPSHOT 1
#define SYS_TIMER_SPAN 32
#define SYS_TIMER_TICKS_PER_SEC 1000
#define SYS_TIMER_TIMEOUT_PULSE_OUTPUT 0
#define SYS_TIMER_TYPE "altera_avalon_timer"


/*
 * system_ram configuration
 *
 */

#define ALT_MODULE_CLASS_system_ram altera_avalon_onchip_memory2
#define SYSTEM_RAM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define SYSTEM_RAM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define SYSTEM_RAM_BASE 0x80080000
#define SYSTEM_RAM_CONTENTS_INFO ""
#define SYSTEM_RAM_DUAL_PORT 0
#define SYSTEM_RAM_GUI_RAM_BLOCK_TYPE "M9K"
#define SYSTEM_RAM_INIT_CONTENTS_FILE "testbench_ls_system_ram"
#define SYSTEM_RAM_INIT_MEM_CONTENT 1
#define SYSTEM_RAM_INSTANCE_ID "NONE"
#define SYSTEM_RAM_IRQ -1
#define SYSTEM_RAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSTEM_RAM_NAME "/dev/system_ram"
#define SYSTEM_RAM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define SYSTEM_RAM_RAM_BLOCK_TYPE "M9K"
#define SYSTEM_RAM_READ_DURING_WRITE_MODE "DONT_CARE"
#define SYSTEM_RAM_SINGLE_CLOCK_OP 0
#define SYSTEM_RAM_SIZE_MULTIPLE 1
#define SYSTEM_RAM_SIZE_VALUE 512000
#define SYSTEM_RAM_SPAN 512000
#define SYSTEM_RAM_TYPE "altera_avalon_onchip_memory2"
#define SYSTEM_RAM_WRITABLE 1

#endif /* __SYSTEM_H_ */
