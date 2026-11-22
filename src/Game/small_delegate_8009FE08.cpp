struct Config{char unknown0[0x1C];void*value1C;void*value20;void*value24;};
extern "C" void fn_80228408(void*,void*,Config*,void*,void*,void*,void*);
extern "C" int fn_8009FE08(void*self,Config*c,void*,void*extra){fn_80228408(self,c->value1C,c,extra,c->value20,c->value24,extra);return 1;}
