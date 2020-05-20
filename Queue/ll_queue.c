#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* front=NULL;
struct Node* rear=NULL;

// so the idea is to  enqueue at rear and dequeue at front 
void enqueue(int x){
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=NULL;
	//in case of empty ll 
	if(front==NULL && rear==NULL){
		front=rear=temp;
		return;
	}
	rear->next=temp;
	rear=temp;

}

void dequeue(){
	struct Node* temp=front;
	//case of an empty ll 
	if(front==NULL){
		return;
	}
	//in case of a single element 
	else if(front==rear){
		front=rear=NULL;
	}
	else{
		front=front->next;
	}
	free(temp);
}
//returns the data at the front 
int frontt(){
	return front->data;	
}
//prints the linked list
void print(){
	struct Node* temp=front;
	while(temp != NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	
}

int main(){
	enqueue(5);
	dequeue();
	print();
	enqueue(7);
	enqueue(8);
	enqueue(9);
	enqueue(10);
	dequeue();
	print();
	return 0;
}

