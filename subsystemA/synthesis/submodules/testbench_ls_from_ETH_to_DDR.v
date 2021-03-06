// testbench_ls_from_ETH_to_DDR.v

// Generated using ACDS version 18.1 646

`timescale 1 ps / 1 ps
module testbench_ls_from_ETH_to_DDR (
		input  wire [31:0]  ETH_DMA_csr_writedata,                //              ETH_DMA_csr.writedata
		input  wire         ETH_DMA_csr_write,                    //                         .write
		input  wire [3:0]   ETH_DMA_csr_byteenable,               //                         .byteenable
		output wire [31:0]  ETH_DMA_csr_readdata,                 //                         .readdata
		input  wire         ETH_DMA_csr_read,                     //                         .read
		input  wire [2:0]   ETH_DMA_csr_address,                  //                         .address
		output wire         ETH_DMA_csr_irq_irq,                  //          ETH_DMA_csr_irq.irq
		input  wire         ETH_DMA_descriptor_slave_write,       // ETH_DMA_descriptor_slave.write
		output wire         ETH_DMA_descriptor_slave_waitrequest, //                         .waitrequest
		input  wire [127:0] ETH_DMA_descriptor_slave_writedata,   //                         .writedata
		input  wire [15:0]  ETH_DMA_descriptor_slave_byteenable,  //                         .byteenable
		output wire [30:0]  ETH_DMA_mm_write_address,             //         ETH_DMA_mm_write.address
		output wire         ETH_DMA_mm_write_write,               //                         .write
		output wire [31:0]  ETH_DMA_mm_write_byteenable,          //                         .byteenable
		output wire [255:0] ETH_DMA_mm_write_writedata,           //                         .writedata
		input  wire         ETH_DMA_mm_write_waitrequest,         //                         .waitrequest
		input  wire         clk_clk,                              //                      clk.clk
		input  wire [63:0]  eth_fifo_tofifo_fifo_data,            //          eth_fifo_tofifo.fifo_data
		output wire         eth_fifo_tofifo_fifo_read,            //                         .fifo_read
		input  wire         eth_fifo_tofifo_fifo_empty,           //                         .fifo_empty
		input  wire         eth_fifo_tofifo_fifo_full,            //                         .fifo_full
		input  wire         reset_reset_n                         //                    reset.reset_n
	);

	wire          data_format_adapter_0_out_valid;                // data_format_adapter_0:out_valid -> ETH_DMA:st_sink_valid
	wire  [255:0] data_format_adapter_0_out_data;                 // data_format_adapter_0:out_data -> ETH_DMA:st_sink_data
	wire          data_format_adapter_0_out_ready;                // ETH_DMA:st_sink_ready -> data_format_adapter_0:out_ready
	wire          data_format_adapter_0_out_startofpacket;        // data_format_adapter_0:out_startofpacket -> ETH_DMA:st_sink_startofpacket
	wire          data_format_adapter_0_out_endofpacket;          // data_format_adapter_0:out_endofpacket -> ETH_DMA:st_sink_endofpacket
	wire    [4:0] data_format_adapter_0_out_empty;                // data_format_adapter_0:out_empty -> ETH_DMA:st_sink_empty
	wire          eth_fifo_avalon_streaming_source_valid;         // eth_fifo:asi_valid -> avalon_st_adapter:in_0_valid
	wire   [63:0] eth_fifo_avalon_streaming_source_data;          // eth_fifo:asi_data -> avalon_st_adapter:in_0_data
	wire          eth_fifo_avalon_streaming_source_ready;         // avalon_st_adapter:in_0_ready -> eth_fifo:asi_ready
	wire          eth_fifo_avalon_streaming_source_startofpacket; // eth_fifo:asi_startofpacket -> avalon_st_adapter:in_0_startofpacket
	wire          eth_fifo_avalon_streaming_source_endofpacket;   // eth_fifo:asi_endofpacket -> avalon_st_adapter:in_0_endofpacket
	wire          avalon_st_adapter_out_0_valid;                  // avalon_st_adapter:out_0_valid -> data_format_adapter_0:in_valid
	wire   [63:0] avalon_st_adapter_out_0_data;                   // avalon_st_adapter:out_0_data -> data_format_adapter_0:in_data
	wire          avalon_st_adapter_out_0_ready;                  // data_format_adapter_0:in_ready -> avalon_st_adapter:out_0_ready
	wire          avalon_st_adapter_out_0_startofpacket;          // avalon_st_adapter:out_0_startofpacket -> data_format_adapter_0:in_startofpacket
	wire          avalon_st_adapter_out_0_endofpacket;            // avalon_st_adapter:out_0_endofpacket -> data_format_adapter_0:in_endofpacket
	wire    [2:0] avalon_st_adapter_out_0_empty;                  // avalon_st_adapter:out_0_empty -> data_format_adapter_0:in_empty
	wire          rst_controller_reset_out_reset;                 // rst_controller:reset_out -> [ETH_DMA:reset_n_reset_n, avalon_st_adapter:in_rst_0_reset, data_format_adapter_0:reset_n, eth_fifo:rsi_reset_n]

	testbench_ls_from_ETH_to_DDR_ETH_DMA eth_dma (
		.mm_write_address             (ETH_DMA_mm_write_address),                //         mm_write.address
		.mm_write_write               (ETH_DMA_mm_write_write),                  //                 .write
		.mm_write_byteenable          (ETH_DMA_mm_write_byteenable),             //                 .byteenable
		.mm_write_writedata           (ETH_DMA_mm_write_writedata),              //                 .writedata
		.mm_write_waitrequest         (ETH_DMA_mm_write_waitrequest),            //                 .waitrequest
		.clock_clk                    (clk_clk),                                 //            clock.clk
		.reset_n_reset_n              (~rst_controller_reset_out_reset),         //          reset_n.reset_n
		.csr_writedata                (ETH_DMA_csr_writedata),                   //              csr.writedata
		.csr_write                    (ETH_DMA_csr_write),                       //                 .write
		.csr_byteenable               (ETH_DMA_csr_byteenable),                  //                 .byteenable
		.csr_readdata                 (ETH_DMA_csr_readdata),                    //                 .readdata
		.csr_read                     (ETH_DMA_csr_read),                        //                 .read
		.csr_address                  (ETH_DMA_csr_address),                     //                 .address
		.descriptor_slave_write       (ETH_DMA_descriptor_slave_write),          // descriptor_slave.write
		.descriptor_slave_waitrequest (ETH_DMA_descriptor_slave_waitrequest),    //                 .waitrequest
		.descriptor_slave_writedata   (ETH_DMA_descriptor_slave_writedata),      //                 .writedata
		.descriptor_slave_byteenable  (ETH_DMA_descriptor_slave_byteenable),     //                 .byteenable
		.csr_irq_irq                  (ETH_DMA_csr_irq_irq),                     //          csr_irq.irq
		.st_sink_data                 (data_format_adapter_0_out_data),          //          st_sink.data
		.st_sink_valid                (data_format_adapter_0_out_valid),         //                 .valid
		.st_sink_ready                (data_format_adapter_0_out_ready),         //                 .ready
		.st_sink_startofpacket        (data_format_adapter_0_out_startofpacket), //                 .startofpacket
		.st_sink_endofpacket          (data_format_adapter_0_out_endofpacket),   //                 .endofpacket
		.st_sink_empty                (data_format_adapter_0_out_empty)          //                 .empty
	);

	testbench_ls_from_ETH_to_DDR_data_format_adapter_0 data_format_adapter_0 (
		.clk               (clk_clk),                                 //   clk.clk
		.reset_n           (~rst_controller_reset_out_reset),         // reset.reset_n
		.in_data           (avalon_st_adapter_out_0_data),            //    in.data
		.in_valid          (avalon_st_adapter_out_0_valid),           //      .valid
		.in_ready          (avalon_st_adapter_out_0_ready),           //      .ready
		.in_startofpacket  (avalon_st_adapter_out_0_startofpacket),   //      .startofpacket
		.in_endofpacket    (avalon_st_adapter_out_0_endofpacket),     //      .endofpacket
		.in_empty          (avalon_st_adapter_out_0_empty),           //      .empty
		.out_data          (data_format_adapter_0_out_data),          //   out.data
		.out_valid         (data_format_adapter_0_out_valid),         //      .valid
		.out_ready         (data_format_adapter_0_out_ready),         //      .ready
		.out_startofpacket (data_format_adapter_0_out_startofpacket), //      .startofpacket
		.out_endofpacket   (data_format_adapter_0_out_endofpacket),   //      .endofpacket
		.out_empty         (data_format_adapter_0_out_empty)          //      .empty
	);

	ethFifo eth_fifo (
		.csi_clk           (clk_clk),                                        //                   clock.clk
		.rsi_reset_n       (~rst_controller_reset_out_reset),                //                   reset.reset_n
		.fifo_data         (eth_fifo_tofifo_fifo_data),                      //                  toFifo.fifo_data
		.fifo_read         (eth_fifo_tofifo_fifo_read),                      //                        .fifo_read
		.fifo_empty        (eth_fifo_tofifo_fifo_empty),                     //                        .fifo_empty
		.fifo_full         (eth_fifo_tofifo_fifo_full),                      //                        .fifo_full
		.asi_ready         (eth_fifo_avalon_streaming_source_ready),         // avalon_streaming_source.ready
		.asi_valid         (eth_fifo_avalon_streaming_source_valid),         //                        .valid
		.asi_data          (eth_fifo_avalon_streaming_source_data),          //                        .data
		.asi_startofpacket (eth_fifo_avalon_streaming_source_startofpacket), //                        .startofpacket
		.asi_endofpacket   (eth_fifo_avalon_streaming_source_endofpacket)    //                        .endofpacket
	);

	testbench_ls_from_ETH_to_DDR_avalon_st_adapter #(
		.inBitsPerSymbol (8),
		.inUsePackets    (1),
		.inDataWidth     (64),
		.inChannelWidth  (0),
		.inErrorWidth    (0),
		.inUseEmptyPort  (0),
		.inUseValid      (1),
		.inUseReady      (1),
		.inReadyLatency  (0),
		.outDataWidth    (64),
		.outChannelWidth (0),
		.outErrorWidth   (0),
		.outUseEmptyPort (1),
		.outUseValid     (1),
		.outUseReady     (1),
		.outReadyLatency (0)
	) avalon_st_adapter (
		.in_clk_0_clk        (clk_clk),                                        // in_clk_0.clk
		.in_rst_0_reset      (rst_controller_reset_out_reset),                 // in_rst_0.reset
		.in_0_data           (eth_fifo_avalon_streaming_source_data),          //     in_0.data
		.in_0_valid          (eth_fifo_avalon_streaming_source_valid),         //         .valid
		.in_0_ready          (eth_fifo_avalon_streaming_source_ready),         //         .ready
		.in_0_startofpacket  (eth_fifo_avalon_streaming_source_startofpacket), //         .startofpacket
		.in_0_endofpacket    (eth_fifo_avalon_streaming_source_endofpacket),   //         .endofpacket
		.out_0_data          (avalon_st_adapter_out_0_data),                   //    out_0.data
		.out_0_valid         (avalon_st_adapter_out_0_valid),                  //         .valid
		.out_0_ready         (avalon_st_adapter_out_0_ready),                  //         .ready
		.out_0_startofpacket (avalon_st_adapter_out_0_startofpacket),          //         .startofpacket
		.out_0_endofpacket   (avalon_st_adapter_out_0_endofpacket),            //         .endofpacket
		.out_0_empty         (avalon_st_adapter_out_0_empty)                   //         .empty
	);

	altera_reset_controller #(
		.NUM_RESET_INPUTS          (1),
		.OUTPUT_RESET_SYNC_EDGES   ("deassert"),
		.SYNC_DEPTH                (2),
		.RESET_REQUEST_PRESENT     (0),
		.RESET_REQ_WAIT_TIME       (1),
		.MIN_RST_ASSERTION_TIME    (3),
		.RESET_REQ_EARLY_DSRT_TIME (1),
		.USE_RESET_REQUEST_IN0     (0),
		.USE_RESET_REQUEST_IN1     (0),
		.USE_RESET_REQUEST_IN2     (0),
		.USE_RESET_REQUEST_IN3     (0),
		.USE_RESET_REQUEST_IN4     (0),
		.USE_RESET_REQUEST_IN5     (0),
		.USE_RESET_REQUEST_IN6     (0),
		.USE_RESET_REQUEST_IN7     (0),
		.USE_RESET_REQUEST_IN8     (0),
		.USE_RESET_REQUEST_IN9     (0),
		.USE_RESET_REQUEST_IN10    (0),
		.USE_RESET_REQUEST_IN11    (0),
		.USE_RESET_REQUEST_IN12    (0),
		.USE_RESET_REQUEST_IN13    (0),
		.USE_RESET_REQUEST_IN14    (0),
		.USE_RESET_REQUEST_IN15    (0),
		.ADAPT_RESET_REQUEST       (0)
	) rst_controller (
		.reset_in0      (~reset_reset_n),                 // reset_in0.reset
		.clk            (clk_clk),                        //       clk.clk
		.reset_out      (rst_controller_reset_out_reset), // reset_out.reset
		.reset_req      (),                               // (terminated)
		.reset_req_in0  (1'b0),                           // (terminated)
		.reset_in1      (1'b0),                           // (terminated)
		.reset_req_in1  (1'b0),                           // (terminated)
		.reset_in2      (1'b0),                           // (terminated)
		.reset_req_in2  (1'b0),                           // (terminated)
		.reset_in3      (1'b0),                           // (terminated)
		.reset_req_in3  (1'b0),                           // (terminated)
		.reset_in4      (1'b0),                           // (terminated)
		.reset_req_in4  (1'b0),                           // (terminated)
		.reset_in5      (1'b0),                           // (terminated)
		.reset_req_in5  (1'b0),                           // (terminated)
		.reset_in6      (1'b0),                           // (terminated)
		.reset_req_in6  (1'b0),                           // (terminated)
		.reset_in7      (1'b0),                           // (terminated)
		.reset_req_in7  (1'b0),                           // (terminated)
		.reset_in8      (1'b0),                           // (terminated)
		.reset_req_in8  (1'b0),                           // (terminated)
		.reset_in9      (1'b0),                           // (terminated)
		.reset_req_in9  (1'b0),                           // (terminated)
		.reset_in10     (1'b0),                           // (terminated)
		.reset_req_in10 (1'b0),                           // (terminated)
		.reset_in11     (1'b0),                           // (terminated)
		.reset_req_in11 (1'b0),                           // (terminated)
		.reset_in12     (1'b0),                           // (terminated)
		.reset_req_in12 (1'b0),                           // (terminated)
		.reset_in13     (1'b0),                           // (terminated)
		.reset_req_in13 (1'b0),                           // (terminated)
		.reset_in14     (1'b0),                           // (terminated)
		.reset_req_in14 (1'b0),                           // (terminated)
		.reset_in15     (1'b0),                           // (terminated)
		.reset_req_in15 (1'b0)                            // (terminated)
	);

endmodule
