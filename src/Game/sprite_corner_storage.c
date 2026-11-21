/* Four square corners and four UV corners filled by the original startup. */
struct SpriteCorner { float x, y; };
struct SpriteCorner lbl_8035D380[4];
struct SpriteCorner lbl_8035D360[4];

typedef char SpriteCornerSizeCheck[sizeof(struct SpriteCorner) == 8 ? 1 : -1];
typedef char SpriteCornerArraySizeCheck[sizeof(lbl_8035D360) == 32 ? 1 : -1];
typedef char SpriteUVArraySizeCheck[sizeof(lbl_8035D380) == 32 ? 1 : -1];
