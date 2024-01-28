//
// Created by Maxwell Conradt on 1/25/24.
//

#ifndef TRANSFORMERS_TENSOR_H
#define TRANSFORMERS_TENSOR_H

typedef struct Tensor {
    int nDim;
    int size;
    float *data;
    int *shape;
} Tensor;

extern struct Tensor makeTensor(int nDim, int shape[]);

extern struct Tensor makeZeros(int nDim, int shape[]);

extern struct Tensor makeFull(int nDim, int shape[], float value);

extern void freeTensor(Tensor *tensor);

#endif //TRANSFORMERS_TENSOR_H
