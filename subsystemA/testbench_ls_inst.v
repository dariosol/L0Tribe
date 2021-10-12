	testbench_ls u0 (
		.clk_200_out_clk_clk                                     (<connected-to-clk_200_out_clk_clk>),                                     //                              clk_200_out_clk.clk
		.clk_50_clk                                              (<connected-to-clk_50_clk>),                                              //                                       clk_50.clk
		.ctrl_sig_export                                         (<connected-to-ctrl_sig_export>),                                         //                                     ctrl_sig.export
		.ddr2_ram_status_local_init_done                         (<connected-to-ddr2_ram_status_local_init_done>),                         //                              ddr2_ram_status.local_init_done
		.ddr2_ram_status_local_cal_success                       (<connected-to-ddr2_ram_status_local_cal_success>),                       //                                             .local_cal_success
		.ddr2_ram_status_local_cal_fail                          (<connected-to-ddr2_ram_status_local_cal_fail>),                          //                                             .local_cal_fail
		.dma_fifo_subsystem_2_fifo_stream_conduit_end_fifo_data  (<connected-to-dma_fifo_subsystem_2_fifo_stream_conduit_end_fifo_data>),  // dma_fifo_subsystem_2_fifo_stream_conduit_end.fifo_data
		.dma_fifo_subsystem_2_fifo_stream_conduit_end_fifo_write (<connected-to-dma_fifo_subsystem_2_fifo_stream_conduit_end_fifo_write>), //                                             .fifo_write
		.dma_fifo_subsystem_2_fifo_stream_conduit_end_fifo_send  (<connected-to-dma_fifo_subsystem_2_fifo_stream_conduit_end_fifo_send>),  //                                             .fifo_send
		.dma_fifo_subsystem_3_fifo_stream_conduit_end_fifo_data  (<connected-to-dma_fifo_subsystem_3_fifo_stream_conduit_end_fifo_data>),  // dma_fifo_subsystem_3_fifo_stream_conduit_end.fifo_data
		.dma_fifo_subsystem_3_fifo_stream_conduit_end_fifo_write (<connected-to-dma_fifo_subsystem_3_fifo_stream_conduit_end_fifo_write>), //                                             .fifo_write
		.dma_fifo_subsystem_3_fifo_stream_conduit_end_fifo_send  (<connected-to-dma_fifo_subsystem_3_fifo_stream_conduit_end_fifo_send>),  //                                             .fifo_send
		.dma_fifo_subsystem_4_fifo_stream_conduit_end_fifo_data  (<connected-to-dma_fifo_subsystem_4_fifo_stream_conduit_end_fifo_data>),  // dma_fifo_subsystem_4_fifo_stream_conduit_end.fifo_data
		.dma_fifo_subsystem_4_fifo_stream_conduit_end_fifo_write (<connected-to-dma_fifo_subsystem_4_fifo_stream_conduit_end_fifo_write>), //                                             .fifo_write
		.dma_fifo_subsystem_4_fifo_stream_conduit_end_fifo_send  (<connected-to-dma_fifo_subsystem_4_fifo_stream_conduit_end_fifo_send>),  //                                             .fifo_send
		.fifo_stream_fifo_data                                   (<connected-to-fifo_stream_fifo_data>),                                   //                                  fifo_stream.fifo_data
		.fifo_stream_fifo_write                                  (<connected-to-fifo_stream_fifo_write>),                                  //                                             .fifo_write
		.fifo_stream_fifo_send                                   (<connected-to-fifo_stream_fifo_send>),                                   //                                             .fifo_send
		.fifo_stream_1_fifo_data                                 (<connected-to-fifo_stream_1_fifo_data>),                                 //                                fifo_stream_1.fifo_data
		.fifo_stream_1_fifo_write                                (<connected-to-fifo_stream_1_fifo_write>),                                //                                             .fifo_write
		.fifo_stream_1_fifo_send                                 (<connected-to-fifo_stream_1_fifo_send>),                                 //                                             .fifo_send
		.from_fifo_fifo_data                                     (<connected-to-from_fifo_fifo_data>),                                     //                                    from_fifo.fifo_data
		.from_fifo_fifo_read                                     (<connected-to-from_fifo_fifo_read>),                                     //                                             .fifo_read
		.from_fifo_fifo_empty                                    (<connected-to-from_fifo_fifo_empty>),                                    //                                             .fifo_empty
		.from_fifo_fifo_full                                     (<connected-to-from_fifo_fifo_full>),                                     //                                             .fifo_full
		.input_io_0_external_connection_export                   (<connected-to-input_io_0_external_connection_export>),                   //               input_io_0_external_connection.export
		.input_io_1_external_connection_export                   (<connected-to-input_io_1_external_connection_export>),                   //               input_io_1_external_connection.export
		.input_io_2_external_connection_export                   (<connected-to-input_io_2_external_connection_export>),                   //               input_io_2_external_connection.export
		.input_io_3_external_connection_export                   (<connected-to-input_io_3_external_connection_export>),                   //               input_io_3_external_connection.export
		.input_io_4_external_connection_export                   (<connected-to-input_io_4_external_connection_export>),                   //               input_io_4_external_connection.export
		.input_io_external_connection_export                     (<connected-to-input_io_external_connection_export>),                     //                 input_io_external_connection.export
		.memory_mem_a                                            (<connected-to-memory_mem_a>),                                            //                                       memory.mem_a
		.memory_mem_ba                                           (<connected-to-memory_mem_ba>),                                           //                                             .mem_ba
		.memory_mem_ck                                           (<connected-to-memory_mem_ck>),                                           //                                             .mem_ck
		.memory_mem_ck_n                                         (<connected-to-memory_mem_ck_n>),                                         //                                             .mem_ck_n
		.memory_mem_cke                                          (<connected-to-memory_mem_cke>),                                          //                                             .mem_cke
		.memory_mem_cs_n                                         (<connected-to-memory_mem_cs_n>),                                         //                                             .mem_cs_n
		.memory_mem_dm                                           (<connected-to-memory_mem_dm>),                                           //                                             .mem_dm
		.memory_mem_ras_n                                        (<connected-to-memory_mem_ras_n>),                                        //                                             .mem_ras_n
		.memory_mem_cas_n                                        (<connected-to-memory_mem_cas_n>),                                        //                                             .mem_cas_n
		.memory_mem_we_n                                         (<connected-to-memory_mem_we_n>),                                         //                                             .mem_we_n
		.memory_mem_dq                                           (<connected-to-memory_mem_dq>),                                           //                                             .mem_dq
		.memory_mem_dqs                                          (<connected-to-memory_mem_dqs>),                                          //                                             .mem_dqs
		.memory_mem_dqs_n                                        (<connected-to-memory_mem_dqs_n>),                                        //                                             .mem_dqs_n
		.memory_mem_odt                                          (<connected-to-memory_mem_odt>),                                          //                                             .mem_odt
		.memory_1_mem_a                                          (<connected-to-memory_1_mem_a>),                                          //                                     memory_1.mem_a
		.memory_1_mem_ba                                         (<connected-to-memory_1_mem_ba>),                                         //                                             .mem_ba
		.memory_1_mem_ck                                         (<connected-to-memory_1_mem_ck>),                                         //                                             .mem_ck
		.memory_1_mem_ck_n                                       (<connected-to-memory_1_mem_ck_n>),                                       //                                             .mem_ck_n
		.memory_1_mem_cke                                        (<connected-to-memory_1_mem_cke>),                                        //                                             .mem_cke
		.memory_1_mem_cs_n                                       (<connected-to-memory_1_mem_cs_n>),                                       //                                             .mem_cs_n
		.memory_1_mem_dm                                         (<connected-to-memory_1_mem_dm>),                                         //                                             .mem_dm
		.memory_1_mem_ras_n                                      (<connected-to-memory_1_mem_ras_n>),                                      //                                             .mem_ras_n
		.memory_1_mem_cas_n                                      (<connected-to-memory_1_mem_cas_n>),                                      //                                             .mem_cas_n
		.memory_1_mem_we_n                                       (<connected-to-memory_1_mem_we_n>),                                       //                                             .mem_we_n
		.memory_1_mem_dq                                         (<connected-to-memory_1_mem_dq>),                                         //                                             .mem_dq
		.memory_1_mem_dqs                                        (<connected-to-memory_1_mem_dqs>),                                        //                                             .mem_dqs
		.memory_1_mem_dqs_n                                      (<connected-to-memory_1_mem_dqs_n>),                                      //                                             .mem_dqs_n
		.memory_1_mem_odt                                        (<connected-to-memory_1_mem_odt>),                                        //                                             .mem_odt
		.oct_rdn                                                 (<connected-to-oct_rdn>),                                                 //                                          oct.rdn
		.oct_rup                                                 (<connected-to-oct_rup>),                                                 //                                             .rup
		.oct_1_rdn                                               (<connected-to-oct_1_rdn>),                                               //                                        oct_1.rdn
		.oct_1_rup                                               (<connected-to-oct_1_rup>),                                               //                                             .rup
		.pilot_sig_external_connection_export                    (<connected-to-pilot_sig_external_connection_export>),                    //                pilot_sig_external_connection.export
		.reset_reset_n                                           (<connected-to-reset_reset_n>)                                            //                                        reset.reset_n
	);
