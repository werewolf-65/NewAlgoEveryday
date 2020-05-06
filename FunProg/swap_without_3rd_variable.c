/*Swap two integers without third variable*/
#include <stdio.h>
int main(){
int x=4,y=5;
printf("x=%d y=%d\n",x,y);
x=x+y;
y=x-y;
x=x-y;
printf("x=%d y=%d\n",x,y);
return 0;
}
