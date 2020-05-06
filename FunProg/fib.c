#include <stdio.h>
int main(){
  int x=0,y=1,z;
  printf("%d\n",x);
  do{
    printf("%d\n",y);
    z=x+y;
    x=y;
    y=z;
  }while (y<255);
  return 0;
}
