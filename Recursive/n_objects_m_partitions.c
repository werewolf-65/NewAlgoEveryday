/* a program to find the total no of ways in which n items can be partitioned , provided upto m items */
#include <stdio.h>
#include <stdlib.h>

int ways(int n,int m){
	//base case 
	if(n==0){
		return 1;
	}
	if(m==0 || n<0){
		return 0;
	}
	return ways(n,m-1)+ways(n-m,m);
}
int main(int argc,char* argv[]){
	printf("Total no of ways:%d\n",ways(atoi(argv[1]),atoi(argv[2])));
	return 0;
}

