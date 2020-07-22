#include <stdio.h>
#include <stdlib.h> 

int min(int a,int b){
	int res;
	res=(a<=b)?a:b;
//	printf("%d %d %d\n",a,b,res);
	return res;
}

int* money_change(int money, int* coins,int n_coins){
	int i,j,best,temp;
	int* final;
	final=(int *)malloc(sizeof(int)*(money+1));
	final[0]=0;
	for(i=1;i<=money;i++){
		best=money+1;
		for(j=0;j<n_coins;j++){
			if((i-coins[j])>=0){
				temp=1+final[i-coins[j]];
  			//compare temp and the current best 
	  		best=min(best,temp);

			}
			else{
				continue;
			}
		}
		final[i]=best;
	}
	return final;
}


int main(){
	int money=1;
	int coins[10];
	int ncoins,*res,i;
	char c;
	
	printf("Enter the amount of money you want to change:\n");
	scanf("%d",&money);
	
	printf("Enter the no of coins:\n");
	scanf("%d",&ncoins);
	
	printf("Enter the values of coins:(not more than 10)\n");
	for(i=0;i<ncoins;i++){
		scanf("%d",&coins[i]);
	}

	
//	ncoins=sizeof(coins)/sizeof(coins[0]);
	res=money_change(money,coins,ncoins);
	printf("Min number of coins:%d",res[money]);
	return 0;
}
			
				
		
