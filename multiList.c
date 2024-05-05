#include <stdio.h>
#include <stdlib.h>

typedef union {
    int marks;
    char grade;
    float percentage;
} Data;

typedef enum {
    INT,
    CHAR,
    FLOAT
} DataType;

struct Node {
    DataType type;
    Data data;
    struct Node* next;
};

struct Node* createNode(DataType type, Data data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->type = type;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        switch (head->type) {
            case INT:
                printf("%d -> ", head->data.marks);
                break;
            case CHAR:
                printf("%c -> ", head->data.grade);
                break;
            case FLOAT:
                printf("%.2f -> ", head->data.percentage);
                break;
        }
        head = head->next;
    }
    printf("NULL\n \n");
}

int main() {
    struct Node* head = createNode(INT, (Data){.marks = 423});
    head->next = createNode(CHAR, (Data){.grade = 'B'});
    head->next->next = createNode(FLOAT, (Data){.percentage = 84.6});

    printf("\nLinked List: \n");
    printList(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
