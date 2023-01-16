#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
}*head;
void traversal(struct Node* ptr)
{
    printf("\nThe list is: ");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
struct Node* insertBegin(struct Node* head)
{
    struct Node* ptr;
    int data;
    ptr=(struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the value: ");
    scanf("%d",&data);
    ptr->data=data;
    ptr->next=head;
    return ptr;
}
struct Node* insertBetween(struct Node* head)
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
}
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
        newNode->next=NULL;
        temp->next=newNode;
        temp=temp->next;
    }
    return head;
}
struct Node * delFirstNode(struct Node* head)
{
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct Node * delBetNode(struct Node* head)
{
	int index,i=0;
	printf("\nEnter the index of the node you want to delete: ");
	scanf("%d",&index);
	struct Node* p=head;
	while(i!=index-1)
	{
		p=p->next;
		i++;
	}
	struct Node* q=p->next;
	p->next=q->next;
	free(q);
	return head;
}
struct Node * delLast(struct Node* head)
{
	struct Node* p=head;
	while(p->next->next!=NULL)
	{
		p=p->next;
	}
	struct Node* q=p->next;
	p->next=NULL;
	free(q);
	return head;
}
struct Node * delNode(struct Node *head)
{
	struct Node* ptr=head;
	int value;
	printf("\nEnter the node value you want to delete: ");
	scanf("%d",&value);
	while(ptr->next->data!=value)
	{
		ptr=ptr->next;
	}
	struct Node* q=ptr->next;
	ptr->next=q->next;
	free(q);
	return head;
}
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
    printf("\nINSERT BETWEEN");
    head=insertBetween(head);
    traversal(head);
    printf("\nINSERT AT END");
    head=insertEnd(head);
    traversal(head);
    printf("\nINSERT AFTER NODE");
    head=insertAfterNode(head);
    traversal(head);
    printf("\nDELETE BEGIN");
    head=delFirstNode(head);
    traversal(head);
    printf("\nDELETE BETWEEN");
    head=delBetNode(head);
    traversal(head);
    printf("\nDELETE LAST");
    head=delLast(head);
    traversal(head);
    printf("\nDELETE NODE VALUE");
    head=delNode(head);
    traversal(head);
}