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
//inorder
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int isBST(struct node* root){
    static struct node* prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left))
            return 0;
        if(prev!=NULL && root->data<=prev->data)
            return 0;
        prev=root;
        return isBST(root->right);
    }
    else return 1;
}
struct node* search(struct node* root,int key)
{
    if(root==NULL)
        return NULL;
    if(root->data==key)
        return root;
    else if(root->data>key)
        return search(root->left,key);
    else return search(root->right,key);
}
void main()
{
    int key;
    struct node* p=createNode(9);
    struct node* p1=createNode(4);
    struct node* p2=createNode(10);
    struct node* p3=createNode(1);
    struct node* p4=createNode(6);
    /*
          9
        /   \
       4     10
      / \
    1    6*/
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    printf("\nThe inorder traversal of this binary tree is: ");
    inorder(p);
    printf("\n");
    if(isBST(p)){
        printf("Yes it is a BST");
        printf("Enter the key for searching: ");
        scanf("%d",&key);
        struct node * n=search(p,key);
        if(n!=NULL)
            printf("key found: %d",n->data);
        else printf("key not found");}
    else printf("Cannot search, It is not a BST");
}
