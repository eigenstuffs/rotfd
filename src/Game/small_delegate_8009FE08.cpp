struct Config{char unknown0[0x1C];void*value1C;void*value20;void*value24;};
extern "C" void slot64__13ObjectThrow_ZFv(void*,void*,Config*,void*,void*,void*,void*);
extern "C" int slot60__11CScriptMoveFv(void*self,Config*c,void*,void*extra){slot64__13ObjectThrow_ZFv(self,c->value1C,c,extra,c->value20,c->value24,extra);return 1;}
