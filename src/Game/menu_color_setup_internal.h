struct MenuSetupColor3 {
    float x, y, z;
    void set(float a, float b, float c) { x=a; y=b; z=c; }
    void scale(float value) { set(x*value,y*value,z*value); }
};
struct Menu2DColorSetup {
    char unknown00[0x8C];
    MenuSetupColor3 start,end,startSelect,endSelect,grey;
    float greyAlpha;
};
struct Menu3DColorSetup {
    char unknown00[0x80];
    MenuSetupColor3 start,end,startSelect,endSelect,grey;
    float greyAlpha;
};
