// The provider stores each key in the opposite word order to the owner.
extern "C" int fn_8005B0F0(const void* object)
{
    const int* key = (const int*)((const char*)object + 0xF0);
    const int* table = *(const int* const*)((const char*)object + 0xEC);
    int first = key[0];
    int low, high;

    low = table[10];
    high = table[11];
    if (first == high && key[1] == low)
        return 1;

    low = table[30];
    high = table[31];
    if (first == high && key[1] == low)
        return 1;

    low = table[102];
    high = table[103];
    if (first == high && key[1] == low)
        return 1;

    low = table[106];
    high = table[107];
    if (first == high && key[1] == low)
        return 1;

    low = table[110];
    high = table[111];
    if (first == high && key[1] == low)
        return 1;

    low = table[114];
    high = table[115];
    if (first == high && key[1] == low)
        return 1;

    low = table[98];
    high = table[99];
    if (first == high && key[1] == low)
        return 1;

    return 0;
}
