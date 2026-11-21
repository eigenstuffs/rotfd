/* Original notification, virtual setup and string helpers; see docs/notes/game-early-simple-notification-helpers.md. */
struct Resource { char opaque[0x70];char field70,field71; };
struct Service { char opaque[0x94];Resource* resource94; };
struct Owner { char opaque[0xC];Service* serviceC; };
struct Globals { char opaque[0x110];void* context110; };
extern "C" Globals lbl_801E9D24;
extern "C" char lbl_8029EF38[];
extern "C" char fn_8007256C(Resource*);
extern "C" void fn_801FA014(void*,const char*,...);
extern "C" void fn_800AB29C(Owner* self) {
 Resource* resource=self->serviceC->resource94;
 resource->field70=0;
 if(!resource->field71 && fn_8007256C(resource))fn_801FA014(lbl_801E9D24.context110,lbl_8029EF38);
}
