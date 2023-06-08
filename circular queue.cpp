#include<stdio.h>
# define N 5
int front=-1,rear=-1,queue[N];
void enqueue(int x){
	if((rear+1)%N==front){
		printf("Overflow condition.\n");
	}
	else if(front==-1 && rear==-1){
		front =rear=0;
		queue[rear]=x;
		printf("Element inserted\n");
	}
	else{
		rear=(rear+1)%N; 
		queue[rear]=x;
		printf("Element inserted\n");
	}
}
void dequeue(){
	if(front==-1 && rear==-1){
		printf("queue is underflow.\n");
	}
	else if(front==rear){
		printf("element poped=%d\n",queue[front]);
		front=rear=-1;
		
	}
	else{
		printf("element poped=%d\n",queue[front]);
		front=(front+1)%N;
	}
}
void display(){
	int i=front;
	if(front==-1 && rear==-1){
		printf("Queue is empty\n");
	}
	else{
		while(i!=rear){
			printf("%d\n",queue[i]);
			i=(i+1)%N;
		}
		printf("%d",queue[rear]);
	}
}
void peek(){
	if(front==-1 && rear==-1){
		printf("Queue is empty\n");
	}
	else{
		printf("Data at front is %d\n",queue[front]);
	}
}
int main(){
	int ch;
	do{
	
	printf("MEnu\n");
	printf("Press 1 to enqueue\n");
	printf("Press 2 to dequeue\n");
	printf("Press 3 to display\n");
	printf("Press 4 to peek\n");
	printf("Press 5 to exit\n");
	printf("Enter your choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			{
				int x;
				printf("Enter element to be inserted: ");
				scanf("%d",&x);	
				enqueue(x);
			}
			break;
		case 2:{
			dequeue();
			break;
		}
		case 3:{
			display();
			break;
		}
		case 4:{
			peek();
			break;
		}
		case 5:{
			printf("Thank you.");
			break;
		}
		
	}
}while(ch!=5);
	
}
