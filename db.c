#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *dir = "/var/lib/db/";

char *get(const char *key)
{
    char path[strlen(dir) + strlen(key)];
    strcpy(path, dir);
    strcat(path, key);
    FILE *fp = fopen(path, "r");

    if (fp == NULL) {
        fprintf(stderr, "Error: No value with key: %s\n", key);
        exit(1);
    }

    char ch;

    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);

    fclose(fp);
}

void put(const char *key, const char *value)
{
    char path[strlen(dir) + strlen(key)];
    strcpy(path, dir);
    strcat(path, key);
    FILE *f = fopen(path, "w");

    if (f == NULL) {
        fprintf(stderr, "Error writing value!\n");
        exit(1);
    }

    fprintf(f, "%s", value);

    fclose(f);
}

void delete(const char *key)
{
    char path[strlen(dir) + strlen(key)];
    strcpy(path, dir);
    strcat(path, key);
    int del = remove(path);
    
    if (!del)
      printf("Successfully deleted entry: %s\n", key);
    else {
        fprintf(stderr, "Could not delete key: %s\n", key);
        exit(1);
    }
}

int main(int argc, char const *argv[])
{

    if (argc < 3) {
        return 1;
    }

    if (!strcmp(argv[1], "get")) {
        get(argv[2]);
    }

    else if (!strcmp(argv[1], "put")) {
        if (argc < 4) {
            fprintf(stderr, "Error: no value supplied\n");
            exit(1);
        }

        put(argv[2], argv[3]);
    }

    else if (!strcmp(argv[1], "delete")) {
        delete(argv[2]);
    }

    else {
        fprintf(stderr, "Error: Unsupported option: %s\n", argv[1]);
    }

    return 0;
}
