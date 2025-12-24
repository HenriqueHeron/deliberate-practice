unsigned int my_strlen(char* text) {
    unsigned int i = 0;

    for (int c = 0; text[c] != '\0'; c++) {
        i++;
    }

    return i;
}