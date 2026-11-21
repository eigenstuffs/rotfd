#include "Game/movie_block_interpolation.h"

extern "C" void fn_80292AC8(unsigned char* output, int outputStride,
    const unsigned char* input, int inputStride)
{
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            output[col] = input[col];
        }
        input += inputStride;
        output += outputStride;
    }
}

extern "C" void fn_80292B64(unsigned char* output, int outputStride,
    const unsigned char* input, int inputStride)
{
    for (int col = 0; col < 4; col++) {
        output[col] = (input[col] + input[col + 1] + 1) >> 1;
    }
    input += inputStride;
    output += outputStride;

    for (int col = 0; col < 4; col++) {
        output[col] = (input[col] + input[col + 1] + 1) >> 1;
    }
    input += inputStride;
    output += outputStride;

    for (int col = 0; col < 4; col++) {
        output[col] = (input[col] + input[col + 1] + 1) >> 1;
    }
    input += inputStride;
    output += outputStride;

    for (int col = 0; col < 4; col++) {
        output[col] = (input[col] + input[col + 1] + 1) >> 1;
    }
    input += inputStride;
    output += outputStride;
}

extern "C" void fn_80292D00(unsigned char* output, int outputStride,
    const unsigned char* input, int inputStride)
{
    const unsigned char* current = input;
    const unsigned char* next = input + inputStride;
    for (int col = 0; col < 4; col++) {
        output[col] = (current[col] + next[col] + 1) >> 1;
    }
    current += inputStride;
    next += inputStride;
    output += outputStride;

    for (int col = 0; col < 4; col++) {
        output[col] = (current[col] + next[col] + 1) >> 1;
    }
    current += inputStride;
    next += inputStride;
    output += outputStride;

    for (int col = 0; col < 4; col++) {
        output[col] = (current[col] + next[col] + 1) >> 1;
    }
    current += inputStride;
    next += inputStride;
    output += outputStride;

    for (int col = 0; col < 4; col++) {
        output[col] = (current[col] + next[col] + 1) >> 1;
    }
    current += inputStride;
    next += inputStride;
    output += outputStride;
}

extern "C" void fn_80292EAC(unsigned char* output, int outputStride,
    const unsigned char* input, int inputStride)
{
    const unsigned char* current = input;
    const unsigned char* next = input + inputStride;
    for (int col = 0; col < 4; col++) {
        output[col] = (current[col] + current[col + 1] + next[col] + next[col + 1] + 2) >> 2;
    }
    current += inputStride;
    next += inputStride;
    output += outputStride;

    for (int col = 0; col < 4; col++) {
        output[col] = (current[col] + current[col + 1] + next[col] + next[col + 1] + 2) >> 2;
    }
    current += inputStride;
    next += inputStride;
    output += outputStride;

    for (int col = 0; col < 4; col++) {
        output[col] = (current[col] + current[col + 1] + next[col] + next[col + 1] + 2) >> 2;
    }
    current += inputStride;
    next += inputStride;
    output += outputStride;

    for (int col = 0; col < 4; col++) {
        output[col] = (current[col] + current[col + 1] + next[col] + next[col + 1] + 2) >> 2;
    }
    current += inputStride;
    next += inputStride;
    output += outputStride;
}
