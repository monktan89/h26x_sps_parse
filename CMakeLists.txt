project(h26x_sps_parse)

#使能c++11
set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.1.3)
aux_source_directory(. SRC_LIST)

add_executable(test_h26x_analysis ${SRC_LIST})
target_link_libraries(test_h26x_analysis ${LINK_LIB_LIST} pthread)