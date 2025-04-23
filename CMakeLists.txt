cmake_minimum_required(VERSION 3.12)
project(rtt_logger C)

add_library(rtt_logger STATIC
    src/SEGGER_RTT.c
    src/SEGGER_RTT_printf.c
    src/rtt_logger.c
)

target_include_directories(rtt_logger PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_library(RTT::Logger ALIAS rtt_logger)
