// Native variadic formatting wrapper. See the unit note.
typedef struct {
    char gpr, fpr, reserved[2];
    char* input_arg_area;
    char* reg_save_area;
} FormatArguments[1];
extern "C" {
void __builtin_va_info(void*);
int vsprintf(char*, const char*, FormatArguments);
}
extern "C" void fn_801BA714(char* out, const char* format, ...) {
    FormatArguments args;
    __builtin_va_info(&args);
    vsprintf(out, format, args);
}
