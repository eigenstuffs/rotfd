/* Render display list call; see docs/notes/game-render-display-list-call.md. */
struct SavedVertexDescriptor {int attribute,type;};
struct DisplayListView {char unknown00[0x110];void*displayList;unsigned long present,bytes;};
struct DisplayVertexOwner {char unknown00[0xBDC];void*positions;};
extern "C" {
void GXGetVtxDescv(SavedVertexDescriptor*);
void GXClearVtxDesc();void GXSetVtxDesc(int,int);void PPCSync();void GXInvalidateVtxCache();
void GXSetArray(int,const void*,unsigned char);void GXCallDisplayList(const void*,unsigned long);void GXDrawDone();void GXSetVtxDescv(const SavedVertexDescriptor*);
}
extern "C" void fn_802828FC(DisplayListView*self,DisplayVertexOwner*owner){
 SavedVertexDescriptor saved[28];GXGetVtxDescv(saved);GXClearVtxDesc();GXSetVtxDesc(9,3);PPCSync();GXInvalidateVtxCache();GXSetArray(9,owner->positions,12);
 if(self->displayList&&self->present)GXCallDisplayList(self->displayList,self->bytes);
 GXDrawDone();GXSetVtxDescv(saved);
}
