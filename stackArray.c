#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define N 5
int stack[N];
int top = -1;
void push(){
    int x;
    printf("Enter Data:");
    scanf("%d", &x);
    if(top == N-1){
        printf("Stack Overflow!\n");
    }
    else{
        top++;
        stack[top] = x;
        printf("Data Pushed: %d\n", x);
    }
}
void pop(){
    int item;
    if(top == -1){
        printf("Stack Underflow");
    }
    else{
        item = stack[top];
        top--;
        printf("Data Popped: %d\n", item);
    }
}
void peek(){
    if(top == -1){
        printf("Stack is Empty\n");
    }
    else{
        printf("Top Element: %d\n", stack[top]);
    }
}
void display(){
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack elements are:\n");
        for(int i = top; i >= 0; i--){
            printf("%d\n", stack[i]);
        }
    }
}
int main(){
    int choice;
    do{
        printf("Enter choice:\n 1. Push\n 2. Pop\n 3. Peek\n 4. Display\n 5. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                push();
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
    }while (choice != 5);
    {
        printf("Thank you for using the stack program!\n");
    }
    return 0;
}
