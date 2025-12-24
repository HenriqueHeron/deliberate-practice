#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_valid_str(char* str) {
    size_t len = strlen(str);
    if (str[len - 1] == '-' || str[0] == '-') {
        fprintf(stderr, "Invalid skewer-case string: %s\n", str);
        return false;
    }
    return true;
}

char* skewer_to_camel(char* text) {
    if (!is_valid_str(text)) return NULL;

    size_t len = strlen(text);
    char* camel_str = malloc(len + 1);
    int offset = 0;

    if (camel_str == NULL) {
        perror("Failed to allocate heap memory to 'camel_str'");
        return NULL;
    }

    for (int i = 0; text[i] != '\0'; i++) {
        if (i + offset >= len) {
            break;
        }

        if (text[i] == '-') {
            camel_str[i + offset] = toupper(text[i + 1]);
            i++;
            offset--;
            continue;
        }
        camel_str[i + offset] = text[i];
    }

    camel_str[len + offset] = '\0';

    return camel_str;
}

void skewer_to_camel_inplace(char* text) {
    unsigned int i = 0, j = 0;

    while (text[i] != '\0') {
        if (text[i] == '-') {
            do {
                i++;
            } while (text[i] == '-');
            text[j] = toupper(text[i]);
        } else {
            text[j] = text[i];
        }
        i++;
        j++;
    }

    text[j] = '\0';
}

int main(void) {
    char sample_skewer_text[] = "please-convert-me";
    skewer_to_camel_inplace(sample_skewer_text);
    printf("%s\n", sample_skewer_text);

    return 0;
}