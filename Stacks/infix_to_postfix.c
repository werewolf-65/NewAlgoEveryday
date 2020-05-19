#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

//operations for stack 
int is_operator(char c){
	if(c=='+' || c=='-' || c=='*' || c=='/')
		return 1; //true 
	return 0; // false if not true 
}
//function to check if it is operand 
int is_operand(char c){
	if(c>='0' &&  c<='9') return 1;
	if(c>='a' &&  c<='z') return 1;
	if(c>='A' &&  c<='Z') return 1;
	return 0;
}

//function to check right associative or not 
int is_right_associative(char op){
	if(op=='^') return 1;
	return 0;
}

//function to get weight of an operator (higher weight=higher precedence) 
int get_operator_weight(char op){

	int weight=-1;
	switch(op){
	
	case '+':
	case '-':
		weight=1;
		break;
	case '*':
	case '/':
		weight=2;
		break; 
	case '^':
		weight=3;
		break;
	}
	return weight;

}
//function to check if op1 has higher precedence than op2 
int has_higher_precedence(char op1,char op2){
	int op1_weight=get_operator_weight(op1);
	int op2_weight=get_operator_weight(op2);
	
	//if equal precedence, return true if left associative 
	//if right associative (^) return false 
	if(op1_weight==op2_weight){
		if(is_right_associative(op1)) return 0;
		return 1;
	}
	return op1_weight>op2_weight?1:0;
}

char* infix_to_postfix(char* S){
	//CREATING A STACK
	int top=-1;
	char *stack=" ";
	char *postfix=" ";
	int i;
	for(i=0;i<strlen(S);i++){//Start from the left 
		if(S[i]==' ' || S[i]==','){//if it is a delimiter,skip to the next character 
			continue;
		}
		else if(is_operator(S[i])){
			while(!(top==-1) && stack[top] != '(' &&has_higher_precedence(stack[top],S[i])){
				strncat(postfix,&stack[top],1);
				top--;
			}
			//push the character operator 
			top++;
			stack[top]=S[i];	
		}
		else if(is_operand(S[i])){
			strncat(postfix,&S[i],1);
		}
		else if(S[i]=='('){
			top++;
			stack[top]=S[i];
		}
		else if(S[i]==')'){
			while(!(top==-1) && stack[top] != '('){
				strncat(postfix,&stack[top],1);
				top--; 
			}
// 			if(top != -1){
// 				top--;
// 			}
			top--;

		}
	}
	
	while(!(top==-1)){
		strncat(postfix,&stack[top],1);
		top--;	
	}
	
	return postfix;






}
int main(){
	char S[30];
	printf("Enter an expression:\n");
	fgets(S,30,stdin);
	printf("Final output is %s",infix_to_postfix(S)) ; 
	return 0;

}

