/* Projected quad rejection reconstruction; see docs/notes/game-projected-quad-test.md. */
struct ProjectedQuadVector {
    float x, y, z;
};

struct ProjectedQuadVertex {
    float x, y, z, w;
};

struct ProjectedQuadQuery {
    ProjectedQuadVector position;
    float distance;
    ProjectedQuadVector direction;
    float unknown1C;
};

struct ProjectedQuadResult {
    ProjectedQuadVector position;
    float distance;
    ProjectedQuadVector normal;
    char unknown1C[20];
};

extern "C" const float lbl_8037A250;
extern "C" signed char fn_80279558(ProjectedQuadQuery*, const ProjectedQuadVertex*,
                                    const ProjectedQuadVertex*, const ProjectedQuadVertex*,
                                    const ProjectedQuadVertex*, const ProjectedQuadVertex*,
                                    ProjectedQuadResult*);
extern "C" signed char fn_801B5D50(ProjectedQuadQuery* self,
                                    const ProjectedQuadVertex* a,
                                    const ProjectedQuadVertex* b,
                                    const ProjectedQuadVertex* c,
                                    const ProjectedQuadVertex* d,
                                    const ProjectedQuadVertex* normal,
                                    ProjectedQuadResult* out) {
    if (self->direction.y != lbl_8037A250) {
        if (self->position.x > a->x &&
            self->position.x > b->x &&
            self->position.x > c->x &&
            self->position.x > d->x) {
            return 0;
        }
        if (self->position.x < a->x &&
            self->position.x < b->x &&
            self->position.x < c->x &&
            self->position.x < d->x) {
            return 0;
        }
        if (self->position.z > a->z &&
            self->position.z > b->z &&
            self->position.z > c->z &&
            self->position.z > d->z) {
            return 0;
        }
        if (self->position.z < a->z &&
            self->position.z < b->z &&
            self->position.z < c->z &&
            self->position.z < d->z) {
            return 0;
        }
    } else if (self->direction.x != lbl_8037A250) {
        if (self->position.y > a->y &&
            self->position.y > b->y &&
            self->position.y > c->y &&
            self->position.y > d->y) {
            return 0;
        }
        if (self->position.y < a->y &&
            self->position.y < b->y &&
            self->position.y < c->y &&
            self->position.y < d->y) {
            return 0;
        }
        if (self->position.z > a->z &&
            self->position.z > b->z &&
            self->position.z > c->z &&
            self->position.z > d->z) {
            return 0;
        }
        if (self->position.z < a->z &&
            self->position.z < b->z &&
            self->position.z < c->z &&
            self->position.z < d->z) {
            return 0;
        }
    } else {
        if (self->position.x > a->x &&
            self->position.x > b->x &&
            self->position.x > c->x &&
            self->position.x > d->x) {
            return 0;
        }
        if (self->position.x < a->x &&
            self->position.x < b->x &&
            self->position.x < c->x &&
            self->position.x < d->x) {
            return 0;
        }
        if (self->position.y > a->y &&
            self->position.y > b->y &&
            self->position.y > c->y &&
            self->position.y > d->y) {
            return 0;
        }
        if (self->position.y < a->y &&
            self->position.y < b->y &&
            self->position.y < c->y &&
            self->position.y < d->y) {
            return 0;
        }
    }
    return fn_80279558(self, a, b, c, d, normal, out);
}
