struct EngineDispatchScalar {
    char unknown00[0x5D];
    signed char locked;
    char unknown5E[0x3A];
    float value0, value2;
    int value1;
};

extern const float lbl_8037B208, lbl_8037B20C;

void fn_80235D54(struct EngineDispatchScalar* self, int slot, float value)
{
    if (!self->locked) {
        if (slot == 0 && value > lbl_8037B208)
            self->value0 = value;
        if (slot == 1 && value != lbl_8037B20C)
            self->value1 = (int)value;
        if (slot == 2 && value != lbl_8037B20C)
            self->value2 = value;
    }
}
