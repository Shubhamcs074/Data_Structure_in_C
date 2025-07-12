#include <stdio.h>
#include <stdlib.h>

#define N 5
int Deque[N];
int front = -1, rear = -1;

void enqueue_front(int x){
    if((front == 0 && rear == N -1) || (front == rear + 1)){
        printf("Queue is Full\n");
    }
    else if(front == -1 && rear == -1) {
        front = rear = 0;
        Deque[front] = x;
    }
    else if(front == 0){
        front = N - 1;
        Deque[front] = x;
    }
    else{
        front--;
        Deque[front] = x;
    }
}
void enqueue_rear(int x){
    if((front == 0 && rear == N -1) || (front == rear + 1)){
        printf("Queue is Full\n");
    }
    else if(front == -1 && rear == -1) {
        front = rear = 0;
        Deque[rear] = x;
    }
    else if(rear == N - 1){
        rear = 0;
        Deque[rear] = x;
    }
    else{
        rear++;
        Deque[rear] = x;
    }
}
void display(){
    int i = front;
    printf("Queue elements are: \n");
    while(i != rear){
        printf("%d ",Deque[i]);
        i = (i + 1)%N;
    }
    printf("%d \n",Deque[rear]);
}
void getfront(){
    printf("front element is :%d \n",Deque[front]);
}
void dequeue_front(){
    if(front == -1 && rear == -1){
        printf("Queue is Empty");
    }
    else if( front == rear){
        front = rear = -1;
    }
    else if(front == N - 1){
        printf("Popped %d  from the queue\n",Deque[front]);
        front = 0;
    }
    else{
        printf("%d ", Deque[front]);
        front++;
    }
}

void dequeue_rear(){
    if(front == -1 && rear == -1){
        printf("Queue is Empty");
    }
    else if( front == rear){
        front = rear = -1;
    }
    else if(rear == 0){
        printf("Popped %d  from the queue\n",Deque[rear]);
        rear = N -1;
    }
    else{
        printf("%d ", Deque[rear]);
        rear--;
    }
}

int main() {
    int ch, value;
    do {
        printf("\nCircular Queue using Linked List\n");
        printf("Choose an option:\n");
        printf("1. Enqueue from Front\n2. Enqueue from Rear\n3. Dequeue from front\n4. Dequeue from Rear\n5. Peek\n6. Display\n7. Exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue_front(value);
                break;

            case 2:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue_rear(value);
                break;
            case 3:
                dequeue_front();
                break;
            case 4:
                dequeue_rear();
                break;
            case 5:
                getfront();
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(ch != 7);
    return 0;
}
