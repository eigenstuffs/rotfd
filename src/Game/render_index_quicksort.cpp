#include "Game/render_index_quicksort.h"

struct RenderIndexSortOwner {
    char unknown00[0x3AC];
    char* entries3AC;
};

extern "C" void fn_80271D74(RenderIndexSortOwner* self, unsigned short* indices,
                          int first, int last)
{
    int pivot = (last - first) / 2;
    int left = first;
    int right = last;
    if (last > first) {
        while (left <= right) {
            while (left < last &&
                   *(float*)(self->entries3AC + indices[left] * 0xA8 + 0x94) <
                   *(float*)(self->entries3AC + indices[pivot] * 0xA8 + 0x94))
                ++left;
            while (right > first &&
                   *(float*)(self->entries3AC + indices[right] * 0xA8 + 0x94) >
                   *(float*)(self->entries3AC + indices[pivot] * 0xA8 + 0x94))
                --right;
            if (left <= right) {
                unsigned short tmp = indices[left];
                indices[left] = indices[right];
                indices[right] = tmp;
                ++left;
                --right;
            }
        }
        if (first < right)
            fn_80271D74(self, indices, first, right);
        if (last > left)
            fn_80271D74(self, indices, left, last);
    }
}
