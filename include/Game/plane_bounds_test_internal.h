#ifndef GAME_PLANE_BOUNDS_TEST_INTERNAL_H
#define GAME_PLANE_BOUNDS_TEST_INTERNAL_H

struct PlaneBounds {float x[4],y[4],z[4],unknown30[4];float minimum,maximum;};
struct BoundsSphere {float x,y,z,radius;BoundsSphere(){}BoundsSphere(const BoundsSphere&s):x(s.x),y(s.y),z(s.z),radius(s.radius){}BoundsSphere&operator=(const BoundsSphere&s){x=s.x;y=s.y;z=s.z;radius=s.radius;return *this;}};

typedef char CheckBoundsSphere[sizeof(BoundsSphere)==16?1:-1];
typedef char CheckPlaneBounds[sizeof(PlaneBounds)==0x48?1:-1];
#endif
