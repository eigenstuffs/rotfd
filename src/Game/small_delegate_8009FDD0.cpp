struct Config{char unknown0[0x28];void*value28;void*value2C;void*value30;};
extern "C" void fn_80228408(void*,void*,Config*,void*,void*,void*,void*);
extern "C" int fn_8009FDD0(void*self,Config*c,void*,void*extra){fn_80228408(self,c->value30,c,extra,c->value28,c->value2C,extra);return 1;}
