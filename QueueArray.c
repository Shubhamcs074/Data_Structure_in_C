#include <stdio.h>
#include <stdlib.h>

#define N 5
int queue[N];
int front = -1,rear = -1;

void enqueue(int value) {
    if(rear == -1 && front == -1) {
        rear = front = 0;
        queue[rear] = value;
    }
    else if(rear == N-1) {
        printf("Queue OverFlow\n");
    }
    else{
        rear++;
        queue[rear] = value;
    }
}
void dequeue() {
    if(rear == -1 && front == -1) {
        printf("Queue UnderFlow\n");
    }
    else if(front == rear) {
        front = rear - 1;
    }
    else{
        printf("%d Element is Popped from the Queue!!!\n",queue[front]);
        front++;
    }
}
void dispaly() {
    if(front == -1 && rear == -1) {
        printf("Queue Underflow i.e Queue is Empty\n");
    }
    else{
        printf("Queue is :\n");
        for(int i = front;i<rear + 1; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void peek() {
    if(front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    }else{
        printf("Queue front Element is: %d\n", queue[front]);
    }
}
int main(){
    int choice, value;
    do{
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit...\n");
        printf("Enter your Choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter the value to be about to Enqueue:");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                dispaly();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);
    return 0;
}