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
		//printf("Enqueued element %d\n",val);
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
    int a=-1;
	if(isEmpty(q)){
		printf("Queue underflow\n");
		return;
	}
	else{
		q->front++;
		a= q->arr[q->front];
	}
    return a;
}
void print(struct queue *q){
	int i;
	for(i=q->front+1;i<q->rear+1;i++)
		printf("%d ",q->arr[i]);
}
void main(){
	struct queue q;
	q.size=20;
	q.front=q.rear=-1;
	q.arr=(int *)malloc(q.size*sizeof(int));
    //BFS IMPLEMENTATION
	int node;
    int i = 0,j;
    int visited[7] = {0,0,0,0,0,0,0};
    int a [7][7] = {   //Creating adjacency matrix
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
    printf("The BFS TRaversal order is: ");
    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i); // Enqueue i for exploration
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (j=0;j<7;j++)
        {
            if(a[node][j] ==1 && visited[j] == 0){
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
}
