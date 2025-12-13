#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node *DeletetAtFirst(struct Node *head){
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct Node *DeleteInBtw(struct Node *head,int index){
    struct Node *p=head;
    int i=0;
    while(i!=index-1){ //jis index p insert krna h uske ek pehle wale node pr aajayenge
        p=p->next;
        i++;
    }
    struct Node *q=p->next;
    p->next=q->next;
    free(q);
    return head;

}

struct Node *DeleteAtEnd(struct Node *head){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;

    while (p->next != NULL)
    {
        p=p->next;
    }
    struct Node *q=p->next;
    free(q);
    ptr->next=NULL;
    return head;
}

struct Node *DeleteAfterNode(struct Node *head,struct Node *prevNode,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;

}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 7;
    head->next = second;
    second->data = 13;
    second->next = third;
    third->data = 89;
    third->next = fourth;
    fourth->data = 100;
    fourth->next = NULL;
    linkedlistTraversal(head);
    head=DeleteInBtw(head,2);
    linkedlistTraversal(head);
    return 0;
}