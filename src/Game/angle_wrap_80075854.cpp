// Apply the original bounded degree-angle corrections (360, 0, 180).
// Shared constants retain their original data owners.
extern const float lbl_80378998;
extern const float lbl_8037899C;
extern const float lbl_803789A0;

extern "C" void fn_80075854(float* value) {
    float angle = *value;
    if (angle >= lbl_80378998)
        *value = angle - lbl_80378998;
    if (*value <= lbl_8037899C)
        *value += lbl_80378998;
    if (*value > lbl_803789A0)
        *value -= lbl_80378998;
}
