#include <stdio.h>
#include <stdlib.h>

//Queue Node
struct node{
	int data;
	struct node *next;
};


//Front & Rear
struct node *front=NULL;
struct node *rear=NULL;

//Enquene
int enquene(int data){
	if(front==NULL){
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data=data;
		temp->next=NULL;
		
		front = rear = temp;
	}
	else{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data=data;
		temp->next=NULL;
		
		rear->next=temp;
		rear=temp;
	}
}

//dequeue
int dequeue(){
	if(front==NULL){
		printf("Queue is empty. \n");
	}
	else{
		struct node *temp=front;
		front=front->next;
		free(temp);
	}
	
	return 0;
}

//display queue
int display(){
	
	if(front==NULL){
		printf("Queue is empty. \n"); 
	}
	
	struct node *index=front;
	while (index!=NULL){
		printf("%d - ",index->data);
		index=index->next;
	}
	
	return 0;
}


//main
int main(){
	
	enquene(5);
	enquene(6);
	enquene(8);
	enquene(10);
	display();
	
	dequeue();
	display();
	
	return 0;
}
