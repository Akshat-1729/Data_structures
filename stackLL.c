#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
struct node* new_node;
struct node* temp;
struct node *push(struct node* head){
    new_node=(struct node*)malloc(sizeof(struct node*));
    printf("Enter data:-");
    scanf("%d",&new_node->data);
    if(head==NULL){
        head=new_node;
        head->next=NULL;
    }
    else{
        new_node->next=head;
        head=new_node;
    }
    return head;
}
struct node *pop(struct node* head){
    if(head==NULL){
        printf("stack underflow condition\n");
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
    }
    return head;
}
struct node *display(struct node *head){
    temp=head;
    while(temp->next!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
int main(){
    int ch;
    do{
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.display\n");
    printf("Enter choice: ");
    scanf("%d",&ch);
    switch(ch){
        case 1:{
            head=push(head);
            break;
        }
        case 2:{
            head=pop(head);
            break;
        }
        case 3:{
            display(head);
            break;
        }
    }
}
    while(ch!=0);
}