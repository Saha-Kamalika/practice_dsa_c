#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head;
int checkCir(){
    if(head==NULL) return 0;
    struct node* ptr=head->next;
    while(ptr!=NULL && ptr!=head) ptr=ptr->next;
    return (ptr==head);
}
struct node* newNode(int data){
    struct node* nnode=(struct node*)malloc(sizeof(struct node));
    nnode->data=data;
    nnode->next=NULL;
    return nnode;
}
void main(){
    head=newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = head;
    if(checkCir(head)) printf("Circular");
    else printf("Not Circular");
  
}
