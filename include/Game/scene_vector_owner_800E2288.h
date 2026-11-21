typedef unsigned long SceneWord;

struct SceneVector {
    float x, y, z;
    SceneVector();
};

extern "C" {
extern const SceneVector game_vec3_zero;
extern const float lbl_80379788, lbl_80379784;
extern char lbl_802C867C[], lbl_802C85D0[], lbl_801EF5C8[];
void fn_80090084(void*);
void fn_8009009C(void*, int);
void fn_801EF610(void*, void*);
}

inline SceneVector::SceneVector() {
    x = game_vec3_zero.x;
    y = game_vec3_zero.y;
    z = game_vec3_zero.z;
}

struct SceneVectorRoot {
    void* vtable;
    unsigned char enabled;
    char unknown05[3];
    SceneVectorRoot() { fn_80090084(this); }
};

struct SceneVectorPrefix {
    SceneVectorRoot root;
    SceneWord first, second;

    SceneVectorPrefix(SceneWord a, SceneWord b) {
        root.vtable = lbl_802C867C;
        first = 0;
        second = 0;
        first = a;
        second = b;
    }
    ~SceneVectorPrefix() {
        root.vtable = lbl_802C867C;
        first = 0;
        second = 0;
        fn_8009009C(this, 0);
    }
};

struct Object_800E2288 {
    SceneVectorPrefix prefix;
    SceneWord value;
    float scale, phase, rate;
    SceneVector vector;

    Object_800E2288(SceneWord, SceneWord);
    ~Object_800E2288();
    static void operator delete(void* p) throw() {
        fn_801EF610(lbl_801EF5C8, p);
    }
};
