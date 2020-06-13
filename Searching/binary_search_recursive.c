/*C Program for Recursive Binary Search -Works in Sorted array only.*/
#include <stdio.h>
#include <stdlib.h>

int bin_search(int arr[],int start,int end,int x){
  //start and end are the indices for the binary search to operate
  //x is the element to be found in the array arr[]
  int mid_index;

  if(start<end){
    mid_index=(start+end)/2;
    if(x==arr[mid_index]){
      return mid_index;
    }
    else if(x<arr[mid_index]){
      return bin_search(arr,start,mid_index-1,x);
    }
    else if(x>arr[mid_index]){
      return bin_search(arr,mid_index+1,end,x);
    }
  }
  else{
    return -1;
  }
}
int main(){
  int arr[]={2,4,6,7,9,10,11,12},arr_size;
  int position_x;
  int x=10; //the element whose postiion is to be found

  arr_size=sizeof(arr)/sizeof(arr[0]);
  position_x=bin_search(arr,0,arr_size-1,x);
  position_x==-1?printf("%d not found!",x):printf("%d found at %d!\n",x,position_x);
  return 0;
}
