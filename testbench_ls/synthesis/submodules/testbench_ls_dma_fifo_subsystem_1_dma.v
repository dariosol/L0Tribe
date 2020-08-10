// testbench_ls_dma_fifo_subsystem_1_dma.v

// This file was auto-generated from altera_msgdma_hw.tcl.  If you edit it your changes
// will probably be lost.
// 
// Generated using ACDS version 18.1 646

`timescale 1 ps / 1 ps
module testbench_ls_dma_fifo_subsystem_1_dma (
		output wire [29:0]  mm_read_address,              //          mm_read.address
		output wire         mm_read_read,                 //                 .read
		output wire [31:0]  mm_read_byteenable,           //                 .byteenable
		input  wire [255:0] mm_read_readdata,             //                 .readdata
		input  wire         mm_read_waitrequest,          //                 .waitrequest
		input  wire         mm_read_readdatavalid,        //                 .readdatavalid
		output wire [2:0]   mm_read_burstcount,           //                 .burstcount
		input  wire         clock_clk,                    //            clock.clk
		input  wire         reset_n_reset_n,              //          reset_n.reset_n
		input  wire [31:0]  csr_writedata,                //              csr.writedata
		input  wire         csr_write,                    //                 .write
		input  wire [3:0]   csr_byteenable,               //                 .byteenable
		output wire [31:0]  csr_readdata,                 //                 .readdata
		input  wire         csr_read,                     //                 .read
		input  wire [2:0]   csr_address,                  //                 .address
		input  wire         descriptor_slave_write,       // descriptor_slave.write
		output wire         descriptor_slave_waitrequest, //                 .waitrequest
		input  wire [127:0] descriptor_slave_writedata,   //                 .writedata
		input  wire [15:0]  descriptor_slave_byteenable,  //                 .byteenable
		output wire         csr_irq_irq,                  //          csr_irq.irq
		output wire [255:0] st_source_data,               //        st_source.data
		output wire         st_source_valid,              //                 .valid
		input  wire         st_source_ready               //                 .ready
	);

	wire          dispatcher_internal_read_command_source_valid; // dispatcher_internal:src_read_master_valid -> read_mstr_internal:snk_command_valid
	wire  [255:0] dispatcher_internal_read_command_source_data;  // dispatcher_internal:src_read_master_data -> read_mstr_internal:snk_command_data
	wire          dispatcher_internal_read_command_source_ready; // read_mstr_internal:snk_command_ready -> dispatcher_internal:src_read_master_ready
	wire          read_mstr_internal_response_source_valid;      // read_mstr_internal:src_response_valid -> dispatcher_internal:snk_read_master_valid
	wire  [255:0] read_mstr_internal_response_source_data;       // read_mstr_internal:src_response_data -> dispatcher_internal:snk_read_master_data
	wire          read_mstr_internal_response_source_ready;      // dispatcher_internal:snk_read_master_ready -> read_mstr_internal:src_response_ready

	dispatcher #(
		.MODE                        (1),
		.RESPONSE_PORT               (2),
		.DESCRIPTOR_INTERFACE        (0),
		.DESCRIPTOR_FIFO_DEPTH       (128),
		.ENHANCED_FEATURES           (0),
		.DESCRIPTOR_WIDTH            (128),
		.DESCRIPTOR_BYTEENABLE_WIDTH (16)
	) dispatcher_internal (
		.clk                     (clock_clk),                                                                                                                                                                                                                                                             //               clock.clk
		.reset                   (~reset_n_reset_n),                                                                                                                                                                                                                                                      //         clock_reset.reset
		.csr_writedata           (csr_writedata),                                                                                                                                                                                                                                                         //                 CSR.writedata
		.csr_write               (csr_write),                                                                                                                                                                                                                                                             //                    .write
		.csr_byteenable          (csr_byteenable),                                                                                                                                                                                                                                                        //                    .byteenable
		.csr_readdata            (csr_readdata),                                                                                                                                                                                                                                                          //                    .readdata
		.csr_read                (csr_read),                                                                                                                                                                                                                                                              //                    .read
		.csr_address             (csr_address),                                                                                                                                                                                                                                                           //                    .address
		.descriptor_write        (descriptor_slave_write),                                                                                                                                                                                                                                                //    Descriptor_Slave.write
		.descriptor_waitrequest  (descriptor_slave_waitrequest),                                                                                                                                                                                                                                          //                    .waitrequest
		.descriptor_writedata    (descriptor_slave_writedata),                                                                                                                                                                                                                                            //                    .writedata
		.descriptor_byteenable   (descriptor_slave_byteenable),                                                                                                                                                                                                                                           //                    .byteenable
		.src_read_master_data    (dispatcher_internal_read_command_source_data),                                                                                                                                                                                                                          // Read_Command_Source.data
		.src_read_master_valid   (dispatcher_internal_read_command_source_valid),                                                                                                                                                                                                                         //                    .valid
		.src_read_master_ready   (dispatcher_internal_read_command_source_ready),                                                                                                                                                                                                                         //                    .ready
		.snk_read_master_data    (read_mstr_internal_response_source_data),                                                                                                                                                                                                                               //  Read_Response_Sink.data
		.snk_read_master_valid   (read_mstr_internal_response_source_valid),                                                                                                                                                                                                                              //                    .valid
		.snk_read_master_ready   (read_mstr_internal_response_source_ready),                                                                                                                                                                                                                              //                    .ready
		.csr_irq                 (csr_irq_irq),                                                                                                                                                                                                                                                           //             csr_irq.irq
		.src_response_data       (),                                                                                                                                                                                                                                                                      //         (terminated)
		.src_response_valid      (),                                                                                                                                                                                                                                                                      //         (terminated)
		.src_response_ready      (1'b0),                                                                                                                                                                                                                                                                  //         (terminated)
		.snk_descriptor_data     (128'b00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000),                                                                                                                                 //         (terminated)
		.snk_descriptor_valid    (1'b0),                                                                                                                                                                                                                                                                  //         (terminated)
		.snk_descriptor_ready    (),                                                                                                                                                                                                                                                                      //         (terminated)
		.mm_response_waitrequest (),                                                                                                                                                                                                                                                                      //         (terminated)
		.mm_response_byteenable  (4'b0000),                                                                                                                                                                                                                                                               //         (terminated)
		.mm_response_address     (1'b0),                                                                                                                                                                                                                                                                  //         (terminated)
		.mm_response_readdata    (),                                                                                                                                                                                                                                                                      //         (terminated)
		.mm_response_read        (1'b0),                                                                                                                                                                                                                                                                  //         (terminated)
		.src_write_master_data   (),                                                                                                                                                                                                                                                                      //         (terminated)
		.src_write_master_valid  (),                                                                                                                                                                                                                                                                      //         (terminated)
		.src_write_master_ready  (1'b0),                                                                                                                                                                                                                                                                  //         (terminated)
		.snk_write_master_data   (256'b0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000), //         (terminated)
		.snk_write_master_valid  (1'b0),                                                                                                                                                                                                                                                                  //         (terminated)
		.snk_write_master_ready  ()                                                                                                                                                                                                                                                                       //         (terminated)
	);

	read_master #(
		.DATA_WIDTH                (256),
		.LENGTH_WIDTH              (13),
		.FIFO_DEPTH                (2048),
		.STRIDE_ENABLE             (0),
		.BURST_ENABLE              (1),
		.PACKET_ENABLE             (0),
		.ERROR_ENABLE              (0),
		.ERROR_WIDTH               (8),
		.CHANNEL_ENABLE            (0),
		.CHANNEL_WIDTH             (8),
		.BYTE_ENABLE_WIDTH         (32),
		.BYTE_ENABLE_WIDTH_LOG2    (5),
		.ADDRESS_WIDTH             (30),
		.FIFO_DEPTH_LOG2           (11),
		.SYMBOL_WIDTH              (8),
		.NUMBER_OF_SYMBOLS         (32),
		.NUMBER_OF_SYMBOLS_LOG2    (5),
		.MAX_BURST_COUNT_WIDTH     (3),
		.UNALIGNED_ACCESSES_ENABLE (0),
		.ONLY_FULL_ACCESS_ENABLE   (1),
		.BURST_WRAPPING_SUPPORT    (0),
		.PROGRAMMABLE_BURST_ENABLE (0),
		.MAX_BURST_COUNT           (4),
		.FIFO_SPEED_OPTIMIZATION   (1),
		.STRIDE_WIDTH              (1)
	) read_mstr_internal (
		.clk                  (clock_clk),                                     //            Clock.clk
		.reset                (~reset_n_reset_n),                              //      Clock_reset.reset
		.master_address       (mm_read_address),                               // Data_Read_Master.address
		.master_read          (mm_read_read),                                  //                 .read
		.master_byteenable    (mm_read_byteenable),                            //                 .byteenable
		.master_readdata      (mm_read_readdata),                              //                 .readdata
		.master_waitrequest   (mm_read_waitrequest),                           //                 .waitrequest
		.master_readdatavalid (mm_read_readdatavalid),                         //                 .readdatavalid
		.master_burstcount    (mm_read_burstcount),                            //                 .burstcount
		.src_data             (st_source_data),                                //      Data_Source.data
		.src_valid            (st_source_valid),                               //                 .valid
		.src_ready            (st_source_ready),                               //                 .ready
		.snk_command_data     (dispatcher_internal_read_command_source_data),  //     Command_Sink.data
		.snk_command_valid    (dispatcher_internal_read_command_source_valid), //                 .valid
		.snk_command_ready    (dispatcher_internal_read_command_source_ready), //                 .ready
		.src_response_data    (read_mstr_internal_response_source_data),       //  Response_Source.data
		.src_response_valid   (read_mstr_internal_response_source_valid),      //                 .valid
		.src_response_ready   (read_mstr_internal_response_source_ready),      //                 .ready
		.src_sop              (),                                              //      (terminated)
		.src_eop              (),                                              //      (terminated)
		.src_empty            (),                                              //      (terminated)
		.src_error            (),                                              //      (terminated)
		.src_channel          ()                                               //      (terminated)
	);

endmodule
