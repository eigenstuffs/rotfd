#ifndef GAME_PLATFORM_DISC_READ_H
#define GAME_PLATFORM_DISC_READ_H
#ifdef __cplusplus
extern "C" {
#endif
int DVDReadAsyncPrio(void*,void*,int,int,void(*)(int,void*),int);
int fn_8028EF84(void*);
int fn_8028EEEC(void*,void*,void*,int,int);
#ifdef __cplusplus
}
#endif
#endif
