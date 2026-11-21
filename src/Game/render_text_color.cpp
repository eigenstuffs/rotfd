/* Font color conversion and integer-aligned text position. */
struct TextColorVector {float x,y;};
struct TextColorInput {float r,g,b;};
struct TextColorFont { unsigned char r,g,b; };
struct TextColorOwner { char unknown00[0x9DC]; TextColorFont* font; };
extern "C" { extern const float lbl_8037B7C8; void fn_8027B790(TextColorFont*,float,float,const char*); }
extern "C" void fn_8027DBA8(TextColorOwner* self,const TextColorVector* position,const char* text,const TextColorInput* color) {
 TextColorFont* font=self->font;
 unsigned char red=lbl_8037B7C8*color->r;
 unsigned char blue=lbl_8037B7C8*color->b;
 unsigned char green=lbl_8037B7C8*color->g;
 font->r=red; font->g=green; font->b=blue;
 fn_8027B790(self->font,(int)position->x,(int)position->y,text);
}
