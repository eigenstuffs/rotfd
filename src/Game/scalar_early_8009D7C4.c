static inline void add3(float *out,float x,float y,float z) {out[0]+=x;out[1]+=y;out[2]+=z;}

void fn_8009D7C4(float *object,const float *source) {float scale;object[0x39c/4]=source[0];object[0x3a0/4]=source[1];object[0x3a4/4]=source[2];scale=object[0x36c/4];add3(object+0x358/4,source[0]*scale,source[1]*scale,source[2]*scale);}
