library ieee;
use ieee.std_logic_1164.all;
--use ieee.numeric_std.all;
use IEEE.NUMERIC_BIT.all;
use work.globals.all;
use work.userlib.all;

entity altPrimitiveSerializer is
   port (aclr             : in std_logic; 
         clk              : in std_logic;
	 datain           : in std_logic_vector(255 downto 0);
         rdreq            : in std_logic;
	 dataout          : out std_logic_vector(31 downto 0);
         readfromfifo     : out std_logic
	 );

end altPrimitiveSerializer;

architecture rtl of altPrimitiveSerializer is

  type FSMSerialization_t is (Idle,Chokestate,Dead_time0,Dead_time1,Dead_time2,Dead_time3);
  signal FSMSerialization : FSMSerialization_t;

  signal s_datain  : std_logic_vector(256 downto 0);
  signal s_databuffer : std_logic_vector(31 downto 0);

begin

   s_datain <= datain;
   dataout  <= s_databuffer;
   
	
	
process(clk, aclr) is
 begin
    if(aclr = '1') then
	 s_databuffer <= (others=>'0');
         readfromfifo <= '0';
         
    elsif (clk='1' and clk'event)  then


    end if;
 end process;
--
--
-- process(clk40, reset) is
-- begin
--    if(rising_edge(clk40)) then
--       if(reset = '1') then
--          ERROR_s1 <= (others=>'0');
--          ERROR_s2 <= (others=>'0');
--       else
--          ERROR_s1 <= s_ERROR;
--          ERROR_s2 <= ERROR_s1;
--       end if;
--    end if;
-- end process;
--

   P1: PROCESS(clk40,s_ECRST,s_BCRST,startRUN)
   begin
       if(clk40='1' and clk40'event)  then
	 if startRUN ='1' then --FROM USB
	    if(s_ECRST='1' and s_BCRST='1')then --SOB
	       s_BURST<='1';
	    elsif (s_BCRST='0' and s_ECRST='1')  then --EOB
	       s_BURST <='0';
	    else
	       s_BURST <= s_BURST;
	    end if;	
	 else
	    s_BURST<='0';
	 end if;
     end if;	
   end PROCESS;

 PError: PROCESS(clk40,s_ECRST,s_BCRST)
 begin
   if(clk40='1' and clk40'event)  then
     if (s_ECRST='1' and s_BCRST='1' and s_BURST = '1')  then --sob without eob
       s_BURSTERROR <= "100000";
     elsif (s_ECRST='1' and s_BCRST='1' and s_BURST = '0')  then --good sob
       s_BURSTERROR <= "000000";
     else
       s_BURSTERROR  <=s_BURSTERROR;
     end if;
    end if;      
   end PROCESS;


 

 
   CHOKE_P: PROCESS(reset,clk40,CHOKE_s2,s_FAKECHOKE)
   begin
      if reset ='1' then 
	 
	 FSMChoke <= Idle;

      elsif rising_edge(clk40) then
	 
	 case FSMChoke is
	    
	    when idle =>
	       if activateCHOKE ='1' then --FROM USB
		  if (CHOKE_s2 or s_FAKECHOKE) = "00000000000000"   then
		     FSMChoke <= Idle;
		  else
		     FSMChoke <= Chokestate;
		  end if;
	       else
		  FSMChoke <= Idle;
	       end if;
	       
	    when Chokestate =>
	       if activateCHOKE ='1' then --FROM USB
		  if (CHOKE_s2 or s_FAKECHOKE) = "00000000000000"  then
		     FSMChoke <= Dead_time0;
		  else
		     FSMChoke <= Chokestate;
		  end if;
	       else
		  FSMChoke <= Idle;
	       end if;

	    when Dead_time0 =>
	       
	       if activateCHOKE ='1' then --FROM USB
		  if (CHOKE_s2 or s_FAKECHOKE) = "00000000000000"  then
		     FSMChoke <= Dead_time1;
		  else
		     FSMChoke <= Chokestate;
		  end if;
	       else
		  FSMChoke <= Idle;
	       end if;
	       
	    when Dead_time1 =>
	      if activateCHOKE ='1' then --FROM USB
	        if (CHOKE_s2 or s_FAKECHOKE) = "00000000000000"  then
		     FSMChoke <= Dead_time2;
		  else
		     FSMChoke <= Chokestate;
		  end if;
	       else
		  FSMChoke <= Idle;
	       end if;

         when Dead_time2 =>
           if activateCHOKE ='1' then --FROM USB
	        if (CHOKE_s2 or s_FAKECHOKE) = "00000000000000"  then
		     FSMChoke <= Dead_time3;
		else
		     FSMChoke <= Chokestate;
	       end if;

	    else
                FSMChoke <= Idle;
	    end if;

	 when Dead_time3 =>
           if activateCHOKE ='1' then --FROM USB
	        if (CHOKE_s2 or s_FAKECHOKE) = "00000000000000"  then
		   FSMChoke <= Idle;
		  else
		     FSMChoke <= Chokestate;
		  end if;
	       else
		  FSMChoke <= Idle;
	       end if;
	 end case;
      end if;
   end PROCESS;

-- Output depends on the current state
   process (FSMChoke)
   begin
      s_CHOKE_ON  <='0';
      s_CHOKE_OFF <='1';
      case FSMChoke is
	 when idle =>
	    s_CHOKE_ON  <='0';
	    s_CHOKE_OFF <='1';
	 when Chokestate =>
	    s_CHOKE_ON  <='1';
	    s_CHOKE_OFF <='0';
	 when Dead_time0 =>
	    s_CHOKE_ON  <='1';
	    s_CHOKE_OFF <='0';
	 when Dead_time1 =>
	    s_CHOKE_ON  <='1';
	    s_CHOKE_OFF <='0';
	 when Dead_time2 =>
	    s_CHOKE_ON  <='1';
	    s_CHOKE_OFF <='0';
	 when Dead_time3 =>
	    s_CHOKE_ON  <='1';
	    s_CHOKE_OFF <='0';
      end case;
   end process;

   ERROR_P: PROCESS(reset,clk40,ERROR_s2, s_FAKEERROR)
   begin
      if reset ='1' then 
	 
	 FSMERROR <= Idle;

      elsif rising_edge(clk40) then
	 
	 case FSMERROR is
	    
	    when idle =>
	       if activateERROR ='1' then --FROM USB
		  if (ERROR_s2 or s_FAKEERROR) = "00000000000000"  then
		     FSMERROR <= Idle;
		  else
		     FSMERROR <= ERRORstate;
		  end if;
	       else
		  FSMERROR <= Idle;
	       end if;
	       
	    when ERRORstate =>
	       if activateERROR ='1' then --FROM USB
		  if (ERROR_s2 or s_FAKEERROR) = "00000000000000" then
		     FSMERROR <= Dead_time0;
		  else
		     FSMERROR <= ERRORstate;
		  end if;
	       else
		  FSMERROR <= Idle;
	       end if;
	       
	    when Dead_time0 =>
	       
	       FSMERROR <= Dead_time1;
	       
	    when Dead_time1 =>
	       
	       FSMERROR <= Idle;
	       
	 end case;
      end if;
   end PROCESS;

-- Output depends on the current state
   process (FSMERROR)
   begin
      s_ERROR_ON  <='0';
      s_ERROR_OFF <='1';
      case FSMERROR is
	 when idle =>
	    s_ERROR_ON  <='0';
	    s_ERROR_OFF <='1';
	 when ERRORstate =>
	    s_ERROR_ON  <='1';
	    s_ERROR_OFF <='0';
	 when Dead_time0 =>
	    s_ERROR_ON  <='1';
	    s_ERROR_OFF <='0';
	 when Dead_time1 =>
	    s_ERROR_ON  <='1';
	    s_ERROR_OFF <='0';
      end case;
   end process;



 ERROR_ON       <= s_ERROR_ON   ;
 ERROR_OFF      <= s_ERROR_OFF  ;
 CHOKE_ON       <= s_CHOKE_ON   ;
 CHOKE_OFF      <= s_CHOKE_OFF  ;
 BURST    	<= s_BURST      ;
 BURSTERROR     <= s_BURSTERROR ;
 Led1           <= s_BURST      ;
 Led3           <= not(s_BURST) ; --Led of EOB
 CHOKE_signal   <= CHOKE_s2     ;
 ERROR_signal   <= ERROR_s2     ;



END RTL;
