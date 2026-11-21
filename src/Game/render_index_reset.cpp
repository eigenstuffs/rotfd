struct RenderIndexResetRecord {unsigned short first,second;};
struct RenderIndexResetStorage {char unknown00[8];};
struct RenderIndexResetObject:RenderIndexResetStorage {
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void reset(void*);
 void clear(){for(int i=0;i<count;++i)records[i].first=0xFFFF;}
 char unknown0C[0x24];int count;char unknown34[4];RenderIndexResetRecord* records;
};
struct RenderIndexResetSelf {char unknown00[0x6E];unsigned short flags;char unknown70[0xA8];unsigned char active;};
extern "C" void fn_802701C0(RenderIndexResetSelf* self,void* other,RenderIndexResetObject* object) {
 if(self->flags&4){object->reset(other);object->clear();}
 self->active=0;
}
