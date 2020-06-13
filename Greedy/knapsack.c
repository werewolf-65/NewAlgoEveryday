#include <stdio.h>
#include <stdlib.h> 

//assumming sorted in a descending order of value/weight 
//W is the total weight capacity of the knapsack 
//w-> array of weights 
//v-> array of values 

float knapsack(float W, float* w,float* v,int n){
//	float A[10];
	float V=0;//total value is 0 
	int i;
	float a; // a for amount 
	float* A=(float *)malloc(sizeof(float)*n);
	for(i=0;i<n;i++){
		if(W==0){
			return V;
		}
		if(w[i]<W){
			a=w[i];
		}
		else{
			a=W;
		}
		V=V+a*v[i]/w[i];
		//update the values 
		w[i]=w[i]-a;
		A[i]=A[i]+a;
		printf("%.2f\n",A[i]);
		W=W-a;	
	}
	return V;
}

int main(){
	float final;
	float v[]={20,10,20};
	float w[]={4,5,20};
	int n=sizeof(w)/sizeof(w[0]);
	final=knapsack(10,w,v,n);
	printf("Maximum value:%.2f\n",final);
	return 0;
}
