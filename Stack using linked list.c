/*This is the program to demonstrate the Stack Implementation using
single linked list..*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* top=NULL;
void push(void);
void pop(void);
void traverse(void);

int main()
{
    int ch;
    while(1)
    {
        printf("*****Stack Using Linked List*****\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Traverse\n");
        printf("4.Quite\n");

        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: traverse();
                    break;
            case 4: exit(1);
                    break;
            default: printf("Invalid Input provided...");
        }
    }
}

void push()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&temp->data);
    temp->link=top;
    top=temp;
}

void pop()
{
    struct node* temp;

    if(top==NULL)
    {
        printf("The Stack is Empty...");
    }
    else
    {
        temp=top;
        top=top->link;
        temp->link=NULL;
        free(temp);
    }
}

void traverse()
{
    if(top==NULL)
    {
        printf("The Stack is Empty...");
    }
    else
    {
        struct node* temp;
        temp=top;
        while(temp!=NULL)
        {
            printf("\t|%d|\n",temp->data);
            temp=temp->link;
        }
    }
}
