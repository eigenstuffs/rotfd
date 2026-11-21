/* Original array and scalar routines with private observed layouts.
 * See docs/notes/game-scalar-early-more.md. */

struct Record {int key,group;char pad[0x44];signed char enabled;char tail[3];};

extern struct Record lbl_802F4208[300];

struct RecordSelection {char pad[0x188];int group;int indices[6];};

int fn_800B3E58(struct RecordSelection *object) {int found=0;int i;int index=object->indices[0];while(--index>=0)if(object->group==lbl_802F4208[index].group && lbl_802F4208[index].enabled==1){object->indices[0]=index;found=1;break;}for(i=1;i<6;++i){index=object->indices[i-1];while(++index<300)if(object->group==lbl_802F4208[index].group && lbl_802F4208[index].enabled==1){object->indices[i]=index;break;}}return found;}

int fn_800B3F10(struct RecordSelection *object) {int found=0;int i;int index=object->indices[5];while(++index<300)if(object->group==lbl_802F4208[index].group && lbl_802F4208[index].enabled==1){object->indices[5]=index;found=1;break;}for(i=4;i>=0;--i){index=object->indices[i+1];while(--index>=0)if(object->group==lbl_802F4208[index].group && lbl_802F4208[index].enabled==1){object->indices[i]=index;break;}}return found;}
