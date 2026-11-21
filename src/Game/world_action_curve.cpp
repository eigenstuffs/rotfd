#include "world_action_curve_internal.h"
WorldActionCurve_801F7560::~WorldActionCurve_801F7560(){
    for(int i=0;i<rows.count;++i){
        ActionRow& row=this->row(i);
        for(int j=0;j<row.entries.count;++j){
            ActionEntry& entry=row.entries.data[j];
            if(entry.type==17 || entry.type==18 || entry.type==19)
                ((ActionManager*)lbl_801E9D24.manager)->release(entry.index);
        }
    }
}
