#include <stdio.h>
#include <stdlib.h>



void swap(int *a,int *b){
	int temp; 
	temp=*a;
	*a=*b;
	*b=temp;
}	


int partition(int* A,int start,int end){
	int pivot,i,pIndex;
	pivot=A[end];
	pIndex=start;
	for(i=start;i<end;i++){
		if(A[i]<=pivot){
			swap(&A[i],&A[pIndex]);
			pIndex=pIndex+1; 
		}
	}
	swap(&A[pIndex],&A[end]);
	return pIndex;
} 
void quick_sort(int* A,int start,int end){
	int pIndex; 
	if (start>=end){
		return;
	} 
        else{
	     pIndex=partition(A,start,end);
             quick_sort(A,start,pIndex-1);
	     quick_sort(A,pIndex+1,end);
	}
}


int main(){
	int A[]={3,5,7,3,2,4,1};	
	int size;
	int i;
	size=sizeof(A)/sizeof(A[0]);
	quick_sort(A,0,size-1);
	for(i=0;i<size;i++){
		printf("%d\n",A[i]);
	}
}
