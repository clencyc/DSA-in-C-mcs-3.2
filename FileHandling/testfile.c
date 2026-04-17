#include <stdio.h>
#include <stdlib.h>

int main() {
   // int num;
    FILE *fp;
    fp = fopen("test.txt", "w");

    fprintf(fp, "Mtu mahali pale anakuita. tunaenda kazi. Jiangalie");
    fclose(fp);
    return 0;
}