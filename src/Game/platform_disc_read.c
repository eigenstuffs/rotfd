#include "Game/platform_disc_read.h"
int fn_8028EEEC(void*owner,void*fileInfo,void*buffer,int length,int offset){
 int result=0;
 if(!fileInfo)return 0;if(!buffer)return 0;if(!length)return 0;
 if(DVDReadAsyncPrio(fileInfo,buffer,length,offset,0,2))result=fn_8028EF84(owner);
 return result;
}
