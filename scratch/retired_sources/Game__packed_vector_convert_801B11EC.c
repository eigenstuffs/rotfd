/* Decode three signed 16-bit vector components with the original scale. */
extern const float lbl_8037A20C;

void fn_801B11EC(const unsigned char* input, float* output)
{
    const short* packed = (const short*)(input + 8);
    output[0] = (float)packed[0] * lbl_8037A20C;
    output[1] = (float)packed[1] * lbl_8037A20C;
    output[2] = (float)packed[2] * lbl_8037A20C;
}

void fn_801B1264(const unsigned char* input, float* output)
{
    const short* packed = (const short*)(input + 2);
    output[0] = (float)packed[0] * lbl_8037A20C;
    output[1] = (float)packed[1] * lbl_8037A20C;
    output[2] = (float)packed[2] * lbl_8037A20C;
}
