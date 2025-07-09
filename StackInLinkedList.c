#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int data;
    struct Stack* next;
} stack ;
stack* top = 0;
void push(int value) {
    stack* newNode;
    newNode = (stack*)malloc(sizeof(stack));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
void display() {
    stack* temp = top;
    if(top == 0) {
        printf("Stack is empty\n");
        return;
    }
    else{
        printf("Stack elements are: ");
        while(temp != 0) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void peek() {
    if( top == 0) {
        printf("Stack is empty\n");
        return;
    }
    else {
        printf("Top element is %d\n", top->data);
    }
}
    
void pop() {
    stack* temp = top;
    if(top == 0) {
        printf("Stack Underflow\n");
        return;
    }else {
        top = top->next;
        printf("Popped %d from the stack\n", temp->data);
        free(temp);
    }
}

int main () {
    int choice, value;
    do{
    printf("Stack using Linked List\n");
    printf("Choose a option :\n");
    printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit");
    scanf("%d",&choice);
    switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice\n");
     }
     }while(choice != 5);

return 0;
}