//
// Created by Maxwell Conradt on 1/28/24.
//

#ifndef TRANSFORMERS_LLAMACONFIG_H
#define TRANSFORMERS_LLAMACONFIG_H

typedef struct LlamaConfig {
    int vocabSize;
    int hiddenSize;
    int nHiddenLayers;
    int nAttentionHeads;
    int nKeyValueHeads;
} LlamaConfig;

extern const LlamaConfig LLAMA_7B;

extern int maxi(int n1, int n2);

#endif //TRANSFORMERS_LLAMACONFIG_H
