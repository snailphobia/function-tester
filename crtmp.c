#include "utils.h"

extern volatile int16_t _sgn;
int32_t main(int32_t argc, char* argv[]) {
    FILE * out = fopen("out_rep.txt", "w+");

    if (!out)
        exit(1);
    char* file_cr = calloc(S2, sizeof(char));
    for (int i = 1; i < argc; i++) {
        _sgn = snprintf(file_cr, S2, "cat %s >> temp%d.c", argv[i], i);
        if (is_regular_file(argv[i]))
            _sgn = system(file_cr);
        else fprintf(out, "file not found: %s\n", argv[i]);
        _sgn = snprintf(file_cr, S2, "%c", '\0');
    }

    _sgn = system("make link");
    _sgn = system("./exec");
    
    for (int i = 1; i < argc; i++) {
        char* fname = calloc(S2, sizeof(char));
        _sgn = snprintf(fname, S2, "temp%d.c", i);
        _sgn = snprintf(file_cr, S2, "rm -f %s", fname);
        if (is_regular_file(fname))
            _sgn = system(file_cr);
        _sgn = snprintf(file_cr, S2, "%c", '\0');
        free(fname);
    }

    free(file_cr);
    fclose(out);
    return 0x0;
}