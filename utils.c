#include "utils.h"

int16_t _sgn = 0;
clock_t _clk = 0;
void* wff = NULL;
int16_t _t_idx = 0;

int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}   // stackoverflow

