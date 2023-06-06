#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *new_node;
struct node *head=NULL;
struct node *head2=NULL;
struct node  *temp;
struct node  *p;
struct node *create(struct node *head){
	int a=2;
	while(a!=0){
		new_node=(struct node*)malloc(sizeof(struct node*));
		int s;
		printf("Enter the value of Node: ");
		scanf("%d",&s);
		new_node->data=s;
		if(head==NULL){
			new_node->next=NULL;
			head=new_node;
		}
		else{
			temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=new_node;
			new_node->next=NULL;
		}
		printf("Press 1 to continue creating Nodes, Press 0 to stop: ");
		scanf("%d",&a);
	}
	return head;
}
struct node *display(struct node *head){
	
	if(head->next==NULL){
		printf("%d",head->data);
	}
	else{
		temp=head;
		while(temp->next!=NULL){
			printf("%d  -  ",temp->data);
			temp=temp->next;
			
		}
		printf("%d\n",temp->data);
	}
}
struct node *insert_beg(struct node *head){
	new_node=(struct node*)malloc(sizeof(struct node*));
	int v;
	printf("Enter the value of NODE: ");
	scanf("%d",&v);
	new_node->data=v;
	if(head==NULL){
		head=new_node;
		new_node->next=NULL;
	}
	else{
		new_node->next=head;
		head=new_node;
	}
	printf("NODE inserted at begining.\n");
	return head;
}

struct node *insert_end(struct node *head){
	new_node=(struct node*)malloc(sizeof(struct node*));
	int v;
	printf("Enter the value of NODE: ");
	scanf("%d",&v);
	new_node->data=v;
	if(head==NULL){
		head=new_node;
		new_node->next=NULL;
	}
	else{
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=new_node;
		new_node->next=NULL;
	}
	return head;
}

struct node *insert_random(struct node *head,int loc,int c){
	new_node=(struct node*)malloc(sizeof(struct node*));
	int v;
	printf("Enter the value of NODE: ");
	scanf("%d",&v);
	new_node->data=v;
	if(loc==1){
		new_node->next=head;
		head=new_node;
		printf("Node inserted at %d position.\n",loc);
	}
	else if(loc>c+1){
		printf("Index out of range of the list.\n");
	}
	else if(loc==c+1){
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=new_node;
		new_node->next=NULL;
		printf("Node inserted at %d position.\n",loc);
	}
	else{
		temp=head;
		for(int i=1;i<loc;i++){
			p=temp;
			temp=temp->next;
		}
		p->next=new_node;
		new_node->next=temp;
		printf("Node inserted at %d position.\n",loc);
	}
	return head;
}

struct node *delete_start(struct node *head){
	if(head==NULL){
		printf("Linklist is Empty.\n");
	}
	else if(head->next==NULL){
		free(head);
		printf("Only Node of the list deleted, list is empty now.\n");
	}
	else{
		temp=head;
		head=temp->next;
		free(temp);
		printf("Node deleted from begining of list.\n");
	}
	return head;
}

struct node *delete_end(struct node *head){
	if(head==NULL){
		printf("Linklist is Empty.\n");
	}
	else if(head->next==NULL){
		free(head);
		printf("Only Node of the list deleted, list is empty now.\n");
	}
	else{
		temp=head;
		while(temp->next!=NULL){
			p=temp;
			temp=temp->next;
		}
		p->next=NULL;
		free(temp);
		printf("Node deleted from end of list.\n");
	}
	
}

struct node *delete_random(struct node *head,int loc,int c){
	if(head==NULL){
		printf("List is empty.\n");
	}
	else if(loc==1){
		temp=head;
		head=temp->next;
		free(temp);
		printf("Node deleted from position %d.\n",loc);
	}
	else if(loc==c){
		temp=head;
		while(temp->next!=NULL){
			p=temp;
			temp=temp->next;
		}
		p->next=NULL;
		free(temp);
		printf("Node deleted from position %d.\n",loc);
	}
	else{
		temp=head;
		for(int i=1;i<loc;i++){
			p=temp;
			temp=temp->next;
		}
		p->next=temp->next;
		free(temp);
		printf("Node deleted from position %d.\n",loc);
	}
	return head;
}

struct node *concatenate(struct node *head,struct node *head2){
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=head2;
	printf("New link list concatenated.\n");
}

struct node *reverse(struct node *head){
	struct node *po=NULL;
	p=NULL;
	temp=head;
	while(temp->next!=NULL){
		po=p;
		p=temp;
		temp=temp->next;
		p->next=po;
	}
	temp->next=p;
	head=temp;
	return head;
}

struct node *sorted(struct node *head){
	new_node=(struct node*)malloc(sizeof(struct node*));
	int v;
	printf("Enter the value of NODE: ");
	scanf("%d",&v);
	new_node->data=v;
	temp=head;
	while(temp->data<v){
		p=temp;
		temp=temp->next;
	}
	p->next=new_node;
	new_node->next=temp;
	return head;
	
} 

struct node *duplicate(struct node *head){
	temp=head;
	p=temp->next;
	while(p->next!=NULL){
		if(temp->data!=p->data){
			temp=p;
			p=p->next;
		}
		else{
			temp->next=p->next;
			free(p);
			p=temp->next;
		}
	}
	printf("Duplicate elements deleted.");
}

int count(struct node *head){
	int c=0;
	if(head==NULL){
		return 0;
	}
	else{
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
			c++;
		}
		c+=1;
	}
	return c;
}

int main(){
	int ch,loc,c=1;
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
	printf("Press 11 to insert NOde at sorted position.\n");
	printf("press 12 to delete duplicate Nodes.\n");
	printf("press 20 to exit.\n");
	printf("Enter your choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1:{
				head=create(head);
				c=count(head);
				printf("Linklist created.\n");
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
			printf("Enter the location for node to be inserted: ");
			scanf("%d",&loc);
			head=insert_random(head,loc,c);
			c=count(head);
			break;
		}
		case 6:{
			head=delete_start(head);
			c=count(head);
			break;
		}
		case 7:{
			delete_end(head);
			c=count(head);
			break;
		}
		case 8:{
			printf("Enter the location of the node to be deleted: ");
			scanf("%d",&loc);
			head=delete_random(head,loc,c);
			c=count(head);
			break;
		}
		case 9:{
			head2=create(head2);
			printf("\nNew linklist created.\n");
			display(head2);
			concatenate(head,head2);
			
			break;
		}
		case 10:{
			head=reverse(head);
			break;
		}
		case 11:{
			head=sorted(head);
			break;
		}
		case 12:{
			head=duplicate(head);
			break;
		}
		default:
			printf("Invalid input.\n");
	}
}while(ch!=20);
}

