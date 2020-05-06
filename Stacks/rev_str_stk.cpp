#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
void Reverse(char *C,int n){
	stack<char> S;
	//loop for push 
	for(int i=0;i<n;i++){
		S.push(C[i]);
	}
	//loop for pop 
	for(int i=0;i<n;i++){
		C[i]=S.top();
		S.pop();
	}
}

int main(){
	char C[51];
	printf("Enter a string:");
	fgets(C,51,stdin);
	Reverse(C,strlen(C));
	printf("Output=%s",C);
	return 0;
}
