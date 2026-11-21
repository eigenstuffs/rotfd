/* Original scalar distance and query leaves; see docs/notes/game-scalar-distance-query-leafs.md. */
extern "C"{double pow(double,double);extern const float lbl_80378A84;}extern "C"void fn_8007D45C(const float*start,const float*target,float*result,float base,float elapsed){float scale=pow(base,elapsed/lbl_80378A84);*result=*target-(*target-*start)/scale;}
