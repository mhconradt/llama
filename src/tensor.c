//
// Created by Maxwell Conradt on 1/25/24.
//
#include <stdlib.h>
#include <string.h>  // For memcpy
#include "tensor.h"

struct FloatTensor makeTensor(int nDim, int shape[]) {
    struct FloatTensor tensor;

    if (nDim <= 0 || shape == NULL) {
        // Handle error: Invalid dimensions or null shape array
        return tensor;
    }

    // Allocate memory for shape in the tensor
    tensor.shape = malloc(sizeof(int) * nDim);
    if (tensor.shape == NULL) {
        // Handle error: Memory allocation failed for shape
        return tensor;
    }
    // Copy the shape array
    memcpy(tensor.shape, shape, sizeof(int) * nDim);

    int size = 1;
    for (int i = 0; i < nDim; i++) {
        size *= shape[i];
    }
    tensor.nDim = nDim;
    tensor.size = size;
    tensor.data = malloc(sizeof(float) * size);
    if (tensor.data == NULL) {
        // Handle error: Memory allocation failed for data
        free(tensor.shape);  // Free the allocated shape memory
        return tensor;
    }

    return tensor;
}

void freeTensor(struct FloatTensor *tensor) {
    if (tensor != NULL) {
        if (tensor->data != NULL) {
            free(tensor->data);
            tensor->data = NULL;
        }
        if (tensor->shape != NULL) {
            free(tensor->shape);
            tensor->shape = NULL;
        }
        tensor->nDim = 0;
        tensor->size = 0;
    }
}
