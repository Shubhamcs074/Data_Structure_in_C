#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* front = 0;
struct node* rear = 0;

void enqueue(int x) {
    struct node* newnode ;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode ->next = 0;
    if(rear == 0){
        rear = front = newnode;
        rear->next = front;
    }else{
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}
void dequeue() {
    struct node* temp;
    temp = front;
    if(front == 0 && rear == 0 ){
        printf("Queue is Empty\n");
    }else if(front == rear){
        printf("Poped element %d from Queue\n",temp->data);
        front = rear = 0;
        free(temp);
    }else{
        printf("Poped element %d from Queue\n",temp->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}
void display(){
    struct node* temp;
    temp = front;
    if(rear == 0){
        printf("Queue is empty\n");
    }else{
        printf("Queue Elements are: ");
        while(temp->next != front){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}
void peek(){
    if(front == 0){
        printf("Queue is empty\n");
    }else{
        printf("Peek element is: %d\n", front->data);
    }
}
int main() {
    int choice, value;
    do {
        printf("\nCircular Queue using Linked List\n");
        printf("Choose an option:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
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
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 5);
    return 0;
}