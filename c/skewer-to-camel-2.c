#include <stdio.h>
#include <ctype.h>

void skewer_to_camel_inplace(char* text) {
    int i = 0, j = 0;

    while (text[i] != '\0') {
        if (text[i] == '-') {
            i++;
            text[j] = toupper(text[i]);
        } else {
            text[j] = text[i];
        }

        i++;
        j++;
    }

    text[j] = '\0';
}



void main(void) {
    char sample_skewer_text[] = "i-want-to-be-converted";

    skewer_to_camel_inplace(sample_skewer_text);

    printf("%s\n", sample_skewer_text);

}