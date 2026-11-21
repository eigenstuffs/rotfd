/* Original GLOBAL startup entry; the original ctor record remains external. */
struct V {float x,y;};
extern "C" {
extern const float lbl_8037B814,lbl_8037B818,lbl_8037B81C,lbl_8037B820;
extern V lbl_8035D360[4],lbl_8035D380[4];
void fn_80283E5C() {
const float a=lbl_8037B81C;
const float b=lbl_8037B820;
const float c=lbl_8037B818;
const float d=lbl_8037B814;
lbl_8035D360[0].x=a;lbl_8035D360[0].y=a;
lbl_8035D360[1].x=b;lbl_8035D360[1].y=a;
lbl_8035D360[2].x=b;lbl_8035D360[2].y=b;
lbl_8035D360[3].x=a;lbl_8035D360[3].y=b;
lbl_8035D380[0].x=c;lbl_8035D380[0].y=d;
lbl_8035D380[1].x=d;lbl_8035D380[1].y=d;
lbl_8035D380[2].x=d;lbl_8035D380[2].y=c;
lbl_8035D380[3].x=c;lbl_8035D380[3].y=c;
}

}
