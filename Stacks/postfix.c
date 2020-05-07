#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

//operations for stack 
int is_operator(char c){
	if(c=='+' || c=='-' || c=='*' || c=='/')
		return 1; //true 
	return 0; // false if not true 
}

int is_num_digit(char c){
	if(c>='0' &&  c<='9') return 1;
	return 0;
}

int operate(int operand1,int operand2,char operator){
	if(operator=='+') return operand1+operand2;
	else if(operator=='*') return operand1*operand2;
	else if(operator=='-') return operand1-operand2;
	else if(operator=='/') return operand1/operand2;
	else printf("error during operation");
	return -1; //error 
}
int EvaluatePostFix(char *S){
	int i;
	int operand1,operand2,res;
	int top=-1;
	int *stack=(int *)malloc(sizeof(int)*30);
	
	for(i=0;i<strlen(S);i++){//Start from the left 
		if(S[i]==' ' || S[i]==','){//if it is a delimiter,skip to the next character 
			continue;
		}
		else if(is_operator(S[i])){
			//store last two operands 
			operand2=stack[top];	
		        top--;
			operand1=stack[top];	
		        top--;
			res=operate(operand1,operand2,S[i]);
			//now push res 
			top++;
			stack[top]=res;
			}
		else if(is_num_digit(S[i])){
			int operand=0; //extract the number from the string
			while(i<strlen(S) && is_num_digit(S[i])){
				operand=operand*10 + (S[i]-'0'); //S[i]- '0' gives the number 
				i++;
			}
			i--; //to compensate on one unnecessary increment
			//push operand into the stack 
			top++;
			stack[top]=operand;
		}
	} 
	
	return stack[top];
// 	if(top==-1){ //in case of empty stack 
// 		printf("Success. No error.");
// 	}
// 	else{
// 		printf("Error");
// 	}
	
}

int main(){
	char S[30];
	int output;
	printf("Enter an expression:\n");
	fgets(S,30,stdin);
	output=EvaluatePostFix(S);
	printf("Final output is %d", output) ; 
	return 0;

}

