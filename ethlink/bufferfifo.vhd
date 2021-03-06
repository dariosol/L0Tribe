--**************************************************************
--**************************************************************
--
-- Template file: compmap1.rec (Std --> RecType)
--
--**************************************************************
--**************************************************************
--
--
-- Component bufferfifo  
--
--
--
--
--
--
-- Notes:
--
-- (edit)     --> custom description (component edit)
-- (constant) --> common description (do not modify)
--
--**************************************************************
--**************************************************************

--**************************************************************
--
--
-- Component Interface
--
--
--**************************************************************

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

package component_bufferfifo is

--**************************************************************
--
-- I/O section begin 
--
--**************************************************************

--
-- bufferfifo inputs (constant)
--
type bufferfifo_inputs_t is record

   -- input list
   aclr  : STD_LOGIC;
   data  : STD_LOGIC_VECTOR (31 DOWNTO 0);
   clk   : STD_LOGIC;
   rdreq : STD_LOGIC;
   wrreq : STD_LOGIC;

end record;

--
-- bufferfifo outputs (constant)
--
type bufferfifo_outputs_t is record

   -- output list
   q : STD_LOGIC_VECTOR (31 DOWNTO 0);
   empty : STD_LOGIC;
   full : STD_LOGIC;
   usedw : STD_LOGIC_VECTOR (8 DOWNTO 0);

end record;

--**************************************************************
--
-- I/O section end
--
--**************************************************************

--**************************************************************
--**************************************************************

--
-- bufferfifo component common interface (constant)
--
type bufferfifo_t is record
   inputs : bufferfifo_inputs_t;
   outputs : bufferfifo_outputs_t;
end record;

--
-- bufferfifo vector type (constant)
--
type bufferfifo_vector_t is array(NATURAL RANGE <>) of bufferfifo_t;

--
-- bufferfifo component declaration (constant)
--
component bufferfifo
port (
   inputs : in bufferfifo_inputs_t;
   outputs : out bufferfifo_outputs_t
);
end component;

--
-- bufferfifo global signal to export range/width params (constant)
--
signal component_bufferfifo : bufferfifo_t;

end component_bufferfifo;

--
-- bufferfifo entity declaration
--

-- Local libraries (edit)
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.userlib.all;
use work.component_bufferfifo.all;

-- bufferfifo entity (constant)
entity bufferfifo is
port (
   inputs : in bufferfifo_inputs_t;
   outputs : out bufferfifo_outputs_t
);
end bufferfifo;

--**************************************************************
--**************************************************************

--**************************************************************
--
-- Component Architecture
--
--**************************************************************

architecture rtl of bufferfifo is

--
-- altbufferfifo component declaration (constant)
--
component altbufferfifo
port
(
   aclr  : in STD_LOGIC  := '0';
   data  : in STD_LOGIC_VECTOR (31 DOWNTO 0);
   clock : in STD_LOGIC;
   rdreq : in STD_LOGIC;
   wrreq : in STD_LOGIC;
   q     : out STD_LOGIC_VECTOR (31 DOWNTO 0);
   full  : out STD_LOGIC;
   usedw : out STD_LOGIC_VECTOR (8 DOWNTO 0);
   empty : out STD_LOGIC
);
end component;

begin

--
-- component port map (constant)
--
altbufferfifo_inst : altbufferfifo port map
(
   aclr => inputs.aclr,
   data => inputs.data,
   clock => inputs.clk,
   rdreq => inputs.rdreq,
   wrreq => inputs.wrreq,
   q => outputs.q,
   empty => outputs.empty,
   full => outputs.full,
   usedw => outputs.usedw
   );

end rtl;
