#include <stdio.h>
//C program to demonstrate selection sort
//Two subarrays: sorted and unsorted subarray

void swap(int *a,int *b){
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

void selectionSort(int arr[],int arr_size){
  int i,j,min_idx;

  // One by one move boundary of unsorted subarray
  for(i=0;i<arr_size-1;i++){

    //Find the minimum element in unsorted subarray
    min_idx=i;
    for(j=i+1;j<arr_size;j++){
      if(arr[j]<arr[min_idx]){
        min_idx=j;
      }
    }

    //Swap the found min element with the first element of the loop
    swap(&arr[min_idx],&arr[i]);
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
  selectionSort(arr,arr_size);
  printArray(arr,arr_size);
  return 0;
}
