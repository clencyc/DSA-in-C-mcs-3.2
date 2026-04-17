#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("test.txt", "r");

    if(fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    printf("%ld", ftell(fp));

    fclose(fp);
    return 0;
}