#include <stdio.h> 
#include <stdlib.h>
struct Node{
	int data;
	struct Node* next;
};

struct Node *head=NULL; // empty stack initialized 
struct Node * stack[20];
int top=-1;
//operations for stack 
void Push(struct Node* x){
	top++;
	stack[top]=x;
}

void Pop(){
	if(top==-1){
		return;
	}
	top--;
}

struct Node* Top(){
	return stack[top];
}

void Reverse(){
	if(head==NULL) return;
 	struct Node* temp=head;
	while(temp != NULL){
		Push(temp);
		temp=temp->next;
}
	temp=Top();
	head=temp; 
	Pop();
	while(top != -1){
		temp->next=Top();
		Pop();
		temp=temp->next;
	}
	temp->next=NULL;
}
//operations for the linked list 
void Insert(int data,int n){
  int i;
  struct Node* temp1=(struct Node*)malloc(sizeof(struct Node));
  temp1->data=data;
  temp1->next=NULL;
  if(n==1){
    temp1->next=head;
    head=temp1;
    return;
  }

  struct Node* temp2=head;
  for(i=0;i<n-2;i++){
    temp2=temp2->next;
  }
  temp1->next=temp2->next;
  temp2->next=temp1;
}

void Print(){

  printf("List is:\n");
  struct Node* temp=head;
  while(temp!=NULL){
    printf("%d",temp->data);
    temp=temp->next;
    printf("\n");
  }
  printf("\n");

}


int main(){
  head=NULL;
  char choice='y';

  Insert(2,1);
  Insert(3,2);
  Insert(4,3);
  Print();
	
  Reverse();
  Print();
  return 0;
}

