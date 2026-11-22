#pragma fp_contract on
struct Point{float x,y,z;};extern "C"float fn_80284DD8(float);extern "C"float fn_8005EC08(const Point*a,const Point*b){return fn_80284DD8(a->x*b->x+a->y*b->y+a->z*b->z);}
