// testbench_ls_dma_fifo_subsystem_3.v

// Generated using ACDS version 18.1 646

`timescale 1 ps / 1 ps
module testbench_ls_dma_fifo_subsystem_3 (
		input  wire         dma_clock_clk,                      //               dma_clock.clk
		input  wire [31:0]  dma_csr_writedata,                  //                 dma_csr.writedata
		input  wire         dma_csr_write,                      //                        .write
		input  wire [3:0]   dma_csr_byteenable,                 //                        .byteenable
		output wire [31:0]  dma_csr_readdata,                   //                        .readdata
		input  wire         dma_csr_read,                       //                        .read
		input  wire [2:0]   dma_csr_address,                    //                        .address
		output wire         dma_csr_irq_irq,                    //             dma_csr_irq.irq
		input  wire         dma_descriptor_slave_write,         //    dma_descriptor_slave.write
		output wire         dma_descriptor_slave_waitrequest,   //                        .waitrequest
		input  wire [127:0] dma_descriptor_slave_writedata,     //                        .writedata
		input  wire [15:0]  dma_descriptor_slave_byteenable,    //                        .byteenable
		output wire [30:0]  dma_mm_read_address,                //             dma_mm_read.address
		output wire         dma_mm_read_read,                   //                        .read
		output wire [31:0]  dma_mm_read_byteenable,             //                        .byteenable
		input  wire [255:0] dma_mm_read_readdata,               //                        .readdata
		input  wire         dma_mm_read_waitrequest,            //                        .waitrequest
		input  wire         dma_mm_read_readdatavalid,          //                        .readdatavalid
		output wire [2:0]   dma_mm_read_burstcount,             //                        .burstcount
		input  wire         dma_reset_n_reset_n,                //             dma_reset_n.reset_n
		input  wire         fifo_stream_clock_clk,              //       fifo_stream_clock.clk
		output wire [255:0] fifo_stream_conduit_end_fifo_data,  // fifo_stream_conduit_end.fifo_data
		output wire         fifo_stream_conduit_end_fifo_write, //                        .fifo_write
		output wire         fifo_stream_conduit_end_fifo_send,  //                        .fifo_send
		input  wire         fifo_stream_reset_reset_n           //       fifo_stream_reset.reset_n
	);

	wire          dma_st_source_valid; // dma:st_source_valid -> FIFO_stream:asi_valid
	wire  [255:0] dma_st_source_data;  // dma:st_source_data -> FIFO_stream:asi_data
	wire          dma_st_source_ready; // FIFO_stream:asi_ready -> dma:st_source_ready

	streamFIFO fifo_stream (
		.csi_clk     (fifo_stream_clock_clk),              //       clock.clk
		.rsi_reset_n (fifo_stream_reset_reset_n),          //       reset.reset_n
		.fifo_data   (fifo_stream_conduit_end_fifo_data),  // conduit_end.fifo_data
		.fifo_write  (fifo_stream_conduit_end_fifo_write), //            .fifo_write
		.fifo_send   (fifo_stream_conduit_end_fifo_send),  //            .fifo_send
		.asi_ready   (dma_st_source_ready),                //   Avalon_ST.ready
		.asi_valid   (dma_st_source_valid),                //            .valid
		.asi_data    (dma_st_source_data)                  //            .data
	);

	testbench_ls_dma_fifo_subsystem_1_dma dma (
		.mm_read_address              (dma_mm_read_address),              //          mm_read.address
		.mm_read_read                 (dma_mm_read_read),                 //                 .read
		.mm_read_byteenable           (dma_mm_read_byteenable),           //                 .byteenable
		.mm_read_readdata             (dma_mm_read_readdata),             //                 .readdata
		.mm_read_waitrequest          (dma_mm_read_waitrequest),          //                 .waitrequest
		.mm_read_readdatavalid        (dma_mm_read_readdatavalid),        //                 .readdatavalid
		.mm_read_burstcount           (dma_mm_read_burstcount),           //                 .burstcount
		.clock_clk                    (dma_clock_clk),                    //            clock.clk
		.reset_n_reset_n              (dma_reset_n_reset_n),              //          reset_n.reset_n
		.csr_writedata                (dma_csr_writedata),                //              csr.writedata
		.csr_write                    (dma_csr_write),                    //                 .write
		.csr_byteenable               (dma_csr_byteenable),               //                 .byteenable
		.csr_readdata                 (dma_csr_readdata),                 //                 .readdata
		.csr_read                     (dma_csr_read),                     //                 .read
		.csr_address                  (dma_csr_address),                  //                 .address
		.descriptor_slave_write       (dma_descriptor_slave_write),       // descriptor_slave.write
		.descriptor_slave_waitrequest (dma_descriptor_slave_waitrequest), //                 .waitrequest
		.descriptor_slave_writedata   (dma_descriptor_slave_writedata),   //                 .writedata
		.descriptor_slave_byteenable  (dma_descriptor_slave_byteenable),  //                 .byteenable
		.csr_irq_irq                  (dma_csr_irq_irq),                  //          csr_irq.irq
		.st_source_data               (dma_st_source_data),               //        st_source.data
		.st_source_valid              (dma_st_source_valid),              //                 .valid
		.st_source_ready              (dma_st_source_ready)               //                 .ready
	);

endmodule
