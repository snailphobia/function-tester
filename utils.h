#ifndef DEF_UT
#define DEF_UT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#define S1 32
#define S2 256
#define S3 1024

typedef struct _Node {
    void* val;
    struct _Node* next;
} Node;

typedef struct _List {
    uint16_t nmb;
    Node* head;
} List;

int is_regular_file(const char *path);

#endif
