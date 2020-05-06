#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* head;

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
  while(head!=NULL){
    printf("%d",head->data);
    head=head->next;
    printf("\n");
  }
  printf("\n");

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
  return 0;
}
