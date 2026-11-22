extern void fn_801E2E94(void *,int,int,int,int);
void fn_801E1658(void *object,int mode)  {
    switch(mode) {
        case 1: *((signed char *)object+0x214)=1;
        fn_801E2E94(object,0,0,*(int *)((char *)object+0x218),*(int *)((char *)object+0x21c));
        break;
        case 2:  {
            int halfHeight;
            *((signed char *)object+0x214)=2;
            halfHeight=*(int *)((char *)object+0x21c)>>1;
            fn_801E2E94(object,0,0,*(int *)((char *)object+0x218),halfHeight-1);
            fn_801E2E94((char *)object+0x4c,0,halfHeight+1,*(int *)((char *)object+0x218),halfHeight-1);
            break;
        }
        case 3:  {
            int halfWidth,halfHeight;
            *((signed char *)object+0x214)=3;
            halfWidth=*(int *)((char *)object+0x218)>>1;
            halfHeight=*(int *)((char *)object+0x21c)>>1;
            fn_801E2E94(object,0,0,halfWidth-1,halfHeight-1);
            fn_801E2E94((char *)object+0x4c,halfWidth+1,0,halfWidth-1,halfHeight-1);
            fn_801E2E94((char *)object+0x98,halfWidth-(halfWidth>>1),halfHeight+1,halfWidth,halfHeight-1);
            break;
        }
        case 4:  {
            int halfWidth,halfHeight;
            *((signed char *)object+0x214)=4;
            halfWidth=*(int *)((char *)object+0x218)>>1;
            halfHeight=*(int *)((char *)object+0x21c)>>1;
            fn_801E2E94(object,0,0,halfWidth-1,halfHeight-1);
            fn_801E2E94((char *)object+0x4c,halfWidth+1,0,halfWidth-1,halfHeight-1);
            fn_801E2E94((char *)object+0x98,0,halfHeight+1,halfWidth-1,halfHeight-1);
            fn_801E2E94((char *)object+0xe4,halfWidth+1,halfHeight+1,halfWidth-1,halfHeight-1);
            break;
        }
    }
    {
        char *record=(char *)object;
        int i;
        for(i=0;i<*((signed char *)object+0x214);record+=0x4c,++i)*(void **)(record+0x48)=object;
    }
}
