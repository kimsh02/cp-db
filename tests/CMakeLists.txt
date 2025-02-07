# Find the testing framework (GoogleTest)
find_package(GTest REQUIRED)

# Source files
set(TEST_SOURCES ${SOURCES})
# Remove main.cpp
list(REMOVE_ITEM TEST_SOURCES ${CMAKE_SOURCE_DIR}/src/main.cpp)
# Test files
file(GLOB TESTS ${PROJECT_SOURCE_DIR}/tests/*.cpp)

# Executable
add_executable(dbtest ${TESTS} ${TEST_SOURCES})

# Link the testing framework
target_link_libraries(dbtest PRIVATE GTest::gtest_main)

# Add the tests to CTest
add_test(NAME DBTest COMMAND dbtest)
