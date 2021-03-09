#include <stdio.h>
#include <stdlib.h>


int grid_traveller(int m,int n){
	/* returns the total no of ways to travel from (1,1) to (m,n) */ 
	int i,j;	
	//create a table first 
	//in this case, a 2 dimensional table of size (m+1) * (n+1) 

	int **grid;
	
	grid=(int **)malloc(sizeof(int *)*(m+1));
	
	for(i=0;i<m+1;i++){
		grid[i]=(int *)malloc(sizeof(int)*(n+1));
	}

	//fill with zeroes
	for(i=0;i<m+1;i++){
		for(j=0;j<n+1;j++){
			grid[i][j]=0;
		}
	}

	//trivial case (base case)
	grid[1][1]=1;

	//fill other positions based on the current position 
	
	for(i=0;i<m+1;i++){
		for(j=0;j<n+1;j++){
			//add current position
			//to the right position 
			if((j+1)<=n){
				grid[i][j+1]+=grid[i][j];
			}
			//to the down position 

			if((i+1)<=n){
				grid[i+1][j]+=grid[i][j];	
			}
		}
	}
	return grid[m][n];
}
int main(int argc,char* argv[]){
	int m,n;

	if(argc != 3){
		printf("Usage:./grid m n\n");
		exit(-1);
	}
	m=(int)strtol(argv[1],NULL,10);
	n=(int)strtol(argv[2],NULL,10);

	printf("No of ways to traverse in a m*n grid:%d\n",grid_traveller(m,n));

	return 0;
}
