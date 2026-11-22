struct View_800664B0 { char pad[76]; unsigned int value[1]; };

unsigned int fn_800664B0(const struct View_800664B0 *object, unsigned int index) { return object->value[index & 255U]; }
