-- megafunction wizard: %ALTIOBUF%
-- GENERATION: STANDARD
-- VERSION: WM1.0
-- MODULE: altiobuf_bidir 

-- ============================================================
-- File Name: altiobuf1.vhd
-- Megafunction Name(s):
-- 			altiobuf_bidir
--
-- Simulation Library Files(s):
-- 			stratixiii
-- ============================================================
-- ************************************************************
-- THIS IS A WIZARD-GENERATED FILE. DO NOT EDIT THIS FILE!
--
-- 8.1 Build 163 10/28/2008 SJ Full Version
-- ************************************************************


--Copyright (C) 1991-2008 Altera Corporation
--Your use of Altera Corporation's design tools, logic functions 
--and other software and tools, and its AMPP partner logic 
--functions, and any output files from any of the foregoing 
--(including device programming or simulation files), and any 
--associated documentation or information are expressly subject 
--to the terms and conditions of the Altera Program License 
--Subscription Agreement, Altera MegaCore Function License 
--Agreement, or other applicable license agreement, including, 
--without limitation, that your use is for the sole purpose of 
--programming logic devices manufactured by Altera and sold by 
--Altera or its authorized distributors.  Please refer to the 
--applicable agreement for further details.


--altiobuf_bidir CBX_AUTO_BLACKBOX="ALL" DEVICE_FAMILY="Stratix III" ENABLE_BUS_HOLD="FALSE" NUMBER_OF_CHANNELS=1 OPEN_DRAIN_OUTPUT="TRUE" USE_DIFFERENTIAL_MODE="FALSE" USE_DYNAMIC_TERMINATION_CONTROL="FALSE" USE_TERMINATION_CONTROL="FALSE" datain dataio dataout oe
--VERSION_BEGIN 8.1 cbx_altiobuf_bidir 2008:08:04:11:33:09:SJ cbx_mgl 2008:08:08:15:16:18:SJ cbx_stratixiii 2008:07:11:13:32:02:SJ  VERSION_END

 LIBRARY stratixiii;
 USE stratixiii.all;

--synthesis_resources = stratixiii_io_ibuf 1 stratixiii_io_obuf 1 
 LIBRARY ieee;
 USE ieee.std_logic_1164.all;

 ENTITY  altiobuf1_iobuf_bidir_hto IS 
	 PORT 
	 ( 
		 datain	:	IN  STD_LOGIC_VECTOR (0 DOWNTO 0);
		 dataio	:	INOUT  STD_LOGIC_VECTOR (0 DOWNTO 0);
		 dataout	:	OUT  STD_LOGIC_VECTOR (0 DOWNTO 0);
		 oe	:	IN  STD_LOGIC_VECTOR (0 DOWNTO 0)
	 ); 
 END altiobuf1_iobuf_bidir_hto;

 ARCHITECTURE RTL OF altiobuf1_iobuf_bidir_hto IS

	 SIGNAL  wire_ibufa_o	:	STD_LOGIC;
	 SIGNAL  wire_obufa_o	:	STD_LOGIC;
	 COMPONENT  stratixiii_io_ibuf
	 GENERIC 
	 (
		bus_hold	:	STRING := "false";
		differential_mode	:	STRING := "false";
		lpm_type	:	STRING := "stratixiii_io_ibuf"
	 );
	 PORT
	 ( 
		i	:	IN STD_LOGIC := '0';
		ibar	:	IN STD_LOGIC := '0';
		o	:	OUT STD_LOGIC
	 ); 
	 END COMPONENT;
	 COMPONENT  stratixiii_io_obuf
	 GENERIC 
	 (
		bus_hold	:	STRING := "false";
		open_drain_output	:	STRING := "false";
		shift_series_termination_control	:	STRING := "false";
		sim_dynamic_termination_control_is_connected	:	STRING := "false";
		lpm_type	:	STRING := "stratixiii_io_obuf"
	 );
	 PORT
	 ( 
		dynamicterminationcontrol	:	IN STD_LOGIC := '0';
		i	:	IN STD_LOGIC := '0';
		o	:	OUT STD_LOGIC;
		obar	:	OUT STD_LOGIC;
		oe	:	IN STD_LOGIC := '1';
		parallelterminationcontrol	:	IN STD_LOGIC_VECTOR(13 DOWNTO 0) := (OTHERS => '0');
		seriesterminationcontrol	:	IN STD_LOGIC_VECTOR(13 DOWNTO 0) := (OTHERS => '0')
	 ); 
	 END COMPONENT;
 BEGIN

	dataio(0) <= wire_obufa_o;
	dataout(0) <= wire_ibufa_o;
	ibufa :  stratixiii_io_ibuf
	  GENERIC MAP (
		bus_hold => "false"
	  )
	  PORT MAP ( 
		i => dataio(0),
		o => wire_ibufa_o
	  );
	obufa :  stratixiii_io_obuf
	  GENERIC MAP (
		bus_hold => "false",
		open_drain_output => "true"
	  )
	  PORT MAP ( 
		i => datain(0),
		o => wire_obufa_o,
		oe => oe(0)
	  );

 END RTL; --altiobuf1_iobuf_bidir_hto
