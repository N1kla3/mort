add_executable(mortTests vec3test.cpp coretest.cpp vec2test.cpp)
target_link_libraries(mortTests mort GTest::gtest GTest::gtest_main)
add_test(NAME tests COMMAND mortTests)
