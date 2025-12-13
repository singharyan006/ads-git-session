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

struct Node *insertAtFirst(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
struct Node *insertInBtw(struct Node *head,int data,int index){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1){ //jis index p insert krna h uske ek pehle wale node pr aajayenge
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;

}

struct Node *InsertAtEnd(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    ptr->data=data;

    while (p->next != NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct Node *InsertAfterNode(struct Node *head,struct Node *prevNode,int data){
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
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    head->data = 7;
    head->next = second;
    second->data = 13;
    second->next = third;
    third->data = 89;
    third->next = NULL;
    linkedlistTraversal(head);
    head=insertAtFirst(head,56);
    linkedlistTraversal(head);
    head=insertInBtw(head,43,2);
        linkedlistTraversal(head);
    head=InsertAfterNode(head,second,45);
        linkedlistTraversal(head);
     head=InsertAtEnd(head,100);
    linkedlistTraversal(head);
    return 0;
}