#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* front = 0;
struct node* rear = 0;

void enqueue(int x){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = x ;
    newnode->next = 0;
    if(front == 0 && rear == 0){
        front = rear = newnode;
    }else{
        rear->next = newnode;
        rear = newnode;
    }
}

void display() {
    struct node* temp;
    if(front == 0 && rear == 0){
        printf("Queue is empty\n");
    }
    else{
        temp = front;
        while(temp != 0){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
void dequeue(){
    struct node* temp;
    if(front == 0 && rear == 0) {
        printf("Queue is empty\n");
    }else{
        temp = front;
        printf("Poping the front element from the Queue: %d\n", temp->data);
        front = front->next;
        free(temp);
    }
}
void peek() {
    if(front == 0 &&  rear == 0) {
        printf("Queue is empty\n");
    }else{
        printf("Peek element is: %d\n", front->data);
    }
}
int main() {
    int choice, value;
    do {
        printf("Queue using Linked List\n");
        printf("Choose an option:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
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
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}