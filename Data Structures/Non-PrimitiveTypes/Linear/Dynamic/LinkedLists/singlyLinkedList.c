#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;

} Node; //class in other languages

Node* createNode(int data){ //creating new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Huh! Memory allocation error!\n");
        exit(1);
    }
    
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void appendNode(Node** head, int data){
    Node* newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp -> next;
    }
    temp ->next = newNode;    
}

void printList(Node* head){
    Node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void freeList(Node* head){
    Node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    
}


int main(){

    Node* head = NULL;

    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);

    printf("List: ");
    printList(head);

    freeList(head);
    
    return 0;

}


/*malloc : Bu, programın çalıştığı anda bellekte değişken boyutlarda veri yapılarını yönetmenizi sağlar. 
           Bellek tahsisi derleme zamanında değil, çalışma zamanında yapılır, bu da bellek kullanımı üzerinde daha fazla kontrol sağlar.*/