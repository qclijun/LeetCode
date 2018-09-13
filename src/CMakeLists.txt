
include_directories(${PROJECT_SOURCE_DIR}/include)

# executable
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(p105 p105.cc)
target_link_libraries(p105 tree ${GTEST_BOTH_LIBRARIES})

add_executable(p106 p106.cc)
target_link_libraries(p106 tree ${GTEST_BOTH_LIBRARIES})

add_executable(p96 p96.cc)
target_link_libraries(p96 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p111 p111.cc)
TARGET_LINK_LIBRARIES(p111 tree ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p112 p112.cc)
TARGET_LINK_LIBRARIES(p112 tree ${GTEST_BOTH_LIBRARIES})


ADD_EXECUTABLE(p113 p113.cc)
TARGET_LINK_LIBRARIES(p113 tree ${GTEST_BOTH_LIBRARIES})