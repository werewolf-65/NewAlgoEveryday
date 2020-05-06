#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

char stack[30];

int top=-1;

//operations for stack 
void Push(char x){
	top++;
	stack[top]=x;
}

void Pop(){
	if(top==-1){
		return;
	}
	top--;
}
char Top(){
	return stack[top];
}
char Pair(char c){
	if(c=='}')
		return '{';
	else if(c==')'){
		return '(';
	}
	else{
		return '[';
	}

}

void CheckBalancedParenth(char *S,int length){
	int i;
	for(i=0;i<length-1;i++){
		if(S[i]=='{' || S[i]=='[' || S[i]=='(')
			Push(S[i]);
		else if(S[i]=='}' || S[i]==']' || S[i]==')'){
			if(top==-1 || (Top()!=Pair(S[i]))){
				printf("Error");
				return;
			}
			else{
				Pop();
			}

		}
	}
	if(top==-1){ //in case of empty stack 
		printf("Success. No error.");
	}
	else{
		printf("Error");
	}
}

int main(){
	char S[30];
	int length;
	char *stack1=(char*)malloc(30*sizeof(char));
	fgets(S,30,stdin);
	length=strlen(S);
	printf("%d",length);
	CheckBalancedParenth(S,length);
	printf("%c",Top());
	return 0;

}

