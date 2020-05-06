#include <stdio.h>

unsigned long int fib(int n){
  unsigned long int i,fibo[100];
  fibo[0]=0;
  fibo[1]=1;

  for(i=2;i<=n;i++){
    fibo[i]=fibo[i-1]+fibo[i-2];
  }
  return fibo[n];
}
int main(){
  int i,n;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    printf("%ld\n",fib(i));
  }

  return 0;
}
