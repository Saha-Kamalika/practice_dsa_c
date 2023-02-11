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
char peek(struct stack *ptr)
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
char stackBottom(struct stack *ptr)
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
int parenthesisMatch(char* exp)
{
	struct stack *sp;
	sp->size=strlen(exp);
	sp->top=-1;
	sp->arr=(char *)malloc(sp->size*sizeof(char));
	int i;
	for(i=0;exp[i]!='\0';i++){
		if(exp[i]=='('){
			push(sp,'(');
		}
		else if(exp[i]==')'){
		if(isEmpty(sp))
			return 0;
		pop(sp);
	}
	}
	if(isEmpty(sp))
		return 1;
	return 0;
}

void print(struct stack *ptr)
{
	int i;
	for(i=0;i<ptr->top+1;i++)
		printf("%d ",ptr->arr[i]);
}
void main()
{
	char *exp="2+3*(8-5)";
	/*printf("Enter the expression :");
	scanf("%s",&exp);*/
	if(parenthesisMatch(exp))
		printf("The expression is balanced");
	else
		printf("The expression is not balanced");
}
