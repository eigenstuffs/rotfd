struct View_80066240 { char pad[76]; unsigned int value[1]; };

unsigned int fn_80066240(const struct View_80066240 *object, unsigned int index) { return object->value[index & 65535U]; }
