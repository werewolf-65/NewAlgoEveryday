#include <stdio.h> 
#include <stdlib.h> 

int* count_sort(int *A,int size){
	int* count=(int *)calloc(size-1,sizeof(int));
	int* pos=(int*)calloc(size-1,sizeof(int));
	int* Ar=(int *)calloc(size,sizeof(int));
	int i,j; 
	for (i=1;i<size;i++){
		count[A[i]]=count[A[i]]+1;
	}
	//we have now updated the count of each elements in the original array into the count array 
	//now give the positions at which each element start 
	pos[1]=1;
	for (j=2;j<size;j++){
		pos[j]=pos[j-1]+count[j-1];
	}
	for (i=1;i<size;i++){
		Ar[pos[A[i]]] =A[i];
		pos[A[i]]=pos[A[i]]+1;

	}
	return Ar;
}	

int main(){
	int arr[]={1,1,2,3,4,5,2,1};
	int size=sizeof(arr)/sizeof(arr[0]);
	int i;
	int *ret=(int*)malloc(sizeof(int)*size);
	ret=count_sort(arr,size);
	for(i=0;i<size;i++){
		printf("%d\n",ret[i]);
	}
	return 0;


}
