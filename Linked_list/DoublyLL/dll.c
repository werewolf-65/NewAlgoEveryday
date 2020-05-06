#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* prev;
  struct Node* next;
};

struct Node* head;

struct Node* GetNewNode(int x){
  struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
  newNode->data=x;
  newNode->prev=NULL;
  newNode->next=NULL;
  return newNode;
}

void InsertAtHead(int x){
  struct Node* newNode=GetNewNode(x);
  if(head==NULL){
    head=newNode;
    return;
  }
  head->prev=newNode;
  newNode->next=head;
  head=newNode;
}
void InsertAtTail(int x){
  struct Node* newNode=GetNewNode(x);
  if(head==NULL){
    head=newNode;
    return;
  }
  struct Node* temp=head;
  //traverse to the last node
  while(temp->next != NULL){ // temp should be our last node
    temp=temp->next;
  }
  newNode->prev=temp;
  temp->next=newNode;
}

void Print(){
  struct Node* temp=head;
  printf("Forward:\n");
  while(temp != NULL){
    printf("%d\t",temp->data);
    temp=temp->next;
  }
  printf("\n");
}

void ReversePrint(){
  struct Node* temp=head;
  printf("Backward:\n");
  //traverse to the last node
  while(temp->next != NULL){ // temp should be our last node
    temp=temp->next;
  }
  // traversing backwatd using prev pointer
  while(temp!=NULL){
    printf("%d\t",temp->data);
    temp=temp->prev;
  }
  printf("\n");
}


int main(){
  head=NULL;
  InsertAtHead(1);
  InsertAtHead(2);
  InsertAtHead(3);
  InsertAtTail(4);
  Print();
  ReversePrint();


}
