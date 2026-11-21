/* Scalar startup storage preceding main's translation-unit BSS. The reset
 * thread, its stack and DVD read buffer (0x8033E748..0x80340A90) belong to
 * main (src/Game/game_main_801EC128.cpp); the two objects after them live in
 * engine_reset_typed_storage_80340A90.cpp. */
extern "C" {
 float lbl_8033E738[4];
}
