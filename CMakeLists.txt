cmake_minimum_required(VERSION 2.8)
project(imageSegment)

add_library(dependencies ms.cpp RAList.cpp rlist.cpp loadImage.cpp)

add_library(processor msImageProcessor.cpp)
target_link_libraries(processor dependencies)
add_executable(test_segment test_segment.cpp)
target_link_libraries(test_segment processor)
