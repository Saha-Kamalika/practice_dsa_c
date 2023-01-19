#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
	int size;
	int top;
	char *arr;
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
char pop(struct stack *ptr)
{
	char val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
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
char stackTop(struct stack *ptr)
{
	return ptr->arr[ptr->top];
}
int stackBottom(struct stack *ptr)
{
	return ptr->arr[0];
}
void push(struct stack *ptr,char val)
{
	if(isFull(ptr))
		printf("Stack overflow! cannot insert");
	else{
		ptr->top++;
		ptr->arr[ptr->top]=val;
	}
}
void print(struct stack *ptr)
{
	int i;
	for(i=0;i<ptr->top+1;i++)
		printf("%d ",ptr->arr[i]);
}
int precedence(char ch)
{
	if(ch== '*'|| ch=='/')
		return 3;
	else if(ch=='+' || ch=='-')
		return 2;
	else return 0;
}
int isOperator(char ch)
{
	if(ch=='*' || ch=='/' || ch=='+' || ch=='-')
	 	return 1;
	return 0;
}
char *infixToPostfix(char * infix)
{
	struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
	sp->size=100;
	sp->top=-1;
	sp->arr=(char *)malloc(sp->size*sizeof(char));
	char *postfix=(char *)malloc(strlen(infix+1)*sizeof(char));
	int i=0,j=0;
	while(infix[i]!='\0')
	{
		if(!isOperator(infix[i])){
			postfix[j]=infix[i];
			j++;
			i++;
		}
		else{
			if(precedence(infix[i])>precedence(stackTop(sp))){
				push(sp,infix[i]);
				i++;
			}
			else
				{
					postfix[j]=pop(sp);
					j++;
				}
		}
	}
	while(!isEmpty(sp)){
		postfix[j]=pop(sp);
		j++;
	}
	postfix[j]='\0';
	return postfix;
}

void main()
{
	char *infix="a+b-d";
	printf("Postfix expression is %s",infixToPostfix(infix));
}
