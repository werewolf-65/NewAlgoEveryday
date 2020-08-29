/*A program to calculated the total no of paths from top left to bottom right of a m*n matrix*/
//can only move right and down 1 step at a time 
#include <stdio.h>
#include <stdlib.h>

//as an input we will have the dimensions of a*b matrix 
int distance(int m,int n){
	//base condition 
	if(m==1 || n==1){
		return 1;
	}
	else{
		return distance(m-1,n)+distance(m,n-1);
	}
}

int main(int argc,char* argv[]){
	printf("Distance:%d\n",distance(atoi(argv[1]),atoi(argv[2])));
	return 0;
}
