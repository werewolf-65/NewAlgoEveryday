#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* head;
int sizeofll=0;

void Insert(int data,int n){
  int i;
  struct Node* temp1=(struct Node*)malloc(sizeof(struct Node)); //new node to be added
  temp1->data=data;
  temp1->next=NULL;
  if(n==1){
    temp1->next=head;
    head=temp1;
    return;
  }

  struct Node* temp2=head; //existing linked list part , combine the two
  for(i=0;i<n-2;i++){
    temp2=temp2->next; //gets the n-1 th node
  }
  temp1->next=temp2->next;
  temp2->next=temp1;
}

void Print(){
  sizeofll=0;
  struct Node *temp=head;
  printf("List is:\n");
  while(temp!=NULL){
    printf("%d",temp->data);
    temp=temp->next;
    sizeofll+=1;
    printf("\n");
  }
  printf("\n");
}

void Delete(int n){ //Deletes a node at position n
  struct Node* temp1=head;
  if(n==1){
    head=temp1->next;
    free(temp1);
    return;
  }
  if(n>sizeofll){
    printf("Invalid");
    return;
  }

  int i;
  for(i=0;i<n-2;i++){
    temp1=temp1->next; //gets the n-1 th node , now to link n-1 th node to n+1 th node
  }
  struct Node *temp2=temp1->next; //nth node , node to be deleted
  temp1->next=temp2->next;
  free(temp2);
}


int main(){
  head=NULL;
  char choice='y';

  Insert(2,1);
  Insert(3,2);
  Insert(5,1);
  Insert(5,2);
  Insert(4,3);
  Insert(5,3);
  Print();
  Delete(2);
  Print();
  return 0;
}
