#ifndef GAME_MOVIE_DPCM_TABLES_H
#define GAME_MOVIE_DPCM_TABLES_H
struct MovieDpcmTables {
    int deltas[89][8];
    unsigned char nextIndex[89][8];
};
extern struct MovieDpcmTables lbl_802F23A0;
typedef char MovieDpcmTablesSize[(sizeof(struct MovieDpcmTables)==3560)?1:-1];
typedef char MovieDpcmIndexOffset[((unsigned int)&((struct MovieDpcmTables*)0)->nextIndex==0xB20)?1:-1];
#endif
