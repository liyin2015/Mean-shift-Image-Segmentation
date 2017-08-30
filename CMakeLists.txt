#project(imageSegment)
find_package(Boost COMPONENTS system filesystem program_options REQUIRED)
add_library(dependencies ms.cpp RAList.cpp rlist.cpp loadImage.cpp dir_segmentation.cpp call_segment.cpp call_segment.h)

add_library(processor msImageProcessor.cpp)
target_link_libraries(processor dependencies)

add_library(call_segment call_segment.cpp loadImage.cpp)
target_link_libraries(call_segment processor)
add_executable(test_segment test_segment.cpp)
target_link_libraries(test_segment processor ${Boost_LIBRARIES})

add_executable(dir_segment dir_segmentation.cpp)
target_link_libraries(dir_segment call_segment ${Boost_LIBRARIES})
