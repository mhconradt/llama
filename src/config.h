//
// Created by Maxwell Conradt on 1/28/24.
//

#ifndef TRANSFORMERS_CONFIG_H
#define TRANSFORMERS_CONFIG_H

typedef struct LlamaConfig {
    int vocabSize;
    int hiddenSize;
    int nHiddenLayers;
    int nAttentionHeads;
    int nKeyValueHeads;
} LlamaConfig;

extern const LlamaConfig LLAMA_7B;

#endif //TRANSFORMERS_CONFIG_H
