#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* head;

// void Insert(struct Node** pointer_to_head,int x){
//   struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
//   temp->data=x;
//   temp->next=*pointer_to_head;
//   *pointer_to_head=temp;
// }

void Insert(int x){
  struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
  temp->data=x;
  temp->next=head;
  head=temp;
}

//
void Print(){
  printf("List is:\n");
  struct Node* temp=head;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");
}


int main(){
  // struct Node* head=NULL;
  head=NULL;
  int n,i,x;
  printf("How many numbers?");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("Enter the number:\n");
    scanf("%d",&x);
    // Insert(&head,x);
    Insert(x);
    Print();
  }
  return 0;
}
