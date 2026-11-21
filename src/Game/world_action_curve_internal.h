#ifndef GAME_WORLD_ACTION_CURVE_INTERNAL_H
#define GAME_WORLD_ACTION_CURVE_INTERNAL_H
#include "world_curve_arrays_internal.h"
// Nested action records and manager fields reconstructed from GSQE78.
// Entry types 17, 18 and 19 own a token index; other meanings remain unknown.
template<class T> struct WorldActionArray {
    int count,capacity; T*data;
    // The containing curve initializes these words after installing its table.
    WorldActionArray(){}
    ~WorldActionArray(){
        if(data){
            for(int i=0;i<count;++i) data[i].~T();
            if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}
            data=0;
        }
    }
};

struct ActionEntry {int type,index;u32 unknown;~ActionEntry(){}};
struct ActionRow {u32 prefix;WorldActionArray<ActionEntry> entries;~ActionRow(){}};
struct WorldActionCurve_801F7560 : CurveBase_801B1088 {
    WorldActionArray<ActionRow> rows;
    WorldActionCurve_801F7560(){rows.count=0;rows.capacity=0;rows.data=0;}
    ActionRow& row(int i){return rows.data[i];}
    virtual ~WorldActionCurve_801F7560();
    static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
struct ActionToken {char unknown[128];signed char flag;};
struct ActionManager {
    char unknown[0xD4];ActionToken* tokens;
    u32 unknownD8,unknownDC;u32* words;
    u32 unknownE4,unknownE8;int used;
    const u32& word(int index) {u32* base=words;return base[index];}
    signed char test(int index){return (word(index>>5) & (1UL << (index&31))) ? 1 : 0;}
    void release(int index){
        if(!tokens[index].flag){
            if(test(index)){
                words[index>>5]&=~(1UL << (index&31));--used;
            }
        }
    }
};
typedef char CheckActionEntry[sizeof(ActionEntry)==12?1:-1];
typedef char CheckActionRow[sizeof(ActionRow)==16?1:-1];
typedef char CheckActionCurve[sizeof(WorldActionCurve_801F7560)==20?1:-1];
#endif
