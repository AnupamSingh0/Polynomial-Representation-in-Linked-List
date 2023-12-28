#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coff;
    int expo;
    struct node *next;
};

struct node *first1 = NULL, *last1 = NULL;
struct node *first2 = NULL, *last2 = NULL;

void create(struct node **first, struct node **last)
{
    struct node *temp;
    int i;
    while (1)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Coefficient: ");
        scanf("%d", &temp->coff);
        printf("Enter the Exponent: ");
        scanf("%d", &temp->expo);
        temp->next = NULL;
        if (*first == NULL)
        {
            *first = temp;
            *last = temp;
        }
        else
        {
            (*last)->next = temp;
            *last = temp;
        }
        printf("Press 1 to create a new node: ");
        scanf("%d", &i);
        printf("\n");
        if (i != 1)
            break;
    }
}

void traverse(struct node *first)
{
    struct node *p;
    p = first;
    printf("The Polynomial: ");
    while (p != NULL)
    {
        printf("%dx^%d ", p->coff, p->expo);
        if (p->next != NULL)
            printf("+ ");
        p = p->next;
    }
    printf("\n");
}

struct node *add(struct node *first1, struct node *first2){
        struct node *result = NULL, *lastResult = NULL;

    while (first1 != NULL || first2 != NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->next = NULL;

        if (first1 != NULL && first2 != NULL)
        {
            if (first1->expo > first2->expo)
            {
                temp->coff = first1->coff;
                temp->expo = first1->expo;
                first1 = first1->next;
            }
            else if (first1->expo < first2->expo)
            {
                temp->coff = first2->coff;
                temp->expo = first2->expo;
                first2 = first2->next;
            }
            else
            {
                temp->coff = first1->coff + first2->coff;
                temp->expo = first1->expo;
                first1 = first1->next;
                first2 = first2->next;
            }
        }
        else if (first1 != NULL)
        {
            temp->coff = first1->coff;
            temp->expo = first1->expo;
            first1 = first1->next;
        }
        else if (first2 != NULL)
        {
            temp->coff = first2->coff;
            temp->expo = first2->expo;
            first2 = first2->next;
        }

        if (result == NULL)
        {
            result = temp;
            lastResult = temp;
        }
        else
        {
            lastResult->next = temp;
            lastResult = temp;
        }
    }
    return result;
}

int main()
{
    printf("Enter coefficients and exponents for the first polynomial:\n");
    create(&first1, &last1);

    printf("\nEnter coefficients and exponents for the second polynomial:\n");
    create(&first2, &last2);

    printf("\nFirst Polynomial:\n");
    traverse(first1);

    printf("\nSecond Polynomial:\n");
    traverse(first2);

     struct node *sum = add(first1, first2);

    printf("\nSum of Polynomials:\n");
    traverse(sum);

    return 0;
}


