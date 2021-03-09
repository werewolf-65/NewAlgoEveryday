#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int can_sum(int target_sum,int len_arr,int* num_arr,int* memo,int* return_array,int* ret_arr_len,int* best_array,int* best_len){
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
		if(can_sum(remainder,original_target_sum,len_arr,num_arr,memo,return_array,ret_arr_len,best_array,best_len)==1){
			return_array[(*ret_arr_len)++]=num_arr[i];
			memo[target_sum]= 1;
			combination_found_flag=1;

		if(target_sum == original_target_sum){ //idea is to update best array once every iteration 
		printf("I'm here\n");
		if(*ret_arr_len < *best_len){
			*best_len=*ret_arr_len;
			for(i=0;i<*best_len;i++){
				printf("%d\n",return_array[i]);
			}

			printf("----------------\n");
			memcpy(best_array,return_array,sizeof(int)*(*best_len));	//best_array=return_array;
// 			for(i=0;i<*best_len;i++){
// 				printf("%d\n",best_array[i]);
// 			}
// 			printf("-------------");
		}
	}	

		combination_found_flag=0;
// 		return 1;
		}
}
	memo[target_sum]=0;
	if(combination_found_flag==1){
		return 1;
	}
	else{
		return 0;
	}
}


int main(){
	int target_sum; 
	int* num_array;
	int len_arr,i;
	int best_length; //best length of combination i.e. the shortest 
	int* return_array,*best_array;
	int ret_arr_len=0; //tracks the return array length 
	int best_arr_len;
	int *memo;
	printf("Enter the target sum:\t");
	scanf("%d",&target_sum);

	printf("Enter the length of array:\t");
	scanf("%d",&len_arr);
	
	return_array=(int *)malloc(sizeof(int)*target_sum);
	best_array=(int *)malloc(sizeof(int)*target_sum);
	
	best_arr_len=target_sum+10; //best array's length initialized to a large no
	/* populate return_array with 0s */
	for(i=0;i<target_sum;i++){
		return_array[i]=0;
	}

	num_array=(int *)malloc(sizeof(int)*len_arr);
	printf("Enter the array of numbers:\n");	
	for(i=0;i<len_arr;i++){
		scanf("%d",&num_array[i]);	
	}
 	memo=(int *)malloc(sizeof(int *)*(len_arr+1));
	for(i=0;i<=target_sum;i++){
			memo[i]=-1;
	}

	

	can_sum(target_sum,target_sum,len_arr,num_array,memo,return_array,&ret_arr_len,best_array,&best_arr_len)?printf("Possible"):printf("Not possible");
	
// 	for(i=0;i<=target_sum;i++){
// 		printf("%d\n",memo[i]);	
// 	}
// 
	printf("\n");
	for(i=0;i<best_arr_len;i++){
		printf("%d+",best_array[i]);
	}


	return 0;
}
