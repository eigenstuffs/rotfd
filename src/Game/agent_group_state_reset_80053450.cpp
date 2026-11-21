/* Agent value tables, group records and item byte tables reset (fn_80053450).
 * Private views expose only the observed offsets; layouts follow the accepted
 * Agent_80052520 destructor (groups at 0x138: eight 0x94-byte records with
 * 0x20-byte items). The shared byte counter in clearValues reproduces the
 * original loop register assignment. */
typedef unsigned long u32;
struct Item {
    char unknown00[4];
    unsigned char flag04;
    char unknown05[3];
    u32 word08, word0C, word10;
    unsigned char* first;
    unsigned char* second;
    unsigned char* third;
};
struct Group {
    int count;
    u32 word04, word08, word0C, word10;
    char unknown14[0xC];
    unsigned char enabled20[9];
    unsigned char flag29, flag2A, flag2B;
    Item* items;
    unsigned short values30[50];
};
struct Agent {
    char unknown00[0x100];
    u32 word100;
    char unknown104[0x34];
    Group* groups;
    u32 word13C, word140, word144;
    unsigned short values148[50];
    unsigned short values1AC[100];
    char unknown274[0x7C];
    u32 word2F0;
    void clearValues()
    {
        unsigned char j;
        for (j = 0; j < 100; j++)
            values1AC[j] = 0;
        for (unsigned char i = 0; i < 8; i++)
            for (j = 0; j < 50; j++)
                groups[i].values30[j] = 0;
        for (unsigned char i = 0; i < 50; i++)
            values148[i] = 0;
    }
};
extern "C" void fn_800AFCC0(Agent*);
extern "C" void fn_80053450(Agent* self)
{
    fn_800AFCC0(self);
    self->clearValues();
    self->word100 = 0;
    self->word2F0 = 0;
    self->word13C = 0;
    self->word140 = 0;
    self->word144 = 0;
    int i;
    for (i = 0; i < 8; i++) {
        self->groups[i].word04 = 0;
        self->groups[i].word08 = 0;
        self->groups[i].word0C = 0;
        self->groups[i].word10 = 0;
        for (int j = 0; j < 9; j++)
            self->groups[i].enabled20[j] = 1;
        self->groups[i].flag29 = 0;
        self->groups[i].flag2A = 0;
        self->groups[i].flag2B = 0;
    }
    for (i = 0; i < 8; i++) {
        for (int j = 0; j < self->groups[i].count; j++) {
            self->groups[i].items[j].flag04 = 0;
            self->groups[i].items[j].word08 = 0;
            self->groups[i].items[j].word0C = 0;
            self->groups[i].items[j].word10 = 0;
            for (int k = 0; k < 250; k++)
                self->groups[i].items[j].first[k] = 1;
            for (int k = 0; k < 100; k++)
                self->groups[i].items[j].second[k] = 1;
            for (int k = 0; k < 100; k++)
                self->groups[i].items[j].third[k] = 1;
        }
    }
}
