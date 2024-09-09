#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;             
    struct Node* next;    
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Huh! Memory allocation. \n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        // Liste boşsa
        *head = newNode;
        newNode->next = *head;  // Dairesel yapı
    } else {
        // Liste doluysa
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;  // Dairesel yapı
    }
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Empty list!\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}


void deleteNode(Node** head, int key) {
    if (*head == NULL) {
        return;
    }

    Node *temp = *head, *prev = NULL;

    // Eğer silinecek düğüm baş düğümse
    if (temp->data == key) {
        if (temp->next == *head) {
            // Tek düğüm varsa
            free(temp);
            *head = NULL;
            return;
        } else {
            // Birden fazla düğüm varsa
            prev = *head;
            while (prev->next != *head) {
                prev = prev->next;
            }
            prev->next = temp->next;
            *head = temp->next;
            free(temp);
            return;
        }
    }

    // Diğer düğümleri arama
    prev = temp;
    temp = temp->next;
    while (temp != *head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->data == key) {
        prev->next = temp->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;  // Liste başı

    
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Listeyi yazdırma
    printf("List: ");
    printList(head);

    // Bir düğüm silme
    deleteNode(&head, 20);

    // Güncellenmiş listeyi yazdırma
    printf("Updated liste: ");
    printList(head);

    // Belleği serbest bırakma
    // Listeyi boşaltma
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        if (head == temp) { // Tek düğüm kaldıysa
            free(temp);
            break;
        }
        free(temp);
    }

    return 0;
}