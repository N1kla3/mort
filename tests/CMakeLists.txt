add_executable(mortTests vec3test.cpp coretest.cpp)
target_link_libraries(mortTests mort GTest::gtest GTest::gtest_main)
add_test(NAME tests COMMAND mortTests)
