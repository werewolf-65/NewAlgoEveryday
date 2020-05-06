#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

// struct Node* head;

struct Node* Insert(struct Node* head,int data,int n){
  int i;
  struct Node* temp1=(struct Node*)malloc(sizeof(struct Node));
  temp1->data=data;
  temp1->next=NULL;
  if(n==1){
    temp1->next=head;
    head=temp1;
    return head;
  }

  struct Node* temp2=head;
  for(i=0;i<n-2;i++){
    temp2=temp2->next;
  }
  temp1->next=temp2->next;
  temp2->next=temp1;

  return head;
}

void Print(struct Node* p){
  if(p==NULL){
    printf("\n");
    return;
  }
  printf("%d\t",p->data);
  Print(p->next);
}

void ReversePrint(struct Node* p){
  if(p==NULL){
    printf("\n");
    return;
  }
  ReversePrint(p->next);
  printf("%d\t",p->data);
}

struct Node* Reverse(struct Node* p){
  struct Node* head=NULL;
  if(p->next==NULL){
    head=p;
    return head;
  }
  struct Node* rest=Reverse(p->next);
  struct Node* q;
  q=p->next;
  q->next=p;
  p->next=NULL;
  return rest;
}



int main(){
  struct Node* head=NULL;
  head=Insert(head,2,1);
  head=Insert(head,3,2);
  head=Insert(head,2,1);
  head=Insert(head,5,2);
  printf("In regular order:\n");
  Print(head);
  printf("List reversed:\n");
  head=Reverse(head);
  Print(head);

  return 0;
}
