#include <stdio.h>

#define N 5

int queue[N];
int front = -1, rear = -1;

int isEmpty(){
    return front > rear;
}

void Enqueue(int data) {
    if(rear == N - 1) {
        printf("Queue Overflow\n");
        return;
    }
    rear++;
    queue[rear] = data;
}

void Dequeue() {
    if(isEmpty()){
        printf("Queue underflow\n");
        return;
    }
    front++;
}
int getFront() {
    if (isEmpty()) 
        return -1;
    return queue[front];
}

int getRear() {
    if(isEmpty()) 
        return -1;
    return queue[rear];
}

int getSize() {
    if(isEmpty()) 
        return 0;
    return rear - front + 1;
}

void printQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue after Enqueue Operation: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    printQueue();
    printf("Front: %d\n", getFront());
    printf("Rear: %d\n", getRear());
    Enqueue(1);
    printQueue();
    printf("Front: %d\n", getFront());
    printf("Rear: %d\n", getRear());
    Enqueue(8);
    printQueue();
    printf("Front: %d\n", getFront());
    printf("Rear: %d\n", getRear());
    Enqueue(3);
    printQueue();
    printf("Front: %d\n", getFront());
    printf("Rear: %d\n", getRear());
    Enqueue(6);
    printQueue();
    printf("Front: %d\n", getFront());
    printf("Rear: %d\n", getRear());
    Enqueue(2);
    printQueue();
    printf("Front: %d\n", getFront());
    printf("Rear: %d\n", getRear());

    if (!isEmpty()) {
        printQueue();
    }

    printf("Front: %d\n", getFront());
    printf("Rear: %d\n", getRear());
    printf("Queue size: %d\n", getSize());
    printQueue();

    Dequeue();
    printQueue();
    printf("Front: %d\n", getFront());
    printf("Rear: %d\n", getRear());

    printf("Is queue empty? %s\n", isEmpty() ? "Yes" : "No");
    printQueue();
    

    return 0;
}

