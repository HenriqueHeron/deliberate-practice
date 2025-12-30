#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

FILE* fopen(const char* filename, const char* mode) {
    int open_flag = -1;
    if (strcmp(mode, "r") == 0) {
        open_flag = O_RDONLY;
    }


    if (open_flag == -1) {
        fprintf(stderr, "Invalid mode: '%s'", mode);
        return NULL;
    }
    
    int fd = open(filename, open_flag);

    if (fd == -1) {
        fprintf(stderr, "Failed to open file '%s'\n", filename);
        return NULL;
    }

}