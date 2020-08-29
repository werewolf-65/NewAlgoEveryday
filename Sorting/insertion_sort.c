#include <stdio.h>
#include <stdlib.h>

int* insertion_sort(int* arr,int arrsize){
	int i,j,temp;
	for(i=0;i<arrsize;i++){
		if(arr[i]<arr[0]){
			temp=arr[i];
			for(j=i;j>0;j--){
				arr[j]=arr[j-1];
			}
			arr[0]=temp;
		}
	}
	return arr;
}

int main(){
	int arr[]={4,3,5,7,2,1};
	int arrsize=sizeof(arr)/sizeof(arr[0]);
	int* sorted_arr=(int *)malloc(sizeof(int)*arrsize);
	int i;
	
	sorted_arr=insertion_sort(arr,arrsize);
	
	for(i=0;i<arrsize;i++){
		printf("%d\t",sorted_arr[i]);
	}
	printf("\n");
}
	
	
