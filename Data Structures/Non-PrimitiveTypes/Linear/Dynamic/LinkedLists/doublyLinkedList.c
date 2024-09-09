#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;

} Node;

Node* createNode(int data){ //creating new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Huh! Memory allocation error!\n");
        exit(1);
    }
    
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

// Liste başına düğüm ekleme
void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void printListForward(Node* head){
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printListBackward(Node* head){
    Node* temp = head;
    if (temp == NULL)
    {
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
    
}

void deleteNode(Node** head, Node* delNode){
    if (*head == NULL || delNode == NULL)
    {
        return;
    }
    if (*head == delNode)
    {
        *head = delNode->next;
    }
    if (delNode->next != NULL)
    {
        delNode->next->prev = delNode->prev;
    }
    if (delNode->prev != NULL)
    {
        delNode->prev->next = delNode->next;
    }
    free(delNode);

}

int main()
{
    Node* head = NULL;

    insertAtHead(&head, 1);
    insertAtHead(&head, 2);
    insertAtHead(&head, 3);

    printf("printForward: ");
    printListForward(head);

    printf("printBackward: ");
    printListBackward(head);

    Node* temp = head->next;
    deleteNode(&head, temp);

    printf("Updated list: ");
    printListForward(head);

    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
    
}