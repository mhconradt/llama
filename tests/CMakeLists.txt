include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

# set(CUNIT_INSTALL_DIR "/opt/homebrew/Cellar/cunit/2.1-3/")
find_package(CUnit REQUIRED)

message("CUNIT_INCLUDE_DIRS ${CUNIT_INCLUDE_DIRS}")
include_directories(${CUNIT_INCLUDE_DIRS})
message(${CUNIT_INCLUDE_DIRS})
link_libraries("/opt/homebrew/Cellar/cunit/2.1-3/lib/libcunit.dylib")

set(TEST_SOURCES
        max_test.c
)

add_executable(transformers_test ${TEST_SOURCES})
target_link_libraries(transformers_test transformers "/opt/homebrew/Cellar/cunit/2.1-3/lib/libcunit.dylib")

add_test(NAME TransformersTest COMMAND transformers_test)