/* Original engine scalar setup and forwarding with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-scalar-setup.md. */
extern "C" void fn_8021F518(void*, const void*, int);
extern "C" int fn_80027DD0(void* self, void* unused, const void* value) {
    fn_8021F518(self, value, 0);
    return 0;
}
