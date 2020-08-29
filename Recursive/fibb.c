#include <stdio.h>
#include <stdlib.h>
int fib(int n){
	int a,b,c,i;
	a=0;
	b=1;
	for(i=2;i<=n;i++){
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}

int main(){
	int in;
	printf("Enter the position of Fib no:\n");
	scanf("%d",&in);
	printf("The %d th fibonacci no. is %d\n",in,fib(in));



	return 0;
}
