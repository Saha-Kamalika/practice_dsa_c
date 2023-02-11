#include<stdio.h>
#include<stdlib.h>
struct stack{
	int size;
	int top;
	int *arr;
};
int isFull(struct stack *ptr)
{
	if(ptr->top==ptr->size-1)
		return 1;
	return 0;
}
int isEmpty(struct stack *ptr)
{
	if(ptr->top==-1)
		return 1;
	return 0;
}
int pop(struct stack *ptr)
{
	printf("\nPopped element: %d",ptr->arr[ptr->top]);
	return ptr->top--;
}
int peek(struct stack *ptr)
{
	int i;
	printf("Enter the position to peek: ");
	scanf("%d",&i);
	if(ptr->top-i+1<0){
		printf("Please enter valid position!");
		return -1;
	}
	else
		return ptr->arr[ptr->top-i+1];
}
int stackTop(struct stack *ptr)
{
	return ptr->arr[ptr->top];
}
int stackBottom(struct stack *ptr)
{
	return ptr->arr[0];
}
void print(struct stack *ptr)
{
	int i;
	for(i=0;i<ptr->top+1;i++)
		printf("%d ",ptr->arr[i]);
}
void main()
{
	struct stack *s;
	int i,n;	
	s=(struct stack *)malloc(sizeof(struct stack));
	s->top=-1;
	printf("Enter the size of the stack :");
	scanf("%d",&s->size);
	while(1){
	printf("\n1. To insert element. \n2. To check stack full \n3. To check stack empty\n4. To pop\n\n5. To peek\n6. To print the stack\n7. To exit\n");
	scanf("%d",&n);
		switch(n){
		case 1: if(isFull(s))
					printf("Stack full cannot insert\n");
				else
				{
					printf("Enter the element: ");
					s->top++;
					scanf("%d",&s->arr[s->top]);
					
				}
				break;
		case 2: if(isFull(s))
					printf("Stack full\n");
				else
					printf("Stack not full\n");
				break;
		case 3: if(isEmpty(s))
					printf("Stack empty\n");
				else
					printf("Stack not empty\n");
				break;
		case 4: if(isEmpty(s))
					printf("Cannot print. Stack empty\n");
				else
					pop(s);
				break;
		case 5: printf("Peeked element: %d",peek(s));
				break;
		case 6:	printf("The stack is: ");
				print(s);
				break; 
		case 7: exit(0);
		default: printf("Enter correct choice");
		}
	}
	printf("Stack Top element: %d",stackTop(s));
	printf("Stack Bottom element: %d",stackBottom(s));
}
