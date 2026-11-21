#ifndef GAME_EARLY_SELECTED_CONTROLLER_EVENT_VIEWS_H
#define GAME_EARLY_SELECTED_CONTROLLER_EVENT_VIEWS_H

// Observed selected-owner and related-controller views of the original pool.
struct SelectedObject;
struct SelectedHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct SelectedEntry{SelectedObject*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct SelectedManager{int count,capacity;SelectedEntry*entries;};
struct SelectedSelection{char unknown00[0x1C];SelectedHandle*current;};
struct SelectedContext{char unknown00[0x118];SelectedManager*manager;char unknown11C[8];void*scene;char unknown128[0x14];SelectedSelection*selection;};
extern "C" SelectedContext lbl_801E9D24;
struct SelectedObject{char unknown00[0x24];SelectedHandle owner;char unknown28[0x48];SelectedHandle controller;char unknown74[0x3C];SelectedHandle*related;char unknownB4[0x36C];signed char enabled;};
inline SelectedObject*resolveSelected(const SelectedHandle&h){SelectedEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}
extern "C" {signed char fn_8025E9FC(SelectedObject*,int);unsigned long fn_801F7EB8(const SelectedHandle*);void fn_802603A0(void*,int,SelectedObject*,float);extern const float lbl_80378738;}
struct SelectedRelatedObject{char unknown00[0x70];SelectedHandle controller;};
struct RelatedEntry{SelectedRelatedObject*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct RelatedManager{int count,capacity;RelatedEntry*entries;};
inline SelectedRelatedObject*resolveRelated(const SelectedHandle&h){RelatedEntry*entry=&((RelatedManager*)lbl_801E9D24.manager)->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}

#endif
