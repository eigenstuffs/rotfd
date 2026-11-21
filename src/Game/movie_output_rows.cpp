#include "Game/movie_output_rows.h"

extern "C" {
void fn_80291B88(unsigned char*, int, int, int, int, int, int);
void fn_80291D20(unsigned char*, unsigned char*, int, int, int, int);
}

extern "C" void fn_80292648(unsigned char* workspace, unsigned char* output,
    int stride, MovieOutputRowState* state)
{
    unsigned int mode = state->currentPair[1];
    if (mode == 0) {
        unsigned char* previous = state->previous;
        int value = state->currentPair[0];
        int above = (previous[1] & 0x77) ? value : previous[0];
        unsigned char* next = state->next;
        int below = (next[1] & 0x77) ? value : next[0];
        int right = (state->nextPair[1] & 0x77) ? value : state->nextPair[0];
        fn_80291B88(output, stride, value, above, below, state->last, right);
        state->last = value;
    } else if (mode == 8) {
        int value = state->currentPair[0];
        output[0] = output[1] = output[2] = output[3] = value;
        unsigned char* next = output + stride;
        next[0] = next[1] = next[2] = next[3] = value;
        next += stride;
        next[0] = next[1] = next[2] = next[3] = value;
        next += stride;
        next[0] = next[1] = next[2] = next[3] = value;
        state->last = value;
    } else {
        fn_80291D20(workspace, output, stride, state->currentPair[0], mode,
            state->planeIndex);
        state->last = state->nextPair[0];
    }
    state->previous += 2;
    state->next += 2;
}

extern "C" void fn_8029278C(unsigned char* workspace, unsigned char* output,
    int stride, MovieOutputRowState* state, int blocks)
{
    int count = blocks - 1;
    *(unsigned short*)state->nextPair = *(unsigned short*)state->current;
    state->last = state->current[0];
    for (; count > 0; count--) {
        *(unsigned short*)state->currentPair = *(unsigned short*)state->nextPair;
        unsigned char* current = state->current + 2;
        state->current = current;
        *(unsigned short*)state->nextPair = *(unsigned short*)current;
        fn_80292648(workspace, output, stride, state);
        output += 4;
    }
    *(unsigned short*)state->currentPair = *(unsigned short*)state->nextPair;
    state->current += 6;
    fn_80292648(workspace, output, stride, state);
    state->previous += 4;
    state->next += 4;
}

extern "C" void fn_80292860(unsigned char* workspace, int index,
    unsigned char* output)
{
    MovieDecoderPlane* plane = (MovieDecoderPlane*)(workspace + index * 0x38);
    int width = plane->width;
    int stride = width;
    int advance = width * 4;
    int blocks = plane->blocksWidth;
    int rows = plane->blocksHeight;
    int paddedBytes = plane->paddedWidth * 2;
    MovieOutputRowState state;
    state.planeIndex = index;
    unsigned char* source = *(unsigned char**)((unsigned char*)plane + 4);
    state.previous = source;
    state.current = source;
    state.next = source + paddedBytes;
    if (rows > 0) {
        fn_8029278C(workspace, output, stride, &state, blocks);
        output += advance;
        rows--;
    }
    state.previous = *(unsigned char**)((unsigned char*)plane + 4);
    for (; rows > 1; rows--) {
        fn_8029278C(workspace, output, stride, &state, blocks);
        output += advance;
    }
    if (rows > 0) {
        state.next = state.current;
        fn_8029278C(workspace, output, stride, &state, blocks);
    }
}