--VALID FILE


LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY altiobuf1 IS
	PORT
	(
		datain		: IN STD_LOGIC_VECTOR (0 DOWNTO 0);
		oe		: IN STD_LOGIC_VECTOR (0 DOWNTO 0);
		dataio		: INOUT STD_LOGIC_VECTOR (0 DOWNTO 0);
		dataout		: OUT STD_LOGIC_VECTOR (0 DOWNTO 0)
	);
END altiobuf1;


ARCHITECTURE RTL OF altiobuf1 IS

	SIGNAL sub_wire0	: STD_LOGIC_VECTOR (0 DOWNTO 0);



	COMPONENT altiobuf1_iobuf_bidir_hto
	PORT (
			dataout	: OUT STD_LOGIC_VECTOR (0 DOWNTO 0);
			datain	: IN STD_LOGIC_VECTOR (0 DOWNTO 0);
			dataio	: INOUT STD_LOGIC_VECTOR (0 DOWNTO 0);
			oe	: IN STD_LOGIC_VECTOR (0 DOWNTO 0)
	);
	END COMPONENT;

BEGIN
	dataout    <= sub_wire0(0 DOWNTO 0);

	altiobuf1_iobuf_bidir_hto_component : altiobuf1_iobuf_bidir_hto
	PORT MAP (
		datain => datain,
		oe => oe,
		dataout => sub_wire0,
		dataio => dataio
	);



END RTL;

-- ============================================================
-- CNX file retrieval info
-- ============================================================
-- Retrieval info: PRIVATE: INTENDED_DEVICE_FAMILY STRING "Stratix III"
-- Retrieval info: PRIVATE: SYNTH_WRAPPER_GEN_POSTFIX STRING "0"
-- Retrieval info: LIBRARY: altera_mf altera_mf.altera_mf_components.all
-- Retrieval info: CONSTANT: INTENDED_DEVICE_FAMILY STRING "Stratix III"
-- Retrieval info: CONSTANT: enable_bus_hold STRING "FALSE"
-- Retrieval info: CONSTANT: number_of_channels NUMERIC "1"
-- Retrieval info: CONSTANT: open_drain_output STRING "TRUE"
-- Retrieval info: CONSTANT: use_differential_mode STRING "FALSE"
-- Retrieval info: CONSTANT: use_dynamic_termination_control STRING "FALSE"
-- Retrieval info: CONSTANT: use_termination_control STRING "FALSE"
-- Retrieval info: USED_PORT: datain 0 0 1 0 INPUT NODEFVAL "datain[0..0]"
-- Retrieval info: USED_PORT: dataio 0 0 1 0 BIDIR NODEFVAL "dataio[0..0]"
-- Retrieval info: USED_PORT: dataout 0 0 1 0 OUTPUT NODEFVAL "dataout[0..0]"
-- Retrieval info: USED_PORT: oe 0 0 1 0 INPUT NODEFVAL "oe[0..0]"
-- Retrieval info: CONNECT: @datain 0 0 1 0 datain 0 0 1 0
-- Retrieval info: CONNECT: @oe 0 0 1 0 oe 0 0 1 0
-- Retrieval info: CONNECT: dataout 0 0 1 0 @dataout 0 0 1 0
-- Retrieval info: CONNECT: dataio 0 0 1 0 @dataio 0 0 1 0
-- Retrieval info: GEN_FILE: TYPE_NORMAL altiobuf1.vhd TRUE FALSE
-- Retrieval info: GEN_FILE: TYPE_NORMAL altiobuf1.inc FALSE FALSE
-- Retrieval info: GEN_FILE: TYPE_NORMAL altiobuf1.cmp TRUE FALSE
-- Retrieval info: GEN_FILE: TYPE_NORMAL altiobuf1.bsf TRUE FALSE
-- Retrieval info: GEN_FILE: TYPE_NORMAL altiobuf1_inst.vhd TRUE FALSE
-- Retrieval info: LIB_FILE: stratixiii
