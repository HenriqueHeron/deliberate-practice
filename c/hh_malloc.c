#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>
#include <string.h>

void* malloc(size_t size) {
    void* p = sbrk(0);
    void* request = sbrk(size);

    if (request == -1) {
        perror("sbrk failed");
        return NULL;
    } else {
        assert(request == p);
        return p;
    }
}

int main(void) {
    char* text = malloc(3);
    if (text == NULL) {
        return 1;
    }

    char* text2 = "ab";

    for (int i = 0; i < 2; i++) {
        text[i] = text2[i];
    }
    
    text[3] = '\0';

    printf("%s\n", text);

    return 0;
}