/*STACK USING LINKED LIST*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top;
void DISPLAY()
{
    struct node *ptr;
    if(top==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        ptr=top;
        printf("Stack elements are:");
        while(ptr!=NULL)
        {
            printf("%d",ptr->data);
            ptr=ptr->link;
        }
    }
}
void PUSH(int item)
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=item;
    new->link=top;
    top=new;
}
void POP()
{
    struct node *temp;
    if(top==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        temp=top;
        printf("Popped element is %d",top->data);
        top=top->link;
        free(temp);
    }
}
void main()
{
    int option,item;
    do{
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        printf("Enter option:");
        scanf("%d",&option);
        switch(option)
        {
            case 1: printf("Enter value to insert:");
                    scanf("%d",&item);
                    PUSH(item);
                    break;;
            case 2:POP();
                   break;
            case 3:DISPLAY();
                   break;
            case 4:printf("exiting...");
                   break;
            default: printf("Inavlid choice");
        }
    }while(option!=4);
}




Algorithm: Stack Using Linked List

Step 1: Start.

Step 2: Define a structure for a node with:

data → integer value

link → pointer to next node

Step 3: Initialize top as NULL.

PUSH Operation (Insert element)

Step 4: Create a new node.

Step 5: If memory allocation fails, print “Memory allocation failed” and go back to menu.

Step 6: Read the element to be inserted (item).

Step 7: Assign new->data = item.

Step 8: Set new->link = top.

Step 9: Update top = new.

Step 10: Print “Item pushed successfully” and return.

POP Operation (Delete element)

Step 11: Check if top == NULL.

If yes, print “Stack is empty” and return.

Step 12: Else, set temp = top.

Step 13: Print “Popped element is temp->data”.

Step 14: Update top = top->link.

Step 15: Free the memory of temp and return.

DISPLAY Operation

Step 16: Check if top == NULL.

If yes, print “Stack is empty” and return.

Step 17: Else, set ptr = top.

Step 18: While ptr != NULL

Print ptr->data

Move ptr = ptr->link
End While

Step 19: Return to menu.

Main Menu

Step 20: Repeat the following until the user chooses to exit:

Display menu:

1. PUSH
2. POP
3. DISPLAY
4. EXIT


Read user choice.

Perform the corresponding operation (PUSH, POP, DISPLAY, or exit).

If choice is invalid, print “Invalid choice”.

Step 21: Stop.