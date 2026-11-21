/* Original scalar flag and fixed-record operations; see docs/notes/game-engine-scalar-last.md. */
struct Record{int unknown00,key04;char unknown08[0x4C-8];signed char enabled4C;char unknown4D[3];};extern "C" Record lbl_802F4208[300];
struct Owner{char unknown00[0x188];int key188;int results18C[6];};
extern "C" void fn_800B3FC8(Owner*self){int j=0;for(int i=0;i<6;i++)self->results18C[i]=-1;for(;j<300;j++){if(self->key188==lbl_802F4208[j].key04&&lbl_802F4208[j].enabled4C==1){self->results18C[0]=j;break;}}for(int i=1;i<6;i++){int j=self->results18C[i-1];while(++j<300){if(self->key188==lbl_802F4208[j].key04&&lbl_802F4208[j].enabled4C==1){self->results18C[i]=j;break;}}}}
