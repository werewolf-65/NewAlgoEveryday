#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int sumton(int n){
	if(n==0){
		return 0;
	}
	else{
		return n+sumton(n-1);
	}
}

int main(int argc,char* argv[]){
	printf("%d\n",sumton(atoi(argv[1])));
	return 0;
}
