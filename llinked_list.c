/*Program Demonstrating the operation of linked list...*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
int len;
struct node* head=NULL;

void append(void);
int length(void);
void display(void);
void Delete(void);
void addatbegin(void);
void addatafter(void);
int main()
{
    int ch;
    while(1)
    {
        printf("*****Linked List operation*****\n");
        printf("1.Append\n");
        printf("2.Addatbegin\n");
        printf("3.Addatafter\n");
        printf("4.Length\n");
        printf("5.Display\n");
        printf("6.Delete\n");
        printf("7.Quite\n");

        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: append();
                    break;
            case 2: addatbegin();
                    break;
            case 3: addatafter();
                    break;
            case 4: len=length();
                    printf("\nLength : %d\n\n",len);
                    break;
            case 5: display();
                    break;
            case 6: Delete();
                    break;
            case 7: exit(1);
            default: printf("Invalid Inputs..\n");
        }
    }
}
void append()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node* p;
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
}

void addatbegin()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}

void addatafter()
{
    int loc,i=1;
    struct node* temp,*p;
    p=head;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    printf("Enter the location you want to insert the node: ");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("\nInvalid Location....\n");
    }
    else
    {
        while(i<loc)
        {
            p=p->next;
            i++;
        }
        temp->next=p->next;
        p->next=temp;
    }
}

int length()
{
    struct node* temp;
    int count=0;
    temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
}

void display()
{
    struct node* temp;
    temp=head;
    if(temp==NULL)
    {
        printf("List is Empty...\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("\n\n");
    }
}

void Delete()
{
    struct node* temp;
    int loc;

    printf("Enter the location you want to delete: ");
    scanf("%d",&loc);

    if(loc>length())
    {
        printf("Invalid Location...\n");
    }
    else if(loc==1)
    {
        temp=head;
        head=temp->next;
        temp->next=NULL;
        free(temp);
    }
    else
    {
        temp=head;
        int i=1;

        while(i<loc-1)
        {
            temp=temp->next;
            i++;
        }
        struct node* q;

        q=temp->next;
        temp->next=q->next;
        q->next=NULL;
        free(q);
    }
}
