#include<stdio.h>
#include<stdlib.h>
struct queue{
	int size;
	int front;
	int rear;
	int *arr;
};
void enqueue(struct queue *q,int val){
	if(isFull(q)){
		printf("Queue overflow\n");
		return;
	}
	else{
		printf("Enqueued element %d\n",val);
		q->rear++;
		q->arr[q->rear]=val;
	}
}
int isFull(struct queue *q){
	if(q->rear==q->size-1)
		return 1;
	return 0;
}
int isEmpty(struct queue *q){
	if(q->rear==q->front)
		return 1;
	return 0;
}
int dequeue(struct queue *q){
	if(isEmpty(q)){
		printf("Queue underflow\n");
		return;
	}
	else{
		q->front++;
		return q->arr[q->front];
	}
}void print(struct queue *q){
	int i;
	for(i=q->front+1;i<q->rear+1;i++)
		printf("%d ",q->arr[i]);
}
void main(){
	struct queue *q=(struct queue*)malloc(sizeof(struct queue));
	q->size=5;
	q->front=q->rear=-1;
	q->arr=(int *)malloc(q->size*sizeof(int));
	if(isEmpty(q))
		printf("Queue empty\n");
	enqueue(q,10);
	enqueue(q,12);
	enqueue(q,2);
	enqueue(q,112);
	enqueue(q,121);
	enqueue(q,124);
	if(isFull(q))
		printf("Queue full\n");
	printf("Dequeueing the first element %d\n",dequeue(q));
	enqueue(q,125);
	print(q);
}
