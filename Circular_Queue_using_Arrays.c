#include <stdio.h>
#include <stdlib.h>

#define N 5

int queue[N];
int front = -1, rear = -1;

void enqueue(int x) {
    if(rear == -1 && front == -1) {
        front = rear = 0;
        queue[rear]  = x;
    }
    else if((rear + 1) % N == front) {
        printf("Queue is full\n");
    }else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}
void dequeue() {
    if(rear == -1 && front == -1) {
        printf("Queue is Empty\n");
    }
    else if (front == rear) {
        printf("Dequeued element: %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Dequeued element: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display() {
    if(rear == -1 && front == -1) {
        printf("Queue is empty\n");
    }else{
        printf("Queue elements are: ");
        int i = front;
        while(i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1)%N;
        }
        printf("%d\n", queue[rear]);
    }
}

void peek() {
    if(rear == -1 && front == -1) {
    printf("Queue is empty\n");
    }
    else { 
        printf("Peek element is: %d\n", queue[front]);
    }
}
int main() {
    int choice, value;
    do {
        printf("Circular Queue using Arrays\n");
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