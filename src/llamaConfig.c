//
// Created by Maxwell Conradt on 1/28/24.
//

#include "llamaConfig.h"

const LlamaConfig LLAMA_7B = {
        4096,
        11008,
        32,
        32,
        32
};

int maxi(int n1, int n2) {
    if (n1 > n2) {
        return n1;
    }
    return n2;
}