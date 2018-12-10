#include <stdio.h>

void swap(int *a,int *b){
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

void bubbleSort(int arr[],int arr_size){
  int i,j;

  for(i=0;i<arr_size-1;i++){
    for(j=0;j<arr_size-i-1;j++){
      if(arr[j]>arr[j+1]){
          swap(&arr[j],&arr[j+1]);
      }
    }
  }
}

void printArray(int arr[],int size){
  int i;
  for(i=0;i<size;i++){
    printf("%d ",arr[i] );
  }
}

int main() {
  int arr[]={22,13,24,56,65,43};
  int arr_size;
  arr_size=sizeof(arr)/sizeof(arr[0]);
  bubbleSort(arr,arr_size);
  printArray(arr,arr_size);
  return 0;
}
