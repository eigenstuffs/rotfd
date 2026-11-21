#ifndef GAME_EARLY_SCREEN_SCENE_CONTROL_VIEWS_H
#define GAME_EARLY_SCREEN_SCENE_CONTROL_VIEWS_H
typedef unsigned long ScreenSceneWord;
struct ScreenSceneObjectPrefix{char unknown00[8];};
struct ScreenSceneObject:ScreenSceneObjectPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void clear();};
struct ScreenSceneEntry{ScreenSceneObject*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ScreenSceneManager{char unknown00[8];ScreenSceneEntry*entries;};
struct ScreenSceneHandle{signed int tag:8,index:24;};
struct Handle_801F7F10{union{ScreenSceneWord word;ScreenSceneHandle bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ScreenSceneOwner{char unknown00[0x1504C];int mode;char unknown15050[8];ScreenSceneObject*first;ScreenSceneObject*second;ScreenSceneObject*message;ScreenSceneObject*other;char unknown15068[4];Handle_801F7F10 related;};
struct ScreenSceneService{char unknown00[0x4C];ScreenSceneObject*object;};
struct ScreenSceneContext{char unknown00[0x118];ScreenSceneManager*manager;char unknown11C[0x48];ScreenSceneService*service;};
extern "C" {extern ScreenSceneContext lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_80260F64(ScreenSceneOwner*);ScreenSceneWord fn_801F7EB8(const Handle_801F7F10*);void fn_801F86C8(ScreenSceneManager*,const void*,short);}
template<int D>struct SceneLayer140:SceneLayer140<D-1>{~SceneLayer140(){}};template<>struct SceneLayer140<1>:Handle_801F7F10{~SceneLayer140(){}};
struct Handle_8003E120:SceneLayer140<2>{~Handle_8003E120(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C" Handle_8003E120 fn_800BCEF8(ScreenSceneOwner*);
inline ScreenSceneObject*resolveScreen(const Handle_801F7F10&h){int index=h.bits.index;ScreenSceneManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline signed char validScreen(const Handle_801F7F10&h){return fn_801F7EB8(&h)!=0;}
struct Handle_80021C40:Handle_801F7F10{Handle_80021C40(){word=0;}~Handle_80021C40(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021BCC:Handle_80021C40{Handle_80021BCC(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80021BCC(){}Handle_80021BCC&operator=(const Handle_80021BCC&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return *this;}};
extern "C" {Handle_801F7F10 fn_801B52EC(ScreenSceneManager*,const char*);extern const char agent_type_registry_CMsgBoxManipulator[],agent_type_registry_DisplayStaticImage[];void fn_800BE2CC();void fn_800BE8AC();extern void(*lbl_80378160)();extern void(*lbl_80378164)();}
inline void assignScreen(Handle_801F7F10&dest,const Handle_80021BCC&source){fn_801F86C8(lbl_801E9D24.manager,&dest,-1);dest.word=source.word;fn_801F86C8(lbl_801E9D24.manager,&source,1);}
#endif
