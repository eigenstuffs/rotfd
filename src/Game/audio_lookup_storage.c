/* Audio startup fills 128 four-byte samples before acquiring its voices. */
float lbl_8035E758[128];

typedef char AudioLookupScalarSizeCheck[sizeof(float) == 4 ? 1 : -1];
typedef char AudioLookupStorageSizeCheck[sizeof(lbl_8035E758) == 512 ? 1 : -1];
