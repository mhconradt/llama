include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)
message("SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
find_package(CUnit REQUIRED)

message("CUNIT_INCLUDE_DIRS ${CUNIT_INCLUDE_DIRS}")
include_directories(${CUNIT_INCLUDE_DIRS})
message(${CUNIT_INCLUDE_DIRS})
link_libraries("${CUNIT_LIBRARY_DIRS}/libcunit.dylib")

set(TEST_SOURCES
        tests.c
)

add_executable(transformers_test ${TEST_SOURCES})
target_link_libraries(transformers_test transformers "${CUNIT_LIBRARY_DIRS}/libcunit.dylib")

add_test(NAME TransformersTest COMMAND transformers_test)