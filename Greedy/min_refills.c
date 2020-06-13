#include <stdio.h> 
#include <stdlib.h> 



int min_ref(int* x, int n, int l){
/* 'x' is the array of stations 
   'n' is the no of refills 
   'l' is the max distance a car can travel without refuelling
*/
	int num_refills=0, current_refill_pos=0,last_refill_pos=0;
	while(current_refill_pos<=n){
		last_refill_pos=current_refill_pos;
		while((current_refill_pos<=n)&&(x[current_refill_pos+1]-x[last_refill_pos]<=l)){
			current_refill_pos++;
		}
	
		// check if IMPOSSIBLE 
		if(current_refill_pos==last_refill_pos){
			printf("Current :%d \n Last:%d\n",current_refill_pos,last_refill_pos);
			printf("It's impossible");
			return -1;
		}
		
		if(current_refill_pos<=n){
			num_refills++;
			printf("Car refilled at %d\n",current_refill_pos);
		}
		}
	return num_refills;
}


int main(){
	int a[6]={0,5,7,10,15,20};
	int n=4;
	int l=10; //let's say it can travel 10 km without refill

	printf("Min no of refills:%d\n",min_ref(a,n,l));



	return 0;
}
