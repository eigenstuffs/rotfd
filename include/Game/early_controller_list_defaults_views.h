#ifndef GAME_EARLY_CONTROLLER_LIST_DEFAULTS_VIEWS_H
#define GAME_EARLY_CONTROLLER_LIST_DEFAULTS_VIEWS_H
extern "C"{extern char lbl_8028F698[];void*fn_8028FAF4(void*,void*,unsigned long,unsigned long);void*fn_8028FF24(void*,unsigned long);void fn_8028FD50(void*,void*,unsigned long);extern const unsigned long lbl_80375498,lbl_8037549C;extern const float lbl_803754A0,lbl_80379368;}
inline void*operator new(unsigned long,void*p){return p;}
struct Handle_801F7F10{unsigned long word;Handle_801F7F10();~Handle_801F7F10();};
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78();};
template<class T>struct ControllerDefaultArray{int count,capacity;T*data;ControllerDefaultArray(){count=0;capacity=0;data=0;}void grow(int size){if(size){if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),size*sizeof(T));else data=(T*)fn_8028FF24(lbl_8028F698,size*sizeof(T));}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}void ensure(int step){if(count+1>capacity){grow(capacity+step);capacity+=step;}}void append(const T&v,int step){ensure(step);new(&data[count++])T(v);}void appendDefault(int step){ensure(step);new(&data[count++])T;}};
struct Object_800B5A34:ControllerDefaultArray<ControllerDefaultArray<Handle_8001FF78> >{~Object_800B5A34();};
struct Object_800B5960:ControllerDefaultArray<Handle_8001FF78>{~Object_800B5960();};
struct Array_800B58A8:ControllerDefaultArray<unsigned long>{~Array_800B58A8();};
struct Array_800B57F0:ControllerDefaultArray<float>{~Array_800B57F0();};
struct ControllerListDefaults{Object_800B5A34 vectors;Object_800B5960 handles;Array_800B58A8 first,second;float scalar;Array_800B57F0 floats;ControllerListDefaults();};
#endif
