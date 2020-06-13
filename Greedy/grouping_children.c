#include <stdio.h>
#include <stdlib.h>

int PointsCoverSorted(float* x,int len){
	float R[10][2];
	int r_ind=0;
	float left,right;
	int i=1;
	while (i<=len){
		left=x[i];
		right=x[i]+1;//1 is the size of interval, in this case children with max age gap of 1 year are allowed in a same group
		R[r_ind][0]=left;
		R[r_ind][1]=right;
		r_ind++;
		i++;
		while(i<=len && x[i]<=right){
			i++;
		}
	}
	return r_ind;
}



int main(){
	float x[]={0.1,0.8,1.0,2.0,2.3,3,4,5,5.5};
	int count;
	count=PointsCoverSorted(x,sizeof(x)/sizeof(x[0]));
	printf("Least number of groups is:%d\n",count);
}
