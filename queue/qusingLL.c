#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node * next;
};
struct Node *f=NULL;
struct Node *r=NULL;
int dequeue(){
	int val=-1;
	struct Node *ptr=f;
	if(f==NULL)
		printf("Queue empty");
	else{
		f=f->next;
		val=ptr->data;
		free(ptr);
		return val;
	}
}
void traversal(struct Node *ptr)
{
	printf("Printing the nodes in the linked list: \n");
	while(ptr!=NULL)
	{
		printf("Element = %d\n",ptr->data);
		ptr=ptr->next;
	}
}
void enqueue(int val)
{
	struct Node *n=(struct Node*)malloc(sizeof(struct Node));
	if(n==NULL)
		printf("Queue full");
	else{
		n->data=val;
		n->next=NULL;
		if(f==NULL)
			f=r=n;
		else{
			r->next=n;
			r=n;
		}
	}
}
void main()
{
	enqueue(10);
	enqueue(20);
	traversal(f);
	dequeue();
	traversal(f); 
}
