#ifndef GAME_MOVIE_DECODER_TABLES_H
#define GAME_MOVIE_DECODER_TABLES_H
extern "C" {
    extern unsigned char lbl_80373140[512];
    extern int lbl_80373340[16];
    extern int lbl_80373380[512];
    void fn_80290B88();
}
typedef char CheckMovieDecoderTableWord[sizeof(int)==4?1:-1];
#endif
