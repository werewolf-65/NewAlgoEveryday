#include <stdio.h>
int search(int arr[],int n,int x);
int main(){
  int arr[]={10,20,30,40,50},i,n;
  n=5;
  for(i=0;i<5;i++){
    printf("%d ",arr[i]);
  }
  search(arr,5,60);
  return 0;
}

int search(int arr[5],int n,int x){
  int i;
  for(i=0;i<n;i++){
    if(arr[i]==x){
      printf("\n%d found at %d",x,i);
      return 0;
    }
  }
 return -1;//for element not found
}
