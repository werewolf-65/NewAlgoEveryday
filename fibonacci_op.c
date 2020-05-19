#include <stdio.h>
#include <stdlib.h>
int fib(int n){
	int *fib=(int *)malloc(sizeof(int)*50);
	int i;
	fib[0]=0;
	fib[1]=1;
	for(i=2;i<=n;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	return fib[n];
}

int main(){
	int in;
	printf("Enter the position of Fib no:\n");
	scanf("%d",&in);
	printf("The %d th fibonacci no. is %d\n",in,fib(in));



	return 0;
}
