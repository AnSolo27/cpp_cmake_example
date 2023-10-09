include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)

# configure build of googletest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)

# Sources
file(GLOB_RECURSE TEST_SOURCES FOLLOW_SYMLINKS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    )

add_executable(
    unit_tests
    ${TEST_SOURCES}
    )

target_link_libraries(unit_tests
  PRIVATE
    STACK_LIB
    LL_LIB
    QUEUE_LIB
    gtest_main
  )

# automatic discovery of unit tests
include(GoogleTest)
gtest_discover_tests(unit_tests
  PROPERTIES
    LABELS "unit"
  DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
    240
  )