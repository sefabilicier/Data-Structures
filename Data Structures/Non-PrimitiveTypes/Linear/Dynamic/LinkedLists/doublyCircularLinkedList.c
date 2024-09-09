#include <stdio.h>
#include <stdlib.h>

// Düğüm yapısı
typedef struct Node {
    int data;             // Veri
    struct Node* next;    // Bir sonraki düğüme işaretçi
    struct Node* prev;    // Bir önceki düğüme işaretçi
} Node;

// Yeni düğüm oluşturma
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Bellek tahsisi başarısız oldu!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Listeye düğüm ekleme (sonuna ekleme)
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        // Liste boşsa
        *head = newNode;
        newNode->next = *head;  // Dairesel yapı
        newNode->prev = *head;  // Dairesel yapı
    } else {
        // Liste doluysa
        Node* last = (*head)->prev;  // Listenin sonunu işaretle
        last->next = newNode;
        newNode->prev = last;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}

// Listeyi önden yazdırma
void printListForward(Node* head) {
    if (head == NULL) {
        printf("Liste boş!\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Listeyi arkadan yazdırma
void printListBackward(Node* head) {
    if (head == NULL) {
        printf("Liste boş!\n");
        return;
    }
    Node* temp = head->prev;
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("\n");
}

// Düğüm silme
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
            prev = temp->prev;
            prev->next = temp->next;
            temp->next->prev = prev;
            *head = temp->next;
            free(temp);
            return;
        }
    }

    // Diğer düğümleri arama
    while (temp->next != *head && temp->data != key) {
        temp = temp->next;
    }

    if (temp->data == key) {
        prev = temp->prev;
        prev->next = temp->next;
        temp->next->prev = prev;
        free(temp);
    }
}

// Ana fonksiyon
int main() {
    Node* head = NULL;  // Liste başı

    // Listeye düğüm ekleme
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Listeyi yazdırma
    printf("Önden yazdırma: ");
    printListForward(head);

    printf("Arkadandan yazdırma: ");
    printListBackward(head);

    // Bir düğüm silme
    deleteNode(&head, 20);

    // Güncellenmiş listeyi yazdırma
    printf("Güncellenmiş liste: ");
    printListForward(head);

    // Belleği serbest bırakma
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        if (head == temp) { // Tek düğüm kaldıysa
            free(temp);
            break;
        }
        free(temp);
    }

    return 0;
}
