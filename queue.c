/*Queue using array*/

#include <stdio.h>

int queue[100];
int front = -1, rear = -1, size;

void ENQUEUE(int item) {
    if (rear == size - 1) {
        printf("Queue Overflow!\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = item;
        printf("%d inserted\n", item);
    }
}

void DEQUEUE() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void DISPLAY() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, item;

    printf("Enter size of queue: ");
    scanf("%d", &size);

    do {
        printf("\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &item);
                ENQUEUE(item);
                break;
            case 2:
                DEQUEUE();
                break;
            case 3:
                DISPLAY();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}




















🧩 Algorithm: Queue Using Array
Step 1: Start
Step 2: Initialize

Set
front = -1,
rear = -1.

Step 3: Input size of queue (size)
Step 4: Display menu
1. ENQUEUE
2. DEQUEUE
3. DISPLAY
4. EXIT

Step 5: Repeat until choice = 4

Read choice

Case 1: ENQUEUE (Insertion)

If rear == size - 1
→ Print “Queue Overflow”.

Else

If front == -1, set front = 0.

Increment rear → rear = rear + 1.

Insert element: queue[rear] = item.

Print “Element inserted”.

Case 2: DEQUEUE (Deletion)

If front == -1 or front > rear
→ Print “Queue Underflow”.

Else

Print “Deleted element = queue[front]”.

Increment front → front = front + 1.

If front > rear, set front = rear = -1 (queue becomes empty).

Case 3: DISPLAY

If front == -1 or front > rear
→ Print “Queue is empty”.

Else

Print all elements from queue[front] to queue[rear].

Case 4: EXIT

Print “Exiting program”.

Stop execution.

Step 6: End