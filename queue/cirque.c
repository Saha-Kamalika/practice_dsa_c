#include<stdio.h>
#include<stdlib.h>
struct cirqueue{
	int size;
	int front;
	int rear;
	int *arr;
};
void enqueue(struct cirqueue *q,int val){
	if(isFull(q)){
		printf("Queue overflow, cannot insert\n");
		return;
	}
	else{
		printf("Enqueued element %d\n",val);
		q->rear=(q->rear+1)%q->size;
		q->arr[q->rear]=val;
	}
}
int isFull(struct cirqueue *q){
	if((q->rear+1)%q->size==q->front)
		return 1;
	return 0;
}
int isEmpty(struct cirqueue *q){
	if(q->rear==q->front)
		return 1;
	return 0;
}
int dequeue(struct cirqueue *q){
	if(isEmpty(q)){
		printf("Queue underflow\n");
		return;
	}
	else{
		q->front=(q->front+1)%q->size;
		return q->arr[q->front];
	}
}
void print(struct cirqueue *q){
	int i;
	for(i=q->front;i<q->rear+1;i=(i+1)%q->size)
		printf("%d ",q->arr[i]);
}
void main(){
	struct cirqueue *q=(struct cirqueue*)malloc(sizeof(struct cirqueue));
	q->size=6;
	q->front=q->rear=0;
	q->arr=(int *)malloc(q->size*sizeof(int));
	if(isEmpty(q))
		printf("Queue empty\n");
	enqueue(q,10);
	enqueue(q,12);
	enqueue(q,2);
	enqueue(q,112);
	enqueue(q,121);
	printf("Dequeueing the first element %d\n",dequeue(q));
	enqueue(q,124);
	if(isFull(q))
		printf("Queue full\n");
	
	enqueue(q,125);
	printf("Dequeueing the first element %d\n",dequeue(q));
	print(q);
}
