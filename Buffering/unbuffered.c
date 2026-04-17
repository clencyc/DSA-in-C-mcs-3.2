#include <stdio.h>
#include <unistd.h>

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("This appears immediately");

    sleep(2);
    printf(" and so does this \n");
    return 0;
}
