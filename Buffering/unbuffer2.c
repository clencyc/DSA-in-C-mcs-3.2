#include <stdio.h>
#include <unistd.h>

int main() {
    int i;
    for (i=0; i<5; i++)
    {
        printf("i=%d\n", i);
        fflush(stdout); // force flushing of the buffer
        sleep(1);
    }
}