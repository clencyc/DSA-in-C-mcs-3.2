#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    FILE *fp;
    fp = fopen("fhandling.txt", "r");
    // if ((fp = fopen("fhandling.txt", "r")) == NULL) {
    //     printf("Error opening file!");
    //     exit(1);
    // }
    fscanf(fp, "%d", &num);
    printf("Value of n n=%d\n", num);
    fclose(fp);
    return 0;
}