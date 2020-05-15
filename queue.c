#include<stdio.h>
#define CAPACITY 5
int queue[CAPACITY];
int front=0;
int rear=0;
void insert(void);
void delete1(void);
void taverse(void);
int main()
{
    int ch;
    while(1)
    {
        printf("\n*****Queue Operations*****\n");
        printf("\t1.Insert\n");
        printf("\t2.Delete\n");
        printf("\t3.Traverse\n");
        printf("\t4.Quite\n");

        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: insert();
                    break;
            case 2: delete1();
                    break;
            case 3: traverse();
                    break;
            case 4: exit(1);
                    break;
            default: printf("\n\tInvalid Input provided...");
        }
    }
}

void insert()
{
    int ele;
    if(rear==CAPACITY)
    {
        printf("\nSorry...Queue is Full....\n");
    }
    else
    {
        printf("Enter the data to be stored: ");
        scanf("%d",&ele);
        queue[rear]=ele;
        rear++;
    }
}

void delete1()
{
    if(front==rear)
    {
        printf("\nQueue is Empty...\n");
    }
    else
    {
        printf("Deleted Element is %d\t",queue[front]);
        for(int i=0;i<rear-1;i++)
        {
            queue[i]=queue[i+1];
        }
        rear--;
    }
}

void traverse()
{
    if(front==rear)
    {
        printf("\nQueue is Empty...\n");
    }
    else
    {
        printf("\nQueue Elements are: \n");
        for(int i=front;i<rear;i++)
        {
            printf("|%d|",queue[i]);
        }
    }
}
