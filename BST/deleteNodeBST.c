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
struct node* inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    return root;
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
struct node* inPre(struct node* root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}
struct node* deleteNode(struct node* root,int key)
{
    struct node* iPre;
    if(root==NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL){ //leaf node
        free(root);
        return NULL;
    }
    if(key<root->data){  //delete from left subtree
        root->left=deleteNode(root->left,key);}
    else if(key>root->data){ //delete from right subtree
        root->right=deleteNode(root->right,key);}
    else{
        iPre=inPre(root);
        root->data=iPre->data;
        root->left=deleteNode(root->left,iPre->data);
    }
    return root;
    
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
    printf("Enter the node for deletion: ");
    scanf("%d",&key);
    deleteNode(p,key);
    printf("Data at root = %d\n",p->data);
    printf("After deletion: ");
    inorder(p);  
}