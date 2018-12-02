#include <stdio.h>
int main(){
  int arr[]={2,4,6,7,9,10,11};
  printf("%d",sizeof(arr)/sizeof(arr[0]));
  return 0;
}
