#include <stdio.h>
#include <stdlib.h>
int fib(int n,int* memo){
	int i;
	/* base case */ 
	if(n<=2){
		return 1;
	}
	/*check memo if entry matches */ 
	if (memo[n]>0){
		return memo[n];
	}
	memo[n]=fib(n-1,memo) + fib(n-2,memo);
	return memo[n];
}

int main(){
	int in;
	int *memo=(int *)calloc(1000,sizeof(int));
	printf("Enter the position of Fib no:\n");
	scanf("%d",&in);
	printf("The %d th fibonacci no. is %d\n",in,fib(in,memo));



	return 0;
}
