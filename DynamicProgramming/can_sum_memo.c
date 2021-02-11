#include <stdio.h>
#include <stdlib.h>

int can_sum(int target_sum,int len_arr,int* num_arr,int* memo){
	int i,remainder;
	/*base case */ 
	if(target_sum==0){
		return 1;
	}
	if(target_sum<0){
		return 0;
	}

	if(memo[target_sum]>=0){
		return memo[target_sum];
	}
	/* iterate through the num_arr */ 
	for(i=0;i<len_arr;i++){
		remainder=target_sum-num_arr[i];
		if(can_sum(remainder,len_arr,num_arr,memo)==1){
			memo[target_sum]= 1;
			return 1;
		}
	}	
	memo[target_sum]=0;
	return 0;

}


int main(){
	int target_sum; 
	int* num_array;
	int len_arr,i;
	int *memo;
	printf("Enter the target sum:\t");
	scanf("%d",&target_sum);

	printf("Enter the length of array:\t");
	scanf("%d",&len_arr);
	
	num_array=(int *)malloc(sizeof(int)*len_arr);
	printf("Enter the array of numbers:\n");	
	for(i=0;i<len_arr;i++){
		scanf("%d",&num_array[i]);	
	}
 	memo=(int *)malloc(sizeof(int *)*(len_arr+1));
	for(i=0;i<=target_sum;i++){
			memo[i]=-1;
	}

	

	can_sum(target_sum,len_arr,num_array,memo)?printf("Possible"):printf("Not possible");
	
	for(i=0;i<=target_sum;i++){
		printf("%d\n",memo[i]);	
	}


	return 0;
}
