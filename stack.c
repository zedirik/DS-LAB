/*STACK USING ARRAY*/

#include <stdio.h>

int stack[100];
int top = -1;
int size;

void PUSH(int item) {
    if (top == size - 1) {
        printf("Stack Overflow! Cannot push %d\n", item);
    } else {
        top++;
        stack[top] = item;
        printf("%d pushed onto stack\n", item);
    }
}

void POP() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty\n");
    } else {
        printf("Popped element is %d\n", stack[top]);
        top--;
    }
}

void DISPLAY() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, item;

    printf("Enter size of stack: ");
    scanf("%d", &size);

   
    

    do {
        printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &item);
                PUSH(item);
                break;
            case 2:
                POP();
                break;
            case 3:
                DISPLAY();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}









💻 Algorithm: Stack Implementation Using Array
Step 1: Start
Step 2: Initialize

Declare an array stack[100] to hold stack elements.

Initialize top = -1 (indicates an empty stack).

Input the size of the stack.

Step 3: Define Operations
(a) PUSH Operation

Check if top == size - 1
→ If true, Stack Overflow, print message.

Otherwise:

Increment top by 1

Set stack[top] = item

Print that the item has been pushed.

(b) POP Operation

Check if top == -1
→ If true, Stack Underflow, print message.

Otherwise:

Print stack[top] as the popped element.

Decrement top by 1.

(c) DISPLAY Operation

Check if top == -1
→ If true, print “Stack is empty.”

Otherwise:

Print all elements of stack from top down to 0.

Step 4: Main Menu Loop

Repeat until the user chooses to Exit (choice = 4):

Display menu:

1. PUSH
2. POP
3. DISPLAY
4. EXIT


Input the user’s choice.

Use a switch statement to perform the corresponding operation:

Case 1 → Call PUSH(item)

Case 2 → Call POP()

Case 3 → Call DISPLAY()

Case 4 → Print “Exiting…” and stop

Default → Print “Invalid choice”

Step 5: Stop