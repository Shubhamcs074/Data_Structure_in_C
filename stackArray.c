#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

void display() {
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    }
    else{
        printf("Stack elements are: ");
        for(int i = top; i >=0; i--) {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}

void push(int value) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    else{
        top++;
        stack[top] = value;
        printf("Pushed %d onto the stack\n", value);
        display();
    }
}
void pop() {
    if(top == -1){
        printf("Stack Underflow\n");
        return;
    }
    else{
        printf("Poped %d from the stack\n", stack[top]);
        top--;
    }
}
void peek() {
        if(top == -1){
            printf("Stack underflow\n");
            return;
        }
        else{
            printf("Top element is %d\n", stack[top]);
        }
    }

int main() {
    int value, ch;
    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
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
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(ch != 5);
}