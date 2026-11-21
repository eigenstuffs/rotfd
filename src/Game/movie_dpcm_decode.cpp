#include "Game/movie_dpcm_decode.h"

extern "C" void fn_80295FAC(unsigned char* input, short* output, int channels,
                            unsigned int mode, unsigned int count,
                            MovieDpcmChannel* state)
{
    unsigned int high;
    unsigned int low;
    int value;
    MovieDpcmTables* tables = &lbl_802F23A0;

    if (input == 0) {
        return;
    }

    short* begin = state[0].begin;
    short* end = state[0].end;
    if (channels == 2) {
        if (mode == 1) {
            high = input[0];
            low = input[1];
            state[0].sample = (high << 8) | (low & 0x80);
            state[0].index = low & 0x7F;
            input += 2;

            high = input[0];
            low = input[1];
            state[1].sample = (high << 8) | (low & 0x80);
            state[1].index = low & 0x7F;
            input += 2;

            output[1] = state[0].sample;
            output[0] = state[1].sample;
            output += 2;
            if (output >= end) {
                output = begin;
            }
            count--;
        } else if (mode == 3) {
            value = (short)((input[0] << 8) | input[1]);
            state[0].sample = value;
            state[0].index = input[2];
            input += 3;

            value = (short)((input[0] << 8) | input[1]);
            state[1].sample = value;
            state[1].index = input[2];
            input += 3;

            output[1] = state[0].sample;
            output[0] = state[1].sample;
            output += 2;
            if (output >= end) {
                output = begin;
            }
            count--;
        }

        int first = state[0].sample;
        unsigned int firstIndex = state[0].index;
        int second = state[1].sample;
        unsigned int secondIndex = state[1].index;
        for (; count != 0; count--) {
            unsigned int byte = *input++;
            unsigned int nibble = (byte >> 4) & 7;
            if ((byte & 0x80) == 0) {
                first += tables->deltas[firstIndex][nibble];
                if (first > 32767) {
                    first = 32767;
                }
            } else {
                first -= tables->deltas[firstIndex][nibble];
                if (first < -32768) {
                    first = -32768;
                }
            }
            {
                unsigned char* cursor = (unsigned char*)tables + firstIndex * 8;
                cursor += nibble;
                firstIndex = cursor[0xB20];
            }

            nibble = byte & 7;
            if ((byte & 8) == 0) {
                second += tables->deltas[secondIndex][nibble];
                if (second > 32767) {
                    second = 32767;
                }
            } else {
                second -= tables->deltas[secondIndex][nibble];
                if (second < -32768) {
                    second = -32768;
                }
            }
            {
                unsigned char* cursor = (unsigned char*)tables + secondIndex * 8;
                cursor += nibble;
                secondIndex = cursor[0xB20];
            }

            output[1] = (short)first;
            output[0] = (short)second;
            output += 2;
            if (output >= end) {
                output = begin;
            }
        }
        state[0].sample = (short)first;
        state[0].index = firstIndex;
        state[1].sample = (short)second;
        state[1].index = secondIndex;
        state[0].input = input;
        state[1].input = input;
        state[0].output = output;
        state[1].output = output;
    } else {
        if (mode == 1) {
            high = input[0];
            low = input[1];
            state[0].sample = (high << 8) | (low & 0x80);
            state[0].index = low & 0x7F;
            input += 2;

            short initialSample = state[0].sample;
            output[1] = initialSample;
            output[0] = initialSample;
            output += 2;
            if (output >= end) {
                output = begin;
            }
            count--;
        } else if (mode == 3) {
            value = (short)((input[0] << 8) | input[1]);
            state[0].sample = value;
            state[0].index = input[2];
            input += 3;

            short initialSample = state[0].sample;
            output[1] = initialSample;
            output[0] = initialSample;
            output += 2;
            if (output >= end) {
                output = begin;
            }
            count--;
        }

        int sample = state[0].sample;
        unsigned int index = state[0].index;
        while (count != 0) {
            unsigned int byte = *input++;
            unsigned int nibble = (byte >> 4) & 7;
            if ((byte & 0x80) == 0) {
                sample += tables->deltas[index][nibble];
                if (sample > 32767) {
                    sample = 32767;
                }
            } else {
                sample -= tables->deltas[index][nibble];
                if (sample < -32768) {
                    sample = -32768;
                }
            }
            {
                unsigned char* cursor = (unsigned char*)tables + index * 8;
                cursor += nibble;
                index = cursor[0xB20];
            }

            output[1] = (short)sample;
            output[0] = (short)sample;
            output += 2;
            if (output >= end) {
                output = begin;
            }
            if (count == 1) {
                break;
            }

            nibble = byte & 7;
            if ((byte & 8) == 0) {
                sample += tables->deltas[index][nibble];
                if (sample > 32767) {
                    sample = 32767;
                }
            } else {
                sample -= tables->deltas[index][nibble];
                if (sample < -32768) {
                    sample = -32768;
                }
            }
            {
                unsigned char* cursor = (unsigned char*)tables + index * 8;
                cursor += nibble;
                index = cursor[0xB20];
            }

            output[1] = (short)sample;
            output[0] = (short)sample;
            output += 2;
            if (output >= end) {
                output = begin;
            }
            count -= 2;
        }
        state[0].sample = (short)sample;
        state[0].index = index;
        state[0].input = input;
        state[0].output = output;
    }
}
