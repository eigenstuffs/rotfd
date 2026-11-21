// Connectivity of the eight native box corners: twelve edges and six faces.
struct BoxTopologyEdge802EA9B0 {int first,second;};
struct BoxTopologyFace802EAA10 {int first,second,third,fourth;};
extern "C" {
BoxTopologyEdge802EA9B0 lbl_802EA9B0[12]={
 {0,1},{1,2},{2,3},{3,0},{4,5},{5,6},
 {6,7},{7,4},{0,4},{1,5},{2,6},{3,7}
};
BoxTopologyFace802EAA10 lbl_802EAA10[6]={
 {0,1,2,3},{0,4,5,1},{0,3,7,4},
 {6,5,4,7},{6,7,3,2},{6,2,1,5}
};
}
