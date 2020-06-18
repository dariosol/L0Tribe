library ieee;
use ieee.std_logic_1164.all;
use IEEE.NUMERIC_BIT.all;
use work.userlib.all;
use work.component_ethlink.all;


entity Controller is
  port (
    clkin_50           : in std_logic;
    clkin_125          : in std_logic;
    cpu_resetn         : in std_logic; 
    enet_rxp           : in std_logic_vector(0 to ethlink_NODES -1);
    mdio_sin           : in std_logic_vector(0 to ethlink_NODES -1);
    USER_DIPSW         : in std_logic_vector(7 downto 0);  
    startdata          : in  std_logic;

    datasend0          : in std_logic_vector(31 downto 0);
    primitiveFIFOempty0: in std_logic;
    txready0           : out std_logic;		

    datasend1          : in std_logic_vector(31 downto 0);
    primitiveFIFOempty1: in std_logic;
    txready1           : out std_logic;		

    datasend2          : in std_logic_vector(31 downto 0);
    primitiveFIFOempty2: in std_logic;
    txready2           : out std_logic;		


    datasend3          : in std_logic_vector(31 downto 0);
    primitiveFIFOempty3: in std_logic;
    txready3           : out std_logic;		

    
    ETH_MDIO   	       : inout  std_logic_vector(0 to ethlink_NODES - 1) ;

    enet_resetn        : out std_logic;
    enet_txp           : out std_logic_vector(0 to ethlink_NODES -1);
    enet_mdc           : out std_logic_vector(0 to ethlink_NODES - 1);   
    mdio_sout          : out std_logic_vector(0 to ethlink_NODES - 1); 
    mdio_sena          : out std_logic_vector(0 to ethlink_NODES - 1);
    macdata            : out std_logic_vector(63 downto 0);
    macreceived        : out std_logic;
    packetreceived     : out std_logic;
    detectorUnderInit  : out std_logic_vector(3 downto 0)
    );
end Controller;

architecture rtl of Controller is

  component altiobuf1
    port
      (
        datain  : in    std_logic_vector (0 downto 0);
        oe      : in    std_logic_vector (0 downto 0);
        dataio  : inout std_logic_vector (0 downto 0);
        dataout : out   std_logic_vector (0 downto 0)
        );
  end component;

------------------------------------------------
  signal s_mdio_sin          : std_logic_vector(0 to 3);
  signal s_mdio_sena         : std_logic_vector(0 to 3);
  signal s_mdio_sout         : std_logic_vector(0 to 3);
-------------------------------------------------
 

  
begin



  ethlink_inst : ethlink port map
    (
      inputs.clkin_50   => clkin_50,
      inputs.clkin_125   => clkin_125,
      inputs.cpu_resetn => cpu_resetn,
      inputs.enet_rxp   => enet_rxp,
      inputs.mdio_sin   => s_mdio_sin,
      inputs.USER_DIPSW => USER_DIPSW,
      inputs.startdata  => startdata,

      inputs.datasend0 => datasend0,   
      outputs.txready0 => txready0,
      inputs.primitiveFIFOempty0 => primitiveFIFOempty0,

      inputs.datasend1 => datasend1,   
      outputs.txready1 => txready1,
      inputs.primitiveFIFOempty1 => primitiveFIFOempty1,

      inputs.datasend2 => datasend2,   
      outputs.txready2 => txready2,
      inputs.primitiveFIFOempty2 => primitiveFIFOempty2,


      inputs.datasend3 => datasend3,   
      outputs.txready3 => txready3,
      inputs.primitiveFIFOempty3 => primitiveFIFOempty3,

      outputs.enet_resetn       => enet_resetn,
      outputs.enet_txp          => enet_txp,
      outputs.enet_mdc          => enet_mdc,
      outputs.mdio_sout         => s_mdio_sout,
      outputs.mdio_sena         => s_mdio_sena,
      outputs.macdata           => macdata,
      outputs.macreceived       => macreceived,
      outputs.packetreceived    => packetreceived,
      outputs.detectorUnderInit => detectorUnderInit
      );


  IOBUF : for index in 0 to ethlink_NODES-1 generate
    IOBUF : altiobuf1 port map
      (
        datain(0)  => s_mdio_sout(index),
        oe(0)      => s_mdio_sena(index),
        dataout(0) => s_mdio_sin(index),
        dataio(0)  => ETH_MDIO(index)
        );
  end generate;
  
end rtl;
