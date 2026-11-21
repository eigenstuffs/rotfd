extern "C" float fn_800A8E8C(float value, float lower, float upper) {
    if (value <= lower) return lower;
    if (value >= upper) return upper;
    return value;
}
