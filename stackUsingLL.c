#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *top=NULL;
int peek(struct Node *top)
{
	int pos,i;
	struct Node *ptr=top;
	printf("Enter position to peek: ");
	scanf("%d",&pos);
	for(i=0;(i<pos-1 && ptr!=NULL);i++)
	{
		ptr=ptr->next;
	}
	if(ptr!=NULL)
	printf("Peeked element: %d\n",ptr->data);
}
struct Node *push(struct Node *top,int n)
{
	if(isFull(top))
	{
		printf("Stack Overflow");
		return;
	}
	else{
		struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
		ptr->data=n;
		ptr->next=top;
		top=ptr;
		return top;
	}
	
}
struct Node *pop(struct Node *top)
{
	struct Node *ptr=top;
	if(isEmpty(top))
	{
		printf("Stack Underflow");
		return;
	}
	else{
		printf("Popped element: %d\n",ptr->data);
		top=top->next;
		free(ptr);
	return top;
}

int isFull(struct Node *top)
{
	struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
	if(ptr==NULL)
		return 1;
	else
		return 0;
}
int isEmpty(struct Node *top)
{
	if(top==NULL)
		return 1;
	else
		return 0;
}
void traversal(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void main()
{
	
	top=push(top,89);
	top=push(top,80);
	top=push(top,87);
	top=push(top,79);
	top=pop(top);
	if(isFull(top))
					printf("Stack full\n");
				else
					printf("Stack not full\n");
				
	if(isEmpty(top))
					printf("Stack empty\n");
				else
					printf("Stack not empty\n");
	traversal(top);
	peek(top);
	
	/*int size,n;
	printf("Enter the size of the stack :");
	scanf("%d",&size);
	while(1){
	printf("\n1. To insert element. \n2. To check stack full \n3. To check stack empty\n4. To pop\n\n5. To peek\n6. To print the stack\n7. To exit\n");
	scanf("%d",&n);
		switch(n){
		case 1: if(isFull(top))
					printf("Stack full cannot insert\n");
				else
				{
					push(top);	
				}
				break;
		case 2: if(isFull(top))
					printf("Stack full\n");
				else
					printf("Stack not full\n");
				break;
		case 3: if(isEmpty(top))
					printf("Stack empty\n");
				else
					printf("Stack not empty\n");
				break;
		case 4: if(isEmpty(top))
					printf("Cannot print. Stack empty\n");
				else
					pop(top);
				break;
		/*case 5: printf("Peeked element: %d",peek(s));
				break;
		case 6:	printf("The stack is: ");
				print(s);
				break; 
		case 7: exit(0);
		default: printf("Enter correct choice");
		}
	}*/
}
}
