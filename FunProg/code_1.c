#include <stdio.h>
#include <math.h>
int main(){
  int n=786432,count=0,x=1;
  float sqr;
  sqr=sqrt(n);
  while(sqr!=(int)sqr){
    n=n*x;
    sqr=sqrt(n);
    x++;
    count++;
  }
printf("%d\n",count);
printf("%d\n",sqr);
  return 0;
}
