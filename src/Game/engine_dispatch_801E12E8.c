struct State {
    char pad[0x860];
    int count;
    char pad864[0x41];
    signed char enabled;
    char pad8A6[0x12];
    float requested;
};
struct Globals {
    char pad[0x110];
    struct State *state;
    void *views;
};
extern struct Globals lbl_801E9D24;
extern char lbl_802ACD70[],lbl_802ACE00[];
extern void fn_801FA014(struct State *,const char *,...);
extern void fn_801E1658(void *,unsigned int);
int fn_801E12E8(void){
    struct State *state=lbl_801E9D24.state;
    if(state->count!=2){
        fn_801FA014(state,lbl_802ACD70);
        return 1;
    }
    if(!state->enabled){
        fn_801FA014(state,lbl_802ACE00);
        return 1;
    }fn_801E1658(lbl_801E9D24.views,(unsigned int)state->requested);
    return 1;
}
