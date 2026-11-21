#ifndef GAME_EARLY_OWNER_POSITION_TRANSFER_VIEWS_H
#define GAME_EARLY_OWNER_POSITION_TRANSFER_VIEWS_H
struct TransferVector{float x,y,z;TransferVector(){}TransferVector(float xx,float yy,float zz):x(xx),y(yy),z(zz){}TransferVector(const TransferVector&v):x(v.x),y(v.y),z(v.z){}TransferVector&operator=(const TransferVector&v){x=v.x;y=v.y;z=v.z;return*this;}};
struct TransferTransform{char unknown00[0x30];TransferVector position;};
struct TransferResource;
struct TransferHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct TransferEntry{TransferResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct TransferManager{int count,capacity;TransferEntry*entries;};
struct TransferContext{char unknown00[0x118];TransferManager*manager;};
extern "C" TransferContext lbl_801E9D24;
struct TransferResource{char unknown00[0x58];TransferHandle owner;char unknown5C[0xC8];TransferTransform*transform;char unknown128[0x270];TransferVector saved;};
inline TransferResource*resolveTransfer(const TransferHandle&h){TransferEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}
struct TransferPrefix{char unknown00[4];};
struct TransferObject:TransferPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual TransferResource*getResource();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual const TransferHandle*getHandle();char unknown08[0x104];void*pending;};
extern "C" {void fn_8023D100(TransferResource*,const TransferVector*);void fn_8023DE28(TransferResource*);void fn_80069CA8(TransferObject*,TransferResource*,int);void fn_80067808(TransferObject*);}

#endif
