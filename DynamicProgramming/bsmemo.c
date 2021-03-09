#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int can_sum(int target_sum,int original_sum,int len_arr,int* num_arr,int* memo,int* return_array,int* ret_arr_len,int** ret_array_list,int* ret_array_index,int given_start_index){
	int i,remainder,start_index;
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

	if(target_sum==original_sum){
		start_index=given_start_index;
	}
	else{
		start_index=0;
	}

	/* iterate through the num_arr */ 
	for(i=2;i<len_arr;i++){
		remainder=target_sum-num_arr[i];
		if(can_sum(remainder,original_sum,len_arr,num_arr,memo,return_array,ret_arr_len,ret_array_list,ret_array_index,start_index)==1){
			return_array[(ret_arr_len[*ret_array_index])++]=num_arr[i];
			memo[target_sum]= 1;

			if(target_sum == original_sum){
				memcpy(ret_array_list[(*ret_array_index)++],return_array,sizeof(int)*(ret_arr_len[i]));
				*ret_array_index;
			}
		return 1;
		}
	}
	memo[target_sum]=0;
	return 0;

}


int main(){
	int target_sum; 
	int* num_array;
	int len_arr,i,j;
	int* return_array;
	int** ret_array_list;
	int ret_array_index=0;
	int* ret_arr_len; //tracks the return array length 
	int complete_check_flag=0; //checks whether all combinations have been checked
	int *memo;
	int ret;
	printf("Enter the target sum:\t");
	scanf("%d",&target_sum);

	printf("Enter the length of array:\t");
	scanf("%d",&len_arr);
	
	return_array=(int *)malloc(sizeof(int)*target_sum);
	ret_arr_len=(int *)malloc(sizeof(int)*target_sum);
	ret_array_list=(int**)malloc(sizeof(int *)*(target_sum+1));	

	for(i=0;i<=target_sum;i++){
		ret_array_list[i]=(int *)malloc(sizeof(int)*(target_sum+1));
	}
	/* populate return_array with 0s */
	for(i=0;i<target_sum;i++){
		return_array[i]=0;
		ret_arr_len[i]=0;
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

	
for(i=0;i<len_arr;i++){
	can_sum(target_sum,target_sum,len_arr,num_array,memo,return_array,ret_arr_len,ret_array_list,&ret_array_index,1)?printf("Possible"):printf("Not possible");
	
// 	while(complete_check_flag != len_arr-1){
// 		can_sum(target_sum,target_sum,len_arr,num_array,memo,return_array,ret_arr_len,ret_array_list,&ret_array_index,&complete_check_flag);
// 	}
// 	for(i=0;i<=target_sum;i++){
// 		printf("%d\n",memo[i]);	
// 	}
// 
	printf("\n");
// 	for(i=0;i<ret_arr_len;i++){
// 		printf("%d+",return_array[i]);
// 	}
	for(j=0;j<ret_arr_len[i];j++){
		printf("%d+",ret_array_list[i][j]);
	}
	printf("\n");
	
}
	
// 	(complete_check_flag==len_arr-1)?printf("Completely checked"):printf("Not completely checked");
	
	
	return 0;
}
