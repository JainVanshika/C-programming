#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;

void createnode(int n);
void displaydata();

void createnode(int n)
{
    struct node *newnode, *temp;
    head=(struct node *)malloc(sizeof(struct node));
    int value;
    if(head==NULL)
    {
        printf("unable to allocate memory");
    }
    else
    {
        printf("enter the data in node 1:");
        scanf("%d",&value);
        head->data=value;
        head->next=NULL;
        temp=head;

        for(int i=2;i<=n;i++)
        {
            newnode=(struct node *)malloc(sizeof(struct node));
            if(newnode==NULL)
            {
                printf("new node is empty");
                break;
            }
            else
            {
                printf("enter the data in node %d:",i);
                scanf("%d",&value);
                newnode->data=value;
                newnode->next=NULL;
                temp->next=newnode;
                temp=temp->next;
            }
        }
        printf("\nnode inserted successfully\n");
    }
}
void insertnode(int value1)
{
    struct node *newnode, *temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("unable to allocate memory");
    }
    else
    {
        newnode->data=value1;
        newnode->next=NULL;
        temp=head;
        while(temp!=NULL && temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

int main()
{
    int n,value1;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    createnode(n);
    displaydata();
    printf("enter the value to be inserted:");
    scanf("%d",&value1);
    insertnode(value1);
    displaydata();
    return 0;
}

void displaydata()
{
    struct node *temp=head;
    printf("\ndata:\n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("NUll\n");
}