#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10


struct node{
	int data;
	struct node *next;
};

typedef struct{
	int cnt;
	struct node *top;
}stack;

//initialization

void initialize(stack *stk){
	stk->cnt=0;
	stk->top=NULL;
}

//push
void push(stack *stk,int x){
	if(stk->cnt==STACK_SIZE)
		printf("Stack is full. \n");
	else{
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->data=x;
		temp->next=stk->top;
		stk->cnt++;
		stk->top=temp;
	}
}

//pop
int pop(stack *stk){
	if(stk->cnt==0){
		printf("Stack is empty. \n");
		return -100;		
	}
	else{
		int data=stk->top->data;
		struct node *temp=stk->top;
		stk->top=stk->top->next;
		free(temp);
		return data;	
	}
}


//main
int main(){
	stack s;
	initialize(&s);
	push(&s,3);
	push(&s,5);
	push(&s,7);
	push(&s,11);
	printf("%d \n",pop(&s));
	printf("%d \n",pop(&s));
	printf("%d \n",pop(&s));
	printf("%d \n",pop(&s));

}
