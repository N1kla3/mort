add_executable(mortTests vec3test.cpp coretest.cpp vec2test.cpp matrix3test.cpp rotator2test.cpp quaternionTest.cpp)
target_link_libraries(mortTests mort GTest::gtest GTest::gtest_main)
add_test(NAME tests COMMAND mortTests)
