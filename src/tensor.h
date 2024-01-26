//
// Created by Maxwell Conradt on 1/25/24.
//

#ifndef TRANSFORMERS_TENSOR_H
#define TRANSFORMERS_TENSOR_H

typedef struct FloatTensor {
    int nDim;
    int size;
    float *data;
    int *shape;
} Tensor;

extern struct FloatTensor makeTensor(int nDim, int shape[]);

extern void freeTensor(Tensor *tensor);

#endif //TRANSFORMERS_TENSOR_H
