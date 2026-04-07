#include <stdio.h>
#include <stdlib.h>

/* ---------------------------------------------------
   Each node holds:
     - data  : the value stored
     - next  : pointer to the next node (NULL if last)
   --------------------------------------------------- */
struct Node {
    int data;
    struct Node* next;
};

/* --- Create a new node and return a pointer to it --- */
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data  = value;
    newNode->next  = NULL;
    return newNode;
}

/* --- Insert a node at the HEAD (beginning) --- */
void insertAtHead(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;   /* new node points to old head */
    *head = newNode;         /* head now points to new node */
}

/* --- Insert a node at the TAIL (end) --- */
void insertAtTail(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {     /* list is empty — new node becomes head */
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)   /* walk to the last node */
        temp = temp->next;

    temp->next = newNode;        /* link last node to new node */
}

/* --- Delete the first node that matches a value --- */
void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    /* check if head itself holds the value */
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Deleted: %d\n", value);
        return;
    }

    /* search for the value */
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {          /* value not found */
        printf("Value %d not found in list.\n", value);
        return;
    }

    prev->next = temp->next;     /* unlink the node */
    free(temp);
    printf("Deleted: %d\n", value);
}

/* --- Search for a value, return position (1-based) or -1 --- */
int search(struct Node* head, int value) {
    int position = 1;
    while (head != NULL) {
        if (head->data == value)
            return position;
        head = head->next;
        position++;
    }
    return -1;
}

/* --- Print the entire list --- */
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("HEAD -> ");
    while (head != NULL) {
        printf("[%d] -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* --- Free all nodes (avoid memory leaks) --- */
void freeList(struct Node** head) {
    struct Node* temp;
    while (*head != NULL) {
        temp  = *head;
        *head = (*head)->next;
        free(temp);
    }
}

/* ===================== MAIN ===================== */
int main() {
    struct Node* head = NULL;   /* empty list */

    printf("=== Linked List Demo ===\n\n");

    /* Build: 10 -> 20 -> 30 -> 40 */
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);
    printf("After inserting 10, 20, 30, 40 at tail:\n");
    printList(head);

    /* Insert at head */
    insertAtHead(&head, 5);
    printf("\nAfter inserting 5 at head:\n");
    printList(head);

    /* Delete a node */
    printf("\n");
    deleteNode(&head, 20);
    printf("After deleting 20:\n");
    printList(head);

    /* Search */
    printf("\nSearching for 30: ");
    int pos = search(head, 30);
    if (pos != -1)
        printf("found at position %d\n", pos);
    else
        printf("not found\n");

    printf("Searching for 99: ");
    pos = search(head, 99);
    if (pos != -1)
        printf("found at position %d\n", pos);
    else
        printf("not found\n");

    /* Cleanup */
    freeList(&head);
    printf("\nAll nodes freed. Done.\n");

    return 0;
}
