//
// Created by Maxwell Conradt on 1/28/24.
//

#ifndef TRANSFORMERS_LLAMACONFIG_H
#define TRANSFORMERS_LLAMACONFIG_H

typedef struct LlamaConfig {
    int hiddenSize;
    int intermediateSize;
    int maxPositionEmbeddings;
    int nAttentionHeads;
    int nHiddenLayers;
    int nKeyValueHeads;
    float rmsNormEps;
    int vocabSize;
} LlamaConfig;

extern const LlamaConfig LLAMA_7B;

#endif //TRANSFORMERS_LLAMACONFIG_H
