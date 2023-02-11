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
//preorder
void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
//postorder
void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
//inorder
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void main()
{
    struct node* p=createNode(2);
    struct node* p1=createNode(1);
    struct node* p2=createNode(9);
    struct node* p3=createNode(4);
    struct node* p4=createNode(6);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    printf("The preorder traversal of this binary tree is: ");
    preorder(p);
    printf("\nThe postorder traversal of this binary tree is: ");
    postorder(p);
    printf("\nThe inorder traversal of this binary tree is: ");
    inorder(p);
}