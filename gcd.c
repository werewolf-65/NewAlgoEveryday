#include <stdio.h>

int gcd(int a,int b){
	int mod_d,rem;
	if(b==0){
		return a;
	}
	rem=a%b;
	return gcd(b,rem);
}

int main(){
	int a=16,b=8i,temp;

	scanf("%d %d",&a,&b);
	if(a<b){
		//swap a and b 
		temp=a;
		a=b;
		b=temp;
	}
	printf("GCD:%d",gcd(a,b));
	return 0;
}
