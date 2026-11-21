#ifndef GAME_MOVIE_DECODER_LAYOUT_H
#define GAME_MOVIE_DECODER_LAYOUT_H
struct MovieDecoderPrefix {
    void* workspace;
    unsigned short width,height;
    unsigned char horizontalMode,verticalMode;
};
struct MovieDecoderDimensions {
    unsigned short width,height;
    unsigned char horizontalMode,verticalMode;
};
extern "C" {
 void fn_80290B88();
 void fn_80294FB4();
 void fn_80294FD4(MovieDecoderPrefix*,const MovieDecoderDimensions*);
 int fn_80294FF8(const MovieDecoderPrefix*);
}
typedef char CheckMovieDecoderPrefix[sizeof(MovieDecoderPrefix)==12?1:-1];
typedef char CheckMovieDecoderDimensions[sizeof(MovieDecoderDimensions)==6?1:-1];
#endif
