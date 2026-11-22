struct View {
    char pad[0x18];
    float height,aspect;
    char tail[0x2c];
};
struct Object{
    struct View views[4];
    char pad130[0xe4];
    signed char count,selected;
    char pad216[0x52];
    float height,width;
    int centerX,centerY;
};
extern void fn_801E2E70(struct View *,int *,int *,int *,int *);
extern void fn_801E23A0(struct View *);
void fn_801E15A4(struct Object *self,int index){
    if(index!=-1){
        int x,y,w,h;
        struct View *view=&self->views[index];
        self->selected=index;
        fn_801E2E70(view,&x,&y,&w,&h);
        fn_801E23A0(view);
        self->height=view->height;
        self->width=view->height*view->aspect;
        self->centerX=w/2+x;
        self->centerY=h/2+y;
    }
}
