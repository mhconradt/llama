//
// Created by Maxwell Conradt on 1/21/24.
//

#include "stdio.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"
#include "CUnit/Console.h"

#include "tensor.h"

#include "stdlib.h"
#include <stdio.h>  // for printf

/* Test Suite setup and cleanup functions: */

int init_suite(void) { return 0; }

int clean_suite(void) { return 0; }

/************* Test case functions ****************/

void makeTensor_test_1(void) {
    int shape[3] = {1, 2, 3};
    struct FloatTensor tensor = makeTensor(3, shape);
    CU_ASSERT_EQUAL(tensor.nDim, 3);
    CU_ASSERT_EQUAL(tensor.size, 6);
    CU_ASSERT_TRUE(memcmp(shape, tensor.shape, 3) == 0);
    freeTensor(&tensor);
}

void freeTensor_test_1(void) {
    int shape[3] = {1, 2, 3};
    struct FloatTensor tensor = makeTensor(3, shape);
    freeTensor(&tensor);
    CU_ASSERT_EQUAL(tensor.data, NULL);
    CU_ASSERT_EQUAL(tensor.shape, NULL);
}

/************* Test Runner Code goes here **************/

int main(void) {
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("max_test_suite", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if (
            (NULL == CU_add_test(pSuite, "makeTensor_test_1", makeTensor_test_1)) ||
            (NULL == CU_add_test(pSuite, "freeTensor_test_1", freeTensor_test_1))
            ) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");
/*
   // Run all tests using the automated interface
   CU_automated_run_tests();
   CU_list_tests_to_file();

   // Run all tests using the console interface
   CU_console_run_tests();
*/
    /* Clean up registry and return */
    CU_cleanup_registry();
    return CU_get_error();
}