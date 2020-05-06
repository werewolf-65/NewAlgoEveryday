#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101
int A[MAX_SIZE]; //our stack to be
int top=-1; //top of the stack

void Push(int x){
  if(top==MAX_SIZE-1){
    printf("Reached max limit");
    return;
  }
  A[++top]=x;
}

void Pop(){
  if(top==-1){
    printf("empty stack");
    return;
  }
  top--;
}

int Top(){
  return A[top];
}
void Print(){
  int i;
  for(i=0;i<top+1;i++){
    printf("%d\t",A[i]);
  }
  printf("\n");
}

int main(){
  Push(5);Print();
  Push(7);Print();
  Push(9);Print();
  Pop();Print();
  Push(13);Print();
  Pop();Print();
  return 0;
}
