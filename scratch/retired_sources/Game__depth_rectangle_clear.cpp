extern "C" void GXPokeZMode(int, int, int);

extern "C" void fn_80273448(void*, int x, int y, int width, int height) {
    GXPokeZMode(1, 7, 1);
    volatile unsigned long* data = (volatile unsigned long*)0xC8400000 + x + y * 1024;
    int stride = 1024 - width;
    int row = y;
    int xend = x + width;
    int yend = y + height;
    for (; row < yend; ++row) {
        for (int column = x; column < xend; ++column) *data++ = 0xFFFFFF;
        data += stride;
    }
}
