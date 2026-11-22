static inline void set3(float *out,float x,float y,float z) {out[0]=x;out[1]=y;out[2]=z;}

void fn_801D7EFC(float *out,const float *source,float scale) {float x=source[0]*scale;float y=source[1]*scale;out[0]=x;out[1]=y;}

void fn_801D7F18(float *out,const float *left,const float *right) {float x=left[0]-right[0];float y=left[1]-right[1];out[0]=x;out[1]=y;}

void fn_801D7F3C(float *object,const float *other) {object[0]+=other[0];object[1]+=other[1];object[2]+=other[2];}

void fn_801D7F70(float *out,const float *left,const float *right) {set3(out,left[0]-right[0],left[1]-right[1],left[2]-right[2]);}

void fn_801D7FA4(float *out,const float *source,float scale) {set3(out,source[0]*scale,source[1]*scale,source[2]*scale);}

void fn_801D7FCC(float *out,const float *source) {set3(out,-source[0],-source[1],-source[2]);}

void fn_801D7FF4(float *out,const float *left,const float *right) {float x=left[0]+right[0];float y=left[1]+right[1];out[0]=x;out[1]=y;}

void fn_801D8018(float *object,const float *source) {object[0]=source[0];object[1]=source[1];object[2]=source[2];}

void fn_801D8034(float *out,const float *left,const float *right) {set3(out,left[0]+right[0],left[1]+right[1],left[2]+right[2]);}
