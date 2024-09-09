#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100 //the max size of stack
//Derleyici, bu makronun ismini bulduğunda, ilgili değeri kullanır. (global)

typedef struct Stack{
    int top;
    int items[MAX];
} Stack;

void initStack(Stack* s){
    s->top = -1;
}

bool push(Stack* s, int value){
    if (s->top >= MAX -1)
    {
        printf("Stack overflow! \n");
        return false;
    }
    s->items[++(s->top)] = value;
    return true;
}

bool pop(Stack* s, int* value){
    if (s->top < 0)
    {
        printf("Stack underflow! \n");
        return false;
    }
    *value = s ->items[(s->top)--];
    return true;
}

bool top(Stack* s, int* value){
    if (s->top < 0)
    {
        printf("Stack is empty! \n");
        return false;
    }
    *value = s->items[s->top];
    return true;
}

bool isEmpty(Stack* s){
    return s->top == -1;
}

void printStack(Stack* s){
    if (isEmpty(s))
    {
        printf("Stack is empty! \n");
        return;
    }
    printf("Stack contents: \n");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d\n", s->items[i]);
    }
}

int main(){
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printStack(&s);

    int value;

    if (pop(&s, &value))
    {
        printf("Popped: %d\n", value);
    }

    if (top(&s, &value))
    {
        printf("Top value: %d\n", value);
    }

    printStack(&s);

    return 0;
    
}




