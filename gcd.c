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
	int a=16,b=8;

	scanf("%d %d",&a,&b);
	printf("GCD:%d",gcd(a,b));
	return 0;
}
