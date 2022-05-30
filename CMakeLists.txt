cmake_minimum_required(VERSION 3.22)
project(pfcp_request_analyzer C)

set(CMAKE_C_STANDARD 99)

add_executable(pfcp_request_analyzer analyzer.c helper.c helper.h dpdk.h pfcp_message.c n4_pfcp_handler.c n4_pfcp_handler.h utlt_buff.c)
