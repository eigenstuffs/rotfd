namespace ObjectLayout_800969F0 {
struct Prefix {unsigned long unknown00[2];};
struct Primary:Prefix {virtual ~Primary();char unknown0C[0x30C];};
struct Secondary {virtual ~Secondary();char unknown04[0x28];};
}
struct Object_800969F0:ObjectLayout_800969F0::Primary,ObjectLayout_800969F0::Secondary {
 virtual void accumulate_800970F8(const float*source);
 virtual ~Object_800969F0();
};
static inline void add3(float *out,float x,float y,float z) {out[0]+=x;out[1]+=y;out[2]+=z;}
void Object_800969F0::accumulate_800970F8(const float*source){float*object=(float*)this;float scale=object[221];add3(object+0x358/4,source[0]*scale,source[1]*scale,source[2]*scale);}
typedef char CheckPrimarySize[(sizeof(ObjectLayout_800969F0::Primary)==0x318)?1:-1];
