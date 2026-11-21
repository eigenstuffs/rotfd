#ifndef GAME_ENGINE_TRIPLE_HANDLE_CTOR_H
#define GAME_ENGINE_TRIPLE_HANDLE_CTOR_H

struct Handle_801F7F10 {
 unsigned long value;
 Handle_801F7F10(); ~Handle_801F7F10();
};
struct TripleRecordZero : Handle_801F7F10 { TripleRecordZero(){value=0;} };
struct TripleRecordZero2 : TripleRecordZero { TripleRecordZero2(){value=0;} };
struct TripleRecord_8023BD78 {
 TripleRecordZero2 first,second,third;
 signed char flag;
 char unknown0D[0x1C-0x0D];
 TripleRecord_8023BD78();
};

typedef char CheckTripleRecordSize[sizeof(TripleRecord_8023BD78)==0x1C?1:-1];

#endif
