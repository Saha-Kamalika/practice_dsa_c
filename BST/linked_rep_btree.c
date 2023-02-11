#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
int createNode(int data){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void main()
{
    struct node* p=createNode(2);
    struct node* p1=createNode(1);
    struct node* p2=createNode(9);
    p->left=p1;
    p->right=p2;
}