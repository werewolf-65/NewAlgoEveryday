#include <stdio.h>
#include <stdlib.h> 

void merge(int *A,int *L,int leftCount,int *R, int rightCount){
	int i,j,k; 
	i=j=k=0;
	while(i<leftCount && j<rightCount){
		if(L[i]<=R[j]){
			A[k++]=L[i++];
		}
		else{
			A[k++]=R[j++];
		}	
	}
	//in case elements remain in either of the sub array 
	while(i<leftCount){
		A[k++]=L[i++];
	}
	while(j<rightCount){
		A[k++]=R[j++];
	}	
}

void merge_sort(int *A,int n){
	int *L,*R; // L for left half and r for right half 
	int i,mid; 

	if(n<2){
		return; 
	}

	mid=n/2; 
	L=(int *)malloc(mid*sizeof(int));
	R=(int *)malloc((n-mid)*sizeof(int));
	for(i=0;i<mid;i++){
		L[i]=A[i];
	}
	for(i=mid;i<n;i++){
		R[i-mid]=A[i];
	}
	merge_sort(L,mid);
	merge_sort(R,n-mid);
	merge(A,L,mid,R,n-mid);
	free(L);
	free(R);
	
}

int main(){
	int A[]={3,5,2,1,7,5};
	int size,i=0;
	size=sizeof(A)/sizeof(A[0]);
	merge_sort(A,size);
	for(i=0;i<size;i++){
		printf("%d\t",A[i]);
	}
	return 0;

}


