#include <stdio.h> 
#include <stdlib.h>
struct Node{
	int data;
	struct Node* link;
};

struct Node *top=NULL; // empty stack initialized 

void Push(int x){
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
	temp->data=x;
	temp->link=top;
	top=temp;
}

void Pop(){
	struct Node* temp ; 
	if(top==NULL) return; 
	temp=top;
	top=top->link;
	free(temp);
}

int Top(){
	return top->data;
}

void Print(){
	struct Node* temp=top;
	while(temp!=NULL){
		printf("%d",temp->data);
		temp=temp->link;
	}
	printf("\n");
}

int main(){
	Push(5);Print();
	Push(6);Print();
	Push(7);Print();
	Pop();Print();
	Push(8);Print();
	Pop();Print();
	return 0;
}	
	
