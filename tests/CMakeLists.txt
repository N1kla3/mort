add_executable(mortTests test.cpp)
target_link_libraries(mortTests mort GTest::gtest GTest::gtest_main)
add_test(NAME tests COMMAND mortTests)
