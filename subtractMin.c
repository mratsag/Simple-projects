#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Bağıl listeye yeni düğüm ekler
void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Bağıl listeyi yazdırır
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// En küçük değeri bulur
int findMin(struct Node *head) {
    int min = head->data;
    while (head != NULL) {
        if (head->data < min) {
            min = head->data;
        }
        head = head->next;
    }
    return min;
}

// En küçük değeri çıkararak yeni değerleri hesaplar
void subtractMin(struct Node *head) {
    int min = findMin(head);
    struct Node *current = head;
    while (current != NULL) {
        current->data -= min;
        current = current->next;
    }
}

int main() {
    struct Node *head = NULL;
    push(&head, 3);
    push(&head, 5);
    push(&head, 4);
    push(&head, 9);
    push(&head, 2);
    push(&head, 7);
    push(&head, 4);
    push(&head, 8);

    printf("Original List: ");
    printList(head);

    subtractMin(head);

    printf("Modified List: ");
    printList(head);

    return 0;
}
