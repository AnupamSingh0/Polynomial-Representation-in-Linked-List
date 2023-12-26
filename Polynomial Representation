#include <stdio.h>
#include <stdlib.h>

struct node
{
    int cof;
    int expo;
    struct node *next;
};

struct node *first=NULL, *last=NULL;

void create()
{
    struct node *temp;
    int i;
    while(1)
    {
       temp =(struct node *)malloc(sizeof(struct node));
       printf("Enter the Coefficient: ");
       scanf("%d", &temp->cof);
              printf("Enter the Exponent: ");
       scanf("%d", &temp->expo);
       temp->next=NULL;
       if(first==NULL)
       {
           first=temp;
           last=temp;
       }
       else
       {
           last->next=temp;
           last=temp;
       }
       printf("Press 1 to create New Node: ");
       scanf("%d", &i);
       printf("\n");
       if(i!=1)
       break;
    }
}

void traverse()
{
    struct node *p;
    p=first;
    printf("The Polynomial: ");
    while(p!=NULL)
    {
        printf("%dx^%d ", p->cof, p->expo);
        if(p->next!=NULL)
        printf("+ ");
        p=p->next;
    }
    printf("\n");
}

int main()
{
    
    create();
    traverse();

    return 0;
}



