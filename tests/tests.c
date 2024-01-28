//
// Created by Maxwell Conradt on 1/21/24.
//

#include "stdbool.h"
#include "stdio.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

#include "tensor.h"
#include "llamaConfig.h"


/* Test Suite setup and cleanup functions: */

int init_suite(void) { return 0; }

int clean_suite(void) { return 0; }

/************* Test case functions ****************/

void makeTensor_test_1(void) {
    int shape[3] = {1, 2, 3};
    struct Tensor tensor = makeTensor(3, shape);
    CU_ASSERT_EQUAL(tensor.nDim, 3);
    CU_ASSERT_EQUAL(tensor.size, 6);
    CU_ASSERT_TRUE(memcmp(shape, tensor.shape, 3) == 0);
    // How to test tensor.data?
    freeTensor(&tensor);
}

void makeFull_test_1(void) {
    int shape[3] = {1, 2, 3};
    struct Tensor tensor = makeFull(3, shape, 0.5);
    CU_ASSERT_EQUAL(tensor.nDim, 3);
    CU_ASSERT_EQUAL(tensor.size, 6);
    CU_ASSERT_TRUE(memcmp(shape, tensor.shape, 3) == 0);
    float data[6] = {0.5};
    CU_ASSERT_TRUE(memcmp(tensor.data, data, 6) == 0);
    // How to test tensor.data?
    freeTensor(&tensor);
}

void makeZeros_test_1(void) {
    int shape[3] = {1, 2, 3};
    struct Tensor tensor = makeZeros(3, shape);
    CU_ASSERT_EQUAL(tensor.nDim, 3);
    CU_ASSERT_EQUAL(tensor.size, 6);
    CU_ASSERT_TRUE(memcmp(shape, tensor.shape, 3) == 0);
    float data[6] = {0.0};
    CU_ASSERT_TRUE(memcmp(tensor.data, data, 6) == 0);
    // How to test tensor.data?
    freeTensor(&tensor);
}

void freeTensor_test_1(void) {
    int shape[3] = {1, 2, 3};
    struct Tensor tensor = makeTensor(3, shape);
    freeTensor(&tensor);
    CU_ASSERT_EQUAL(tensor.data, NULL);
    CU_ASSERT_EQUAL(tensor.shape, NULL);
}

void llamaConfig_test_7b(void) {
    CU_ASSERT_EQUAL(LLAMA_7B.hiddenSize, 4096);
    CU_ASSERT_EQUAL(LLAMA_7B.intermediateSize, 11008);
    CU_ASSERT_EQUAL(LLAMA_7B.maxPositionEmbeddings, 4096);
    CU_ASSERT_EQUAL(LLAMA_7B.nAttentionHeads, 32);
    CU_ASSERT_EQUAL(LLAMA_7B.nHiddenLayers, 32);
    CU_ASSERT_EQUAL(LLAMA_7B.nKeyValueHeads, 32);
    CU_ASSERT_EQUAL(LLAMA_7B.rmsNormEps, 1e-5f);
    CU_ASSERT_EQUAL(LLAMA_7B.vocabSize, 32000);
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
            (NULL == CU_add_test(pSuite, "makeZeros_test_1", makeZeros_test_1)) ||
            (NULL == CU_add_test(pSuite, "makeZeros_test_1", makeFull_test_1)) ||
            (NULL == CU_add_test(pSuite, "freeTensor_test_1", freeTensor_test_1)) ||
            (NULL == CU_add_test(pSuite, "llamaConfig_test_7b", llamaConfig_test_7b))
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