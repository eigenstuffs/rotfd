/* Random key pick: collect the record keys 0x21..0x3B and 0x3D that the agent
 * owns into a stack list (count kept in agent+0x3D0), notify one at random,
 * then finish the action.
 * The count field is a plain (signed) char read into an unsigned char local;
 * the `& 0xFF` index keeps the original's lbz/clrlwi pair. */
struct Agent {
    char unknown00[0x3D0];
    char count;
};

struct Action {
    char unknown00[8];
    Agent* agent;
};

extern "C" {
signed char fn_8009C12C(Agent*, int);
signed char fn_8009FABC(Agent*, int);
void fn_800A4E30(Action*);
int fn_801F1224(int, int);
}

#define ADD_KEY(key)                                   \
    if (fn_8009C12C(self->agent, key)) {               \
        unsigned char n = self->agent->count;          \
        keys[n & 0xFF] = key;                          \
        self->agent->count = n + 1;                    \
    }

extern "C" void fn_800A0028(Action* self) {
    unsigned char keys[48];
    self->agent->count = 0;
    ADD_KEY(0x21) ADD_KEY(0x22) ADD_KEY(0x23) ADD_KEY(0x24) ADD_KEY(0x25)
    ADD_KEY(0x26) ADD_KEY(0x27) ADD_KEY(0x28) ADD_KEY(0x29) ADD_KEY(0x2A)
    ADD_KEY(0x2B) ADD_KEY(0x2C) ADD_KEY(0x2D) ADD_KEY(0x2E) ADD_KEY(0x2F)
    ADD_KEY(0x30) ADD_KEY(0x31) ADD_KEY(0x32) ADD_KEY(0x33) ADD_KEY(0x34)
    ADD_KEY(0x35) ADD_KEY(0x36) ADD_KEY(0x37) ADD_KEY(0x38) ADD_KEY(0x39)
    ADD_KEY(0x3A) ADD_KEY(0x3B) ADD_KEY(0x3D)
    unsigned char n = self->agent->count;
    int index = fn_801F1224(0, n - 1);
    fn_8009FABC(self->agent, keys[index]);
    fn_800A4E30(self);
}
