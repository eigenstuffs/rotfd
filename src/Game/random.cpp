/* Reconstructed seeded generator and shuffle state; see unit notes. */
struct ConsoleArguments {
    unsigned char prefix[0x860];
    int argc;
    unsigned char reserved_864[0x8A5-0x864];
    signed char arg1IsNumeric;
    unsigned char reserved_8a6[0x8B8-0x8A6];
    float arg1Value;
};
extern "C" {
extern struct { unsigned char prefix[0x110]; ConsoleArguments *console; } lbl_801E9D24;
extern long game_random_seed;
extern long game_random_selected,game_random_table[32];
extern signed char game_random_initialized;
double floor(double);
float fn_801F12D4(long *);
int fn_801F1184()
{
    ConsoleArguments *console=lbl_801E9D24.console;
    if(console->argc>=1 && console->arg1IsNumeric) {
        int value=(int)console->arg1Value;
        game_random_seed=value<0?value:-value;
        fn_801F12D4(&game_random_seed);
    } else return 0;
    return 1;
}
float fn_801F1200() { return fn_801F12D4(&game_random_seed); }
int fn_801F1224(int minimum,int maximum)
{
    return minimum+(int)floor((maximum-minimum+1)*fn_801F12D4(&game_random_seed));
}
void fn_801F129C(int value)
{
    game_random_seed=value<0?value:-value;
    fn_801F12D4(&game_random_seed);
}
float fn_801F12D4(long *state)
{
    int j; long k;
    // The original compiler guard is retained explicitly so state can live
    // in its own object without changing initialization or code generation.
    if(!game_random_initialized) {
        game_random_selected=0;
        game_random_initialized=1;
    }
    float result;
    if(*state<=0 || !game_random_selected) {
        if(-*state<1) *state=1;
        else *state=-*state;
        for(j=39;j>=0;--j) {
            k=*state/127773;
            *state=16807*(*state-k*127773)-2836*k;
            if(*state<0) *state+=2147483647;
            if(j<32) game_random_table[j]=*state;
        }
        game_random_selected=game_random_table[0];
    }
    k=*state/127773;
    *state=16807*(*state-k*127773)-2836*k;
    if(*state<0) *state+=2147483647;
    j=game_random_selected/67108864;
    game_random_selected=game_random_table[j];
    game_random_table[j]=*state;
    result=(1.0/2147483647)*game_random_selected;
    if(result>(1.0-1.2e-7)) return (1.0-1.2e-7);
    return result;
}
}


/* The following literals share this original small-data pool with the
 * scalar math routines. Keeping their placement in one object preserves
 * the original eight-byte section alignment. */
extern "C" {
/* Original shared scalar math literals, exported for reconstructed C and
 * remaining native assembly references. See docs/notes/game-scalar-math.md. */
extern const float game_math_zero=0.0f;
extern const float game_math_epsilon=0.000001f;
extern const float game_math_one=1.0f;
extern const float game_math_negative_one=-1.0f;
extern const float game_math_half=0.5f;
extern const float game_math_two=2.0f;
}
