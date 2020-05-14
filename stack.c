/*Program to demonstrate stack operation*/
#define CAPACITY 5
#include<stdio.h>
int stack[CAPACITY],top=-1;
void push(int);
void pop(void);
int isFull(void);
int isEmpty(void);
void peek(void);
void main()
{
    int ch,item;
    while(1)
    {
        printf("*****Stack Operations*****\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Traverse\n");
        printf("5.Quite\n");

        printf("Enter Your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("\tEnter the Data to be pushed : ");
                    scanf("%d",&item);
                    push(item);
                    break;
            case 2: pop();
                     break;
            case 3: peek();
                    break;
            case 4: traverse();
                    break;
            case 5: exit(1);
                    break;
            default: printf("\t\nInvalid Inputs...\n\n");
        }
    }
}

void push(int ele)
{
    if(isFull())
    {
        printf("\t\nStack is Overflow...\n\n");
    }
    else
    {
        top++;
        stack[top]=ele;
        printf("\t\n%d is Pushed  \n\n",stack[top]);
    }
}

int isFull()
{
    if(top==CAPACITY-1)
    {
      return 1;
    }
    else
    {
        return 0;
    }
}

void pop()
{
    if(isEmpty())
    {
        printf("\t\nStack is Underflow...\n\n");
    }
    else
    {
        return stack[top--];
    }
}

int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void peek()
{
    if(isEmpty())
    {
        return 0;
    }
    else
    {
        printf("\t\nThe Peek Element is::%d\n\n",stack[top]);

    }
}

void traverse()
{
    if(isEmpty())
    {
        return 0;
    }
    else
    {
        int i;
        for(i=0;i<=top;i++)
        {
            printf("\t| %d |\n",stack[i]);
        }
    }
}
