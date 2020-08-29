#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void prime_sieve(int n){
	/* prints prime numbers upto n*/
	int i,j;
	//create an array of size n+1 that holds 1 for prime and 0 for composite 
	int* check_prime_arr=(int *)malloc(sizeof(int)*(n+1));
	
	check_prime_arr[0]=0;
	check_prime_arr[1]=0;
	
	for(i=2;i<=(n+1);i++){
			check_prime_arr[i]=1; //initialize evth as prime 
	}
	
	for(i=2;i<=sqrt(n);i++){
		if(check_prime_arr[i]==0){
			continue;
		}
		
		for(j=i;i*j<=n;j++){//multiples of i into the check_prime_arr as 0
			check_prime_arr[i*j]=0;
		}
	}

	for(i=2;i<n+1;i++){
			(check_prime_arr[i]==1)?printf("%d is a prime\n",i):printf("");;
	}

}


int main(int argc,char* argv[]){
	prime_sieve(atoi(argv[1]));
	return 0;
}
