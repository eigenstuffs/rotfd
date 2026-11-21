/* Genuine default construction of the established four-byte Handle view. */
typedef unsigned long Word;
struct Handle_801F7F10{Word word;Handle_801F7F10();~Handle_801F7F10();};
struct ReticleCtorZero:Handle_801F7F10{ReticleCtorZero(){word=0;}~ReticleCtorZero();};
struct Handle_800723F4:ReticleCtorZero{Handle_800723F4();~Handle_800723F4();};
Handle_800723F4::Handle_800723F4(){word=0;}
