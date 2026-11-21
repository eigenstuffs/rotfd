/* fn_801E01A8: ray (segment) against an oriented unit box.
   Transforms the eight cube corners (lbl_80340AC0) by the box matrix while
   counting, per axis, corners that lie wholly beyond both segment ends;
   rejects the box when all eight are on one side of any axis, then tests the
   six quadrilateral faces (index table lbl_802EAA10) with fn_801B70DC and
   keeps the first face hit that improves the result.  Same original TU and
   flags as sphere_box_hit_collect_801dfe90 (-O4,p, no exceptions).
   Local declaration order (hit, end, points, counters, i, face) and the
   face increment before the call are what reproduce the original register
   allocation. */
typedef unsigned long long CollisionMask;

struct Point3 {
    float x, y, z;
    Point3() {}
    Point3(float a, float b, float c) : x(a), y(b), z(c) {}
    Point3(const Point3& p) : x(p.x), y(p.y), z(p.z) {}
    Point3 operator*(float scale) const { return Point3(x * scale, y * scale, z * scale); }
    Point3 operator+(const Point3& p) const { return Point3(x + p.x, y + p.y, z + p.z); }
    Point3& operator=(const Point3& p) {
        x = p.x; y = p.y; z = p.z;
        return *this;
    }
};

struct Matrix4 {
    float m[4][4];
    Point3 transform(const Point3& p) const {
        float x = m[3][0] + (m[0][0] * p.x + m[1][0] * p.y + m[2][0] * p.z);
        float y = m[3][1] + (m[0][1] * p.x + m[1][1] * p.y + m[2][1] * p.z);
        float z = m[3][2] + (m[0][2] * p.x + m[1][2] * p.y + m[2][2] * p.z);
        return Point3(x, y, z);
    }
};

struct Ray {
    Point3 origin;
    float distance;
    Point3 direction;
};

struct Hit {
    Point3 point;
    float distance;
    Point3 normal;
    char unknown1C[0x30 - 0x1C];
};

struct Result {
    Point3 point;
    float distance;
    Point3 normal;
    char unknown1C[0x28 - 0x1C];
    CollisionMask flags;
    unsigned object, other, extra;
    signed char valid;
};

extern "C" {
extern Point3 lbl_80340AC0[8];
extern const int lbl_802EAA10[6][4];
signed char fn_801B70DC(Ray*, Point3, Point3, Point3, Point3, Hit*);
}

extern "C" signed char fn_801E01A8(Ray* self, const Matrix4* matrix,
                                   Result* result, CollisionMask flags)
{
    Hit hit;
    Point3 end = self->origin + self->direction * self->distance;
    Point3 points[8];
    int x = 0, y = 0, z = 0;
    int i;
    const int (*face)[4] = lbl_802EAA10;
    for (i = 0; i < 8; ++i) {
        points[i] = matrix->transform(lbl_80340AC0[i]);
        if (self->origin.x > points[i].x && end.x > points[i].x) ++x;
        else if (self->origin.x < points[i].x && end.x < points[i].x) --x;
        if (self->origin.y > points[i].y && end.y > points[i].y) ++y;
        else if (self->origin.y < points[i].y && end.y < points[i].y) --y;
        if (self->origin.z > points[i].z && end.z > points[i].z) ++z;
        else if (self->origin.z < points[i].z && end.z < points[i].z) --z;
    }
    if (x == -8 || x == 8 || z == -8 || z == 8 || y == -8 || y == 8)
        return 0;
    for (i = 0; i < 6; ++i) {
        Point3 a = points[(*face)[0]];
        Point3 b = points[(*face)[1]];
        Point3 c = points[(*face)[2]];
        Point3 d = points[(*face)[3]];
        ++face;
        if (fn_801B70DC(self, a, b, c, d, &hit)) {
            if (!result->valid || hit.distance < result->distance) {
                result->valid = 1;
                result->distance = hit.distance;
                result->point = hit.point;
                result->normal = hit.normal;
                result->flags = flags;
                return 1;
            }
        }
    }
    return 0;
}
