#include <stdio.h>
#include <math.h>

float power(float x,int y){
  float temp;
  if(y==0){
    return 1;
  }
  temp=power(x,y/2);

  if(y%2==0){
    return temp*temp;
  }
  else {
    if(y>0){
      return x*temp*temp;
    }
    else{
      return (temp*temp)/x;
    }

    }
}
int main(){
  float x;
  int y;
  printf("Enter the number and the power you want:\n");
  scanf("%f %d",&x,&y);
  printf("The result is %.5f\n",power(x,y));

  return 0;
}
