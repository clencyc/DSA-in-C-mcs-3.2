#include <stdio.h>

int main() {
    char old_name[] = "file_new.txt";
    char new_name[] = "new_file1.txt";
    int value;

    value = rename(old_name, new_name);

    if(!value) {
        printf("File name changed successfully");
    } else {
        perror("Error");
    }

    return 0;
}
