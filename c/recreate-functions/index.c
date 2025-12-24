#include <stdio.h>
#include "utils/strlen.h"


int main(void) {
    char sample_text[] = "Alan Turing inspired the Turing machine.";

    int len = my_strlen(sample_text);
    printf("%d\n", len);

    return 0;
}