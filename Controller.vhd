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

    datasend4          : in std_logic_vector(31 downto 0);
    primitiveFIFOempty4: in std_logic;
    txready4           : out std_logic;


    -- SGMII(0 to 3): Onboard ethernet links ---
    cETH_RST_n    : out std_logic;
    cETH_RX_p     : in std_logic_vector(0 to 3);
    cETH_TX_p     : out std_logic_vector(0 to 3);


    -- RGMII(0 to 1) : HSMC Port A -------------
    -- RGMII(2 to 3) : HSMC Port B -------------
    cENET_RST_n   : out std_logic_vector(0 to 3);
    cENET_TX_EN   : out std_logic_vector(0 to 3);
    cENET_TX_ER   : out std_logic_vector(0 to 3);
    cENET_GTX_CLK : out std_logic_vector(0 to 3);
    cENET_TX_D0   : out std_logic_vector(7 downto 0);
    cENET_TX_D1   : out std_logic_vector(7 downto 0);
    cENET_TX_D2   : out std_logic_vector(7 downto 0);
    cENET_TX_D3   : out std_logic_vector(7 downto 0);
    cENET_RX_DV   : in std_logic_vector(0 to 3);
    cENET_RX_ER   : in std_logic_vector(0 to 3);
    cENET_RX_CLK  : in std_logic_vector(0 to 3);
    cENET_RX_D0   : in std_logic_vector(7 downto 0);
    cENET_RX_D1   : in std_logic_vector(7 downto 0);
    cENET_RX_D2   : in std_logic_vector(7 downto 0);
    cENET_RX_D3   : in std_logic_vector(7 downto 0);
    

    macdata            : out std_logic_vector(63 downto 0);
    macreceived        : out std_logic;
    packetreceived     : out std_logic;
    detectorUnderInit  : out std_logic_vector(3 downto 0)
    );
end Controller;

architecture rtl of Controller is

  
begin



  ethlink_inst : ethlink port map
    (
      inputs.clkin_50   => clkin_50,
      inputs.clkin_125   => clkin_125,
      inputs.cpu_resetn => cpu_resetn,
      inputs.rxp        => cETH_RX_p(0 to SGMII_NODES - 1),

      inputs.enet_rx_clk   => cENET_RX_CLK(0 to RGMII_NODES - 1),
      inputs.enet_rx_dv    => cENET_RX_DV(0 to RGMII_NODES - 1),
      inputs.enet_rx_er    => cENET_RX_ER(0 to RGMII_NODES - 1),
      inputs.enet_rx_d(0)  => cENET_RX_D0,
      inputs.enet_rx_d(1)  => cENET_RX_D1,
      inputs.enet_rx_d(2)  => cENET_RX_D2,
      inputs.enet_rx_d(3)  => cENET_RX_D3,

      outputs.txp          => cETH_TX_p(0 to SGMII_NODES - 1),

      outputs.resetn       => cETH_RST_n,
      outputs.enet_resetn  => cENET_RST_n(0 to RGMII_NODES - 1),
      outputs.enet_gtx_clk => cENET_GTX_CLK(0 to RGMII_NODES - 1),
      outputs.enet_tx_en   => cENET_TX_EN(0 to RGMII_NODES - 1),
      outputs.enet_tx_er   => cENET_TX_ER(0 to RGMII_NODES - 1),
      outputs.enet_tx_d(0)  => cENET_TX_D0,
      outputs.enet_tx_d(1)  => cENET_TX_D1,
      outputs.enet_tx_d(2)  => cENET_TX_D2,
      outputs.enet_tx_d(3)  => cENET_TX_D3,
      
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

      inputs.datasend4 => datasend4,   
      outputs.txready4 => txready4,
      inputs.primitiveFIFOempty4 => primitiveFIFOempty4,

      inputs.datasend5 => (others =>'0'),   
      inputs.primitiveFIFOempty5 => '0',
      --outputs.txready5 => 
      
		outputs.macdata           => macdata,
      outputs.macreceived       => macreceived,
      outputs.packetreceived    => packetreceived,
      outputs.detectorUnderInit => detectorUnderInit
      );


  
end rtl;
