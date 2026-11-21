#include "Game/platform_record_selection_internal.h"
extern "C" void fn_8026E940(PlatformArrays_802EA884*self,const PlatformRecordIndex&key){
 if(key.index>=0)fn_8026EB34(self,platformRecordAt(self,key.index),1);
}
