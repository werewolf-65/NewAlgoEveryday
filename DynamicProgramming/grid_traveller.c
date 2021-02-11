#include <stdio.h>
#include <stdlib.h>


int grid_traveller(int m,int n,int** memo){
	if(m==0 || n==0){
		return 0;
	}
	if(m==1 && n==1){
		return 1;
	}

	if(memo[m][n]>0){
		return memo[m][n];
	}
	memo[m][n]=grid_traveller(m,n-1,memo)+grid_traveller(m-1,n,memo);
	return memo[m][n];
}


int main(){
	int m,n,i,j;
	int** memo;
	printf("Enter the number of rows and columns:\n");
	scanf("%d %d",&m,&n);

	memo=(int**)malloc(sizeof(int *)*(m+1));
	
	for(i=0;i<=m;i++){
		memo[i]=(int *)malloc(sizeof(int)*(n+1));
	}

	for(i=0;i<=m;i++){
		for(j=0;j<=m;j++){
			memo[i][j]=0;
		}
	}
	
	printf("The total no of paths is %d\n",grid_traveller(m,n,memo));

	for(i=0;i<=m;i++){
		free(memo[i]);
	}
	free(memo);
	
	return 0;
}
	

