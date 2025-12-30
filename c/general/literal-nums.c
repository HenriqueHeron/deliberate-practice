#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_SIZE 150

struct Map {
    int key;
    char* value;
};

typedef struct Map Map;

#define MAP_LIST_SIZE 10 * sizeof(Map*)

Map* create_map(int key, char* value) {
    Map* map = malloc(sizeof(Map));

    if (map == NULL) {
        fprintf(stderr, "Failed to allocate memory to 'map'");
        return NULL;
    }

    map->key = key;
    // map->value = malloc(sizeof(strlen(value)));
    map->value = strdup(value);
    if (map->value == NULL) {
        fprintf(stderr, "Failed to allocate memory for map of key '%d' and value '%s'\n", key, value);
        goto cleanup;
    }

    return map;

cleanup:
    free(map->value);
    free(map);
    return NULL;
}

char* to_str(int num) {
    int right_digit = num % 10;
    int left_chunk = num / 10;

    // Extra byte for null terminator
    char* str = malloc(STR_SIZE + 1);
    if (str == NULL) {
        perror("Failed to allocate memory to 'str'");
        return NULL;
    }

    // Start from the end and move backwards as new words are written
    int written_idx = STR_SIZE;
    int loop_num = 0;

    while (right_digit != 0 || left_chunk != 0) {
        // Search map_list
        if (loop_num % 3 == 0) {
            
        }
        else if (loop_num % 3 == 1) {

        }
        else {

        }

        // written_idx = written_idx - new_str_len

        left_chunk = left_chunk / 10;
        right_digit = left_chunk % 10;
        loop_num++;
    }

    return str;
}

int main(void) {
    Map** map_list = malloc(MAP_LIST_SIZE);

    if (map_list == NULL) {
        perror("Failed to allocate memory to 'map_list'");
        return 1;
    }

    for (int i = 0; i < MAP_LIST_SIZE; i++) {
        Map* map;

        switch (i) {
        case 0:
            map = create_map(0, "zero");
            break;
        case 1:
            map = create_map(1, "one");
            break;
        case 2:
            map = create_map(2, "two");
            break;
        case 3:
            map = create_map(3, "three");
            break;
        case 4:
            map = create_map(4, "four");
            break;
        case 5:
            map = create_map(5, "five");
            break;
        case 6:
            map = create_map(6, "six");
            break;
        case 7:
            map = create_map(7, "seven");
            break;
        case 8:
            map = create_map(8, "eight");
            break;
        case 9:
            map = create_map(9, "nine");
            break;
        default:
            printf("Index digit is not a valid integer\n");
            goto cleanup_fail;
        }

        map_list[i] = map;
    }


    return 0;

cleanup_fail:
    for (int i = 0; i < MAP_LIST_SIZE; i++) {
        free(map_list[i]);
    }
    free(map_list);
    return 1;

cleanup_success:
    for (int i = 0; i < MAP_LIST_SIZE; i++) {
        free(map_list[i]);
    }
    free(map_list);

}