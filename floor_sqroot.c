#include <stdio.h>

int floorSqrt(int x){
  int result=1,i=1;
  if(x==0 || x==1){
    return x;
  }
  while(result<=x){
    i++;
    result=i*i;
  }
  return i-1;

}
int main(){
  int x,flosqr;
  printf("Enter any integer: ");
  scanf("%d",&x);
  flosqr=floorSqrt(x);
  printf("The floor square root of %d is %d.\n",x,flosqr);
  return 0;
}
