#include <stdio.h>
#include <stdlib.h>

int main_list(void)
{
    // 1. Initial allocation for 3 integers
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // 2. Resize the memory safely to hold 4 integers
    // realloc handles copying old data to the new location for you
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list); // If realloc fails, manually free the original block
        return 1;
    }

    // Update list to point to the new (potentially moved) memory block
    list = tmp;

    // 3. Now it is safe to add the 4th element
    list[3] = 4;

    // 4. Print all 4 elements
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // 5. Always free the memory when finished to avoid leaks
    free(list);

    return 0;
}
