#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *new_node;
struct node *head=NULL;
struct node *head2=NULL;
struct node  *temp;
struct node  *temp2;
struct node  *p;
struct node *create(struct node *head){
    int a=2;
    while (a!=0)
    {
        /* code */
        new_node=(struct node*)malloc(sizeof(struct node*));
        printf("Enter the data of node:- ");
        scanf("%d",&new_node->data);
        if(head==NULL){
            head=new_node;
            head->next=NULL;
            head->prev=NULL;
        }
        else{
            temp=head;
            while (temp->next!=NULL)
            {
                /* code */
                p=temp;
                temp=temp->next;
                temp->prev=p;
            }
            temp->next=new_node;
            new_node->prev=temp;
            new_node->next=NULL;
        }
        printf("Press any key to continue , else press 0: ");
        scanf("%d",&a);
    }
    printf("New list created.\n");
    return head;
}
struct node *display(struct node *head){
    temp=head;
    while(temp->next!=NULL){
        printf("%d -- ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}
struct node *insert_beg(struct node *head){
    new_node=(struct node *)malloc(sizeof(struct node *));
    printf("Enter the value of node: ");
    scanf("%d",&new_node->data);
    new_node->next=head;
    head->prev=new_node;
    new_node->prev=NULL;
    head=new_node;
    printf("Node inserted at begining.\n");
    return head;
}
struct node *insert_end(struct node *head){
    new_node=(struct node *)malloc(sizeof(struct node *));
    printf("Enter the value of node: ");
    scanf("%d",&new_node->data);
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->prev=temp;
    new_node->next=NULL;
    printf("Node inserted at end of list.\n");
}
struct node *insert_rand(struct node *head,int c){
    new_node=(struct node *)malloc(sizeof(struct node *));
    printf("Enter the value of node: ");
    scanf("%d",&new_node->data);
    printf("Enter the position to insert the node: ");
    int pos;
    scanf("%d",&pos);
    if(pos==1){
        new_node->next=head;
        head->prev=new_node;
        new_node->prev=NULL;
        head=new_node;
        printf("Node inserted at position %d\n",pos);
    }
    else if(pos>c+1){
        printf("Index out of range.\n");
    }
    else if(pos==c+1){
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->prev=temp;
        new_node->next=NULL;
        printf("Node inserted at position %d\n",pos);
    }
    else{
        temp=head;
        for(int i=1;i<pos;i++){
            p=temp;
            temp=temp->next;
        }
        p->next=new_node;
        new_node->prev=p;
        new_node->next=temp;
        temp->prev=new_node;
        printf("Node inserted at position %d\n",pos);
    }
    return head;

}
struct node *delete_beg(struct node *head){
    temp=head;
    head=head->next;
    free(temp);
    head->prev=NULL;
    printf("Node deleted from begining.\n");
    return head;
}
struct node *delete_end(struct node *head){
    temp=head;
    while(temp->next!=NULL){
        p=temp;
        temp=temp->next;
    }
    free(temp);
    p->next=NULL;
    printf("Node deleted from end.\n");
}
struct node *delete_rand(struct node *head,int c){
    printf("Enter position from where Node is to be deleted: ");
    int pos;
    scanf("%d",&pos);
    if(pos>c){
        printf("Index out of range.\n");
    }
    else if(pos==1){
        temp=head;
        head=head->next;
        free(temp);
        head->prev=NULL;
        printf("Node deleted from begining.\n");
    }
    else if(pos==c){
        temp=head;
        while(temp->next!=NULL){
            p=temp;
            temp=temp->next;
        }
        free(temp);
        p->next=NULL;
        printf("Node deleted from position %d\n",pos);
    }
    else{
        temp=head;
        for(int i=1;i<pos;i++){
            p=temp;
            temp=temp->next;
        }
        p->next=temp->next;
        temp->next->prev=p;
        free(temp);
        printf("Node deleted from position %d\n",pos);
    }
    return head;
}
struct node *con(struct node *head,struct node *head2){
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
    head2->prev=temp;

}
struct node *reverse(struct node *head){
    struct node *first=NULL;
    struct node *sec=head;
    while(sec!=NULL){
        first=sec->prev;
        sec->prev=sec->next;
        sec->next=first;
        sec=sec->prev;
    }
    if(first!=NULL){
        head=first->prev;
    }
    return head;

}
int count(struct node *head){
    temp=head;
    int count=1;
    while(temp->next!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
    int main()
    {
        int ch,a,c;
        do{
        printf("\nMENU\n");
        printf("Press 1 to create a linked list.\n");
        printf("Press 2 to display the linked list.\n");
        printf("Press 3 to insert Node at begining of linked list.\n");
        printf("Press 4 to insert Node at end of linked list.\n");
        printf("Press 5 to insert Node at random position of linked list.\n");
        printf("Press 6 to delete Node from start.\n");
        printf("Press 7 to delete Node from end.\n");
        printf("Press 8 to delete Node from random position.\n");
        printf("Press 9 to concatenate another linklist in the existing one.\n");
        printf("Press 10 to reverse the linklist.\n");
        printf("press 11 to exit.\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                head=create(head);
                c=count(head);
                break;
            }
            case 2:{
                display(head);
                break;
            }
            case 3:{
                head=insert_beg(head);
                c=count(head);
                break;
            }
            case 4:{
                insert_end(head);
                c=count(head);
                break;
            }
            case 5:{
                head=insert_rand(head,c);
                c=count(head);
                break;
            }
            case 6:{
                head=delete_beg(head);
                c=count(head);
                break;
            }
            case 7:{
                delete_end(head);
                c=count(head);
                break;
            }
            case 8:{
                head=delete_rand(head,c);
                c=count(head);
                break;
            }
            case 9:{
                printf("create a new list.\n");
                head2=create(head2);
                con(head,head2);
                c=count(head);
                break;
            }
            case 10:{
                head=reverse(head);
                break;
            }
        }
        }while(ch!=11);
        
    }
 

