#include <stdio.h>
int main(){
  int num,i,sum=0;
  scanf("%d",&num);
  for(i=1;i<num;i++){
    if(num%i==0){
      sum=sum+i;
    }
    else{
      continue;
    }
  }
  if(sum==num){
    printf("Magic number!\n");
  }
  else{
    printf("Not a magic number!");
  }
  return 0;
}
//No equal to the sum of its factors(not counting itself)
