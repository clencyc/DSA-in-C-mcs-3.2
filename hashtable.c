#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HT_SIZE 7

struct HTNode {
    int key;
    int value;
    struct HTNode* next;
};

struct HTNode* table[HT_SIZE];

void htInit() { memset(table, 0, sizeof(table)); }

int hashFn(int key) { return abs(key) % HT_SIZE; }

void htInsert(int key, int value) {
    int idx = hashFn(key);
    struct HTNode* node = (struct HTNode*)malloc(sizeof(struct HTNode));
    node->key   = key;
    node->value = value;
    node->next  = table[idx];
    table[idx]  = node;
    printf("Inserted key=%d value=%d → bucket %d\n", key, value, idx);
}

void htSearch(int key) {
    int idx = hashFn(key);
    struct HTNode* cur = table[idx];
    while (cur) {
        if (cur->key == key) {
            printf("Found key=%d → value=%d\n", key, cur->value);
            return;
        }
        cur = cur->next;
    }
    printf("Key %d not found\n", key);
}

void htDelete(int key) {
    int idx = hashFn(key);
    struct HTNode* cur  = table[idx];
    struct HTNode* prev = NULL;
    while (cur) {
        if (cur->key == key) {
            if (prev) prev->next = cur->next;
            else      table[idx] = cur->next;
            free(cur);
            printf("Deleted key=%d\n", key);
            return;
        }
        prev = cur;
        cur  = cur->next;
    }
    printf("Key %d not found\n", key);
}

void printHT() {
    printf("Hash Table:\n");
    for (int i = 0; i < HT_SIZE; i++) {
        printf("  [%d]: ", i);
        struct HTNode* cur = table[i];
        while (cur) { printf("(%d,%d) -> ", cur->key, cur->value); cur = cur->next; }
        printf("NULL\n");
    }
}

int main() {
    htInit();

    htInsert(12, 100);
    htInsert(25, 200);
    htInsert(19, 300);
    htInsert(5,  400);
    printf("\n");
    printHT();
    printf("\n");
    htSearch(25);
    htSearch(99);
    printf("\n");
    htDelete(19);
    printHT();

    return 0;
}
