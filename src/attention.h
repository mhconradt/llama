//
// Created by Maxwell Conradt on 1/25/24.
//

#ifndef TRANSFORMERS_ATTENTION_H
#define TRANSFORMERS_ATTENTION_H

#include "tensor.h"

typedef struct AttentionParams {
    Tensor qProj;
    Tensor kProj;
    Tensor vProj;
    Tensor oProj;
} AttentionParams;

void selfAttention(Tensor hiddenStates);

#endif //TRANSFORMERS_ATTENTION_H
