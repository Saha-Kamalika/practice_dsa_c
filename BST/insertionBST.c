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
void insert(struct node* root,int key)
{
    struct node*prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(key==root->data)
        {
            printf("Insertion not possible, %d already present\n",key);
            return;
        }
        else if(key<root->data)
            root=root->left;
        else root=root->right;
    }
    struct node *new=createNode(key);
    printf("%d successfully inserted\n",key);
    if(key<prev->data)
        prev->left=new;
    else prev->right=new;
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
        printf("\nEnter the key to insert: ");
        scanf("%d",&key);
        insert(p,key);
    }
    printf("Updated BST: ");
    inorder(p);
}