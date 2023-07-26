#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void traverse( struct node * p)
{
    while (p != NULL)
    {
        printf("%d",p->data);
        p=p->link;
    }
    
}

int main()
{
    struct node * start;
    struct node * first;
    struct node * second;
    start=(struct node *) malloc(sizeof (struct node));
    first=(struct node *) malloc(sizeof (struct node));
    second=(struct node *) malloc(sizeof (struct node));
    start->data=5;
    start->link=first;
    first->data=3;
    first->link=second;
    second->data=4;
    second->link= NULL;

    traverse(start);
    return 0;

}
