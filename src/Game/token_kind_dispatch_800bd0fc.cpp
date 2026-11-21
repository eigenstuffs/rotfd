struct TokenName { unsigned long word; TokenName() {} TokenName(const char*); void set(const char*); };
struct TokenKindInput { char tokens[16][128]; int count; };
struct TokenKindOutput { int kind,number; TokenName name; };
struct TokenKindContext { char unknown00[0x110]; void* diagnostics; };
extern "C" {
    extern const char agent_type_registry_CMsgBoxManipulator[];
    extern const char lbl_803794A0[7],lbl_803794A8[5],lbl_803794B0[7],lbl_803794B8[7],lbl_803794C0[8];
    extern TokenKindContext lbl_801E9D24;
    int fn_801F4520(const char*,const char*);
    int atoi(const char*);
    unsigned long fn_801F948C(TokenName*,const char*);
    void fn_801FA014(void*,const char*,...);
}
inline TokenName::TokenName(const char* text) { word=fn_801F948C(this,text); }
inline void TokenName::set(const char* text) { word=fn_801F948C(this,text); }
extern "C" void fn_800BD0FC(void*,TokenKindInput* input,TokenKindOutput* output)
{
    const char* pool=agent_type_registry_CMsgBoxManipulator;
    if (fn_801F4520(input->tokens[0],pool+0xb0c)==0) {
        output->kind=0xBF;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xb18)==0) {
        output->kind=0xC0;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xb24)==0) {
        output->kind=0x90;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xb34)==0) {
        output->kind=0x97;
    }
    else if (fn_801F4520(input->tokens[0],lbl_803794A0)==0) {
        output->kind=0x99;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xb48)==0) {
        output->kind=0x9D;
    }
    else if (fn_801F4520(input->tokens[0],lbl_803794A8)==0) {
        output->kind=0xA4;
    }
    else if (fn_801F4520(input->tokens[0],lbl_803794B0)==0) {
        output->kind=0xA5;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xb54)==0) {
        output->kind=0xA6;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xb60)==0) {
        output->kind=0xA7;
    }
    else if (fn_801F4520(input->tokens[0],lbl_803794B8)==0) {
        output->kind=0x0;
    }
    else if (fn_801F4520(input->tokens[0],lbl_803794C0)==0) {
        output->kind=0xA9;
        const char* token=input->tokens[1];
        output->number=(unsigned long)(unsigned char)token[0]<<24;
        output->number+=(signed char)token[1]<<16;
        int value=atoi(token+2);
        if (value>65535) {
            fn_801FA014(lbl_801E9D24.diagnostics,pool+0xB6C);
            fn_801FA014(lbl_801E9D24.diagnostics,pool+0xB7C,token);
            fn_801FA014(lbl_801E9D24.diagnostics,pool+0xB6C);
            value=0;
        }
        output->number+=value;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xbbc)==0) {
        output->kind=0xAE;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xbc8)==0) {
        output->kind=0xAF;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xbd4)==0) {
        output->kind=0xB0;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xbe0)==0) {
        output->kind=0xB1;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xbec)==0) {
        output->kind=0xB2;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xbf8)==0) {
        output->kind=0xB3;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xc04)==0) {
        output->kind=0xB4;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xc10)==0) {
        output->kind=0xB5;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xc1c)==0) {
        output->kind=0xB6;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xc28)==0) {
        output->kind=0xB7;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xc34)==0) {
        output->kind=0xB8;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xc40)==0) {
        output->kind=0xB9;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xc4c)==0) {
        output->kind=0xBA;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xc58)==0) {
        output->kind=0xBB;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xc70)==0) {
        output->kind=0xBC;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xc84)==0) {
        output->kind=0xD0;
        if(input->count>1 && fn_801F4520(input->tokens[1],pool+0xC98)==0)
            output->number=atoi(input->tokens[2]);
        else output->number=100;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xca4)==0) {
        output->kind=0xD6;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xcc0)==0) {
        output->kind=0xD7;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xcdc)==0) {
        if(input->count==2) {
            output->kind=0xD8;
            output->name.set(input->tokens[1]);
        } else output->kind=0;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xcf0)==0) {
        if(input->count==2) {
            output->kind=0xD9;
            output->name.set(input->tokens[1]);
        } else output->kind=0;
    }
    else if (fn_801F4520(input->tokens[0],pool+0xd04)==0) {
        output->kind=0xDC;
        output->name=TokenName(input->tokens[1]);
    }
    else if (fn_801F4520(input->tokens[0],pool+0xd10)==0) {
        output->kind=0xDD;
        output->name=TokenName(input->tokens[1]);
    }
}
