# executable
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)


ADD_SUBDIRECTORY(graph)

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

ADD_EXECUTABLE(p35 p35.cc)
TARGET_LINK_LIBRARIES(p35 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p74 p74.cc)
TARGET_LINK_LIBRARIES(p74 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p78 p78.cc)
TARGET_LINK_LIBRARIES(p78 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p31 p31.cc)
TARGET_LINK_LIBRARIES(p31 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p126 p126.cc)
TARGET_LINK_LIBRARIES(p126 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p126_2 p126_2.cc)
TARGET_LINK_LIBRARIES(p126_2 ${GTEST_BOTH_LIBRARIES})


ADD_EXECUTABLE(p131 p131.cc)
TARGET_LINK_LIBRARIES(p131 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p62 p62.cc)
TARGET_LINK_LIBRARIES(p62 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p63 p63.cc)
TARGET_LINK_LIBRARIES(p63 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p51 p51.cc)
TARGET_LINK_LIBRARIES(p51 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p52 p52.cc)
TARGET_LINK_LIBRARIES(p52 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p93 p93.cc)
TARGET_LINK_LIBRARIES(p93 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p39 p39.cc)
TARGET_LINK_LIBRARIES(p39 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p40 p40.cc)
TARGET_LINK_LIBRARIES(p40 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p22 p22.cc)
TARGET_LINK_LIBRARIES(p22 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p37 p37.cc)
TARGET_LINK_LIBRARIES(p37 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p79 p79.cc)
TARGET_LINK_LIBRARIES(p79 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p50 p50.cc)
TARGET_LINK_LIBRARIES(p50 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p69 p69.cc)
TARGET_LINK_LIBRARIES(p69 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p55 p55.cc)
TARGET_LINK_LIBRARIES(p55 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p45 p45.cc)
TARGET_LINK_LIBRARIES(p45 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p121 p121.cc)
TARGET_LINK_LIBRARIES(p121 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p120 p120.cc)
TARGET_LINK_LIBRARIES(p120 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p53 p53.cc)
TARGET_LINK_LIBRARIES(p53 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p132 p132.cc)
TARGET_LINK_LIBRARIES(p132 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p85 p85.cc)
TARGET_LINK_LIBRARIES(p85 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p123 p123.cc)
TARGET_LINK_LIBRARIES(p123 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p97 p97.cc)
TARGET_LINK_LIBRARIES(p97 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p64 p64.cc)
TARGET_LINK_LIBRARIES(p64 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p72 p72.cc)
TARGET_LINK_LIBRARIES(p72 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p91 p91.cc)
TARGET_LINK_LIBRARIES(p91 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p115 p115.cc)
TARGET_LINK_LIBRARIES(p115 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p139 p139.cc)
TARGET_LINK_LIBRARIES(p139 ${GTEST_BOTH_LIBRARIES})

ADD_EXECUTABLE(p140 p140.cc)
TARGET_LINK_LIBRARIES(p140 ${GTEST_BOTH_LIBRARIES})
