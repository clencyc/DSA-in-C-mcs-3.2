#include <stdio.h>
#include <stdlib.h>


// array - fixed size list of something
// array of 5 ints which tells the compiler to allocate an array of 5 integers
// 5 x 4 = 20 bytes
// read, write, delete
// arrays are limiting because what if you need more than 5?
int main1(void)
{
    int values[5];

    return 0;
}

// assign more values
int main2(void)
{
    int values[5000];
    values[2] = 45;
    int xy = values[2];

    return 0;
}

// give more memory spaces - which is memory inefficient
int main3(void)
{
    int *values = malloc(40);
    values[2] = 45;
    int x = values[2];
    values = realloc(values, 2000*sizeof(int));
    x = values[600];

    return 0;
}

// adding and deleting things in an array might be stressful that is why we have linked lists

