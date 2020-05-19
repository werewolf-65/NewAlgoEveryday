#include <stdio.h>
#include <stdlib.h> 
#define N 10
int queue[N]={0,0,0,0,0,0,0,0,0,0};
int rear=-1;
int front=-1;
void enqueue(int x);
void dequeue();
int frontt();
void print();
int is_empty();


int main(){
	enqueue(5);
	print();
	enqueue(7);
	enqueue(8);
	dequeue();
	print();
	printf("The element at the front is %d",frontt());
	return 0;
}

//modular signs are needed to make the queue circular 

void enqueue(int x){
	if((rear+1)%N==front){//return if FULL 
		return;
	}
	else if(is_empty()){
		rear=0;
		front=0; 
	}
	else{
		rear=(rear+1)%N;
	
	}
	queue[rear]=x;
}

void dequeue(){
	if(is_empty()){
		return ; 
	}
	else if(front==rear){// in case of a single element 
		front=-1;
		rear=-1;
	}
	else{
		front=(front+1)%N;
	}
}

int is_empty(){
	if(rear==-1 && front==-1){
		return 1;
	}
	return 0;
}

int frontt(){
	return queue[front];
}

void print(){
	int i;
	for(i=front;i<=rear;i++){
		printf("%d\t",queue[i]);
	}
	printf("\n");
}
