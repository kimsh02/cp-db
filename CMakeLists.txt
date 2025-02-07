CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(db)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(COMPILER_FLAGS "-Wall -Wextra -pedantic -Werror")
set(ADDRESS_SANITIZER_FLAGS "-fsanitize=address,undefined,leak -fno-omit-frame-pointer -fno-optimize-sibling-calls")
set(THREAD_SANITIZER_FLAGS "-fsanitize=thread,undefined -fno-omit-frame-pointer -fno-optimize-sibling-calls")
set(DEBUG_FLAGS "-g")
set(OPTIMIZATION_FLAGS "-O3")
set(IGNORE_ERROR_FLAGS "-Wno-c99-designator")

if (CMAKE_BUILD_TYPE STREQUAL "memory")
  set(CMAKE_CXX_FLAGS "${COMPILER_FLAGS} ${ADDRESS_SANITIZER_FLAGS} ${DEBUG_FLAGS} ${IGNORE_ERROR_FLAGS}")
elseif (CMAKE_BUILD_TYPE STREQUAL "thread")
  set(CMAKE_CXX_FLAGS "${COMPILER_FLAGS} ${THREAD_SANITIZER_FLAGS} ${DEBUG_FLAGS} ${IGNORE_ERROR_FLAGS}")
elseif (CMAKE_BUILD_TYPE STREQUAL "release")
  set(CMAKE_CXX_FLAGS "${COMPILER_FLAGS} ${OPTIMIZATION_FLAGS} ${IGNORE_ERROR_FLAGS}")
endif()

option(ENABLE_COVERAGE "Enable coverage reporting" OFF)
if (ENABLE_COVERAGE)
  message(STATUS "Building with coverage flags...")
  add_compile_options(-fprofile-instr-generate -fcoverage-mapping)

  # Detect and link the correct `clang_rt.profile` library for the system
  if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")  # macOS
    set(COVERAGE_LIB "-lclang_rt.profile_osx")
  elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")  # Linux
    set(COVERAGE_LIB "-lclang_rt.profile")
  else()
    message(WARNING "Unknown system, trying generic coverage library")
    set(COVERAGE_LIB "-lclang_rt.profile")
  endif()
  add_link_options(${COVERAGE_LIB})
endif()

# Headers
include_directories(${CMAKE_SOURCE_DIR}/include)
# Implementation
file(GLOB SOURCES
  ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(db ${SOURCES})

enable_testing()
add_subdirectory(tests)

if (ENABLE_COVERAGE)
  set(TEST_IGNORE_REGEX ".*/tests/.*")  # Ignore anything in the tests directory

  # Explicit coverage data paths
  set(COVERAGE_RAW_FILE "${CMAKE_BINARY_DIR}/db.profraw")
  set(COVERAGE_RAW_FILE_TEST "${CMAKE_BINARY_DIR}/dbtest.profraw")
  set(COVERAGE_DATA_FILE "${CMAKE_BINARY_DIR}/coverage.profdata")
  set(COVERAGE_HTML_DIR "${CMAKE_BINARY_DIR}/coverage_html")
  set(COVERAGE_HTML_DIR_TEST "${CMAKE_BINARY_DIR}/coverage_html_test")

  # Custom target to run `db` with coverage
  add_custom_target(run-db
    COMMAND LLVM_PROFILE_FILE=${COVERAGE_RAW_FILE} ./db
    DEPENDS db
    COMMENT "Running db with coverage..."
    VERBATIM
  )

  # Custom target to run `dbtest` with coverage
  add_custom_target(run-dbtest
    COMMAND LLVM_PROFILE_FILE=${COVERAGE_RAW_FILE_TEST} ./tests/dbtest
    DEPENDS tests/dbtest
    COMMENT "Running dbtest with coverage..."
    VERBATIM
  )

  # Merge coverage data from db and dbtest
  add_custom_target(coverage-merge
    COMMAND llvm-profdata merge -sparse ${COVERAGE_RAW_FILE} ${COVERAGE_RAW_FILE_TEST} -o ${COVERAGE_DATA_FILE}
    DEPENDS run-db run-dbtest
    COMMENT "Merging coverage data..."
    VERBATIM
  )

  # Generate text coverage report for db
  add_custom_target(coverage-db-text
    COMMAND llvm-cov report ./db -instr-profile=${COVERAGE_DATA_FILE}
    DEPENDS coverage-merge
    COMMENT "Generating text coverage report for db..."
    VERBATIM
  )

  # Generate text coverage report for dbtest
  add_custom_target(coverage-dbtest-text
    COMMAND llvm-cov report ./tests/dbtest -instr-profile=${COVERAGE_DATA_FILE}
    DEPENDS coverage-merge
    COMMENT "Generating text coverage report for dbtest..."
    VERBATIM
  )

  # Generate HTML coverage report for db
  add_custom_target(coverage-db-html
    COMMAND llvm-cov show ./db -instr-profile=${COVERAGE_DATA_FILE} -format=html
  -output-dir=${COVERAGE_HTML_DIR} -ignore-filename-regex=${TEST_IGNORE_REGEX}
    DEPENDS coverage-merge
    COMMENT "Generating HTML coverage report for db..."
    VERBATIM
  )

  # Generate HTML coverage report for dbtest
  add_custom_target(coverage-dbtest-html
    COMMAND llvm-cov show ./tests/dbtest -instr-profile=${COVERAGE_DATA_FILE}
  -format=html -output-dir=${COVERAGE_HTML_DIR_TEST} -ignore-filename-regex=${TEST_IGNORE_REGEX}
    DEPENDS coverage-merge
    COMMENT "Generating HTML coverage report for dbtest..."
    VERBATIM
  )
endif()
