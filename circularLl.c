#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
}*head;
void traversal(struct Node* head)
{
	struct Node *ptr=head;
    printf("The list is: ");
    while(ptr->next!=head)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
}
struct Node* insertBegin(struct Node* head)
{
    struct Node* ptr;
    int data;
    ptr=(struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the value: ");
    scanf("%d",&data);
    struct Node* p=head->next;
    while(p->next!=head)
    {
    	p=p->next;
	}
    ptr->data=data;
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return ptr;
}
/*struct Node* insertBetween(struct Node* head)
{
    struct Node *ptr;
    ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* p=head;
    int index,i=0,data;
    printf("\nEnter the index of insertion: ");
    scanf("%d",&index);
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    printf("\nEnter the value: ");
    scanf("%d",&data);
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct Node* insertEnd(struct Node* head)
{
    //struct Node* ptr1=head;
    struct Node* p=head;
    int data;
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    while(p->next!=NULL)
    {
        p=p->next;
    }
    printf("\nEnter the value: ");
    scanf("%d",&data);
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
struct Node* insertAfterNode(struct Node* head)
{
    struct Node* p = head;
    int data,i=1,node;
    printf("\nEnter the node after which you want to insert: ");
    scanf("%d",&node);
    while(i!=node)
    {
        p=p->next;
        i++;
    }
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the value: ");
    scanf("%d",&data);
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}*/
struct Node* create(int n)
{
    int data,i;
    struct Node* newNode,*temp;
    head=(struct Node*)malloc(sizeof(struct Node));
    if(head==NULL)
    {
        printf("Unable to allocate memory");
        exit(0);
    }
    printf("Enter node 1 data: ");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    
    temp=head;
    for(i=2;i<=n;i++)
    {
        newNode=(struct Node*)malloc(sizeof(struct Node));
        if(newNode==NULL)
        {
            printf("Unable to allocate memory");
            break;
        }
        printf("Enter node %d data: ",i);
        scanf("%d",&data);
        newNode->data=data;
        newNode->next=head;
        temp->next=newNode;
        temp=temp->next;
    }
    return head;
}
/*struct Node * delFirstNode(struct Node* head)
{
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}*/
void main()
{
    int n;
    printf("Enter the no of nodes in the linked list: ");
    scanf("%d",&n);
    head=create(n);
    traversal(head);
    printf("\nINSERT BEGIN");
    head=insertBegin(head);
    traversal(head);
    /*printf("\nINSERT BETWEEN");
    head=insertBetween(head);
    traversal(head);
    printf("\nINSERT AT END");
    head=insertEnd(head);
    traversal(head);
    printf("\nINSERT AFTER NODE");
    head=insertAfterNode(head);
    traversal(head);
    head=delFirstNode(head);
    traversal(head);*/
}
