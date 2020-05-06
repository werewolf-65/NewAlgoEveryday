#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkParentheses(char* string)
{
 int n = 0;
 int top = -1;
 n = strlen(string);
 char *stack = (char*)malloc(n*sizeof(char));

 for (int i = 0; i < n; i++)
 {
  if (string[i] == '{' || string[i] == '[' || string[i] == '(')
  {
   stack[++top] = string[i];
  }
  else if (string[i] == '}' || string[i] == ']' || string[i] == ')')
  {
   if (top == -1)
   {
    printf("Parentheses are unbalanced\n");
    return;
   }
   else if (stack[top] == '{')
   {
    if (string[i] == '}')
     top--;
    else
    {
     printf("Parentheses are unbalanced\n");
     return;
    }
   }
   else if (stack[top] == '[')
   {
    if (string[i] == ']')
     top--;
    else
    {
     printf("Parentheses are unbalanced\n");
     return;
    }
   }
   else if (stack[top] == '(')
   {
    if (string[i] == ')')
     top--;
    else
    {
     printf("Parentheses are unbalanced\n");
     return;
    }
   }
  }
 }
 if (top == -1 ) printf("Parentheses are balanced\n");
} 

int main(){
	char *s="hakdsdfd(){}";
	checkParentheses(s);
	return 0;

}

