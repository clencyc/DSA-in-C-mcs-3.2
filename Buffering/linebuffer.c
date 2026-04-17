#include <stdio.h>
#include <unistd.h>

int main() {
    // set line buffering
    setvbuf(stdout, NULL, _IOLBF, 0);
    printf("This will be printed immediatley when newline is encountered");
    sleep(5); // notice a delay before this appears

    //printf("\n");
    printf("This appears immediately\n");

    return 0;
}