/* Resource property token decoding; see docs/notes/game-early-resource-token-mask.md. */
extern "C"{int strcmp(const char*,const char*);extern const char agent_type_registry_CMsgBoxManipulator[],lbl_803793A0[8],lbl_803793A8[8];}
extern "C"unsigned long fn_800B7FFC(void*,const char*text){const char*pool=agent_type_registry_CMsgBoxManipulator;
if(strcmp(text,pool+0x28)==0)return 0x800UL;
if(strcmp(text,pool+0x34)==0)return 0x1000UL;
if(strcmp(text,pool+0x40)==0)return 0x2000UL;
if(strcmp(text,lbl_803793A0)==0)return 0x4000UL;
if(strcmp(text,pool+0x4C)==0)return 0x8000UL;
if(strcmp(text,pool+0x58)==0)return 0x10000UL;
if(strcmp(text,pool+0x64)==0)return 0x40000UL;
if(strcmp(text,pool+0x74)==0)return 0x80000UL;
if(strcmp(text,pool+0x84)==0)return 0x100000UL;
if(strcmp(text,pool+0x94)==0)return 0x200000UL;
if(strcmp(text,lbl_803793A8)==0)return 0x20000UL;
if(strcmp(text,pool+0xA4)==0)return 0x400000UL;
if(strcmp(text,pool+0xB0)==0)return 0x800000UL;
if(strcmp(text,pool+0xC0)==0)return 0x1000000UL;
if(strcmp(text,pool+0xD0)==0)return 0x1800000UL;
if(strcmp(text,pool+0xE0)==0)return 0x2000000UL;
if(strcmp(text,pool+0xF0)==0)return 0x2800000UL;
if(strcmp(text,pool+0x100)==0)return 0x3000000UL;
if(strcmp(text,pool+0x110)==0)return 0x3800000UL;
if(strcmp(text,pool+0x120)==0)return 0x4000000UL;
if(strcmp(text,pool+0x130)==0)return 0x4800000UL;
if(strcmp(text,pool+0x140)==0)return 0x5000000UL;
if(strcmp(text,pool+0x150)==0)return 0x5800000UL;
if(strcmp(text,pool+0x160)==0)return 0x6000000UL;
if(strcmp(text,pool+0x170)==0)return 0x6800000UL;
return strcmp(text,pool+0x180)==0?0x8000000UL:0;
}
