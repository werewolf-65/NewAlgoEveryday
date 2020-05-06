
#include <stdio.h>
int anagram(char x[],char y[]);

int main(){
  char str1[20],str2[20];
  int func_res;
  fflush(stdin);
  printf("Enter first string:\n",str1);
  gets(str1);
  printf("Enter second string:\n",str2);
  gets(str2);

  func_res=anagram(str1,str2);

  if (func_res==1){
    printf("Anagram!");
  }
  else{
    printf("Not Anagram");
  }
  return 0;
}

int anagram(char x[],char y[]){
  int first_str[256]={0},second_str[256]={0},c=0;
  while(x[c]!=0){
    first_str[x[c]]++;
    c++;
  }
  c=0;
  while(y[c]!=0){
    second_str[y[c]]++;
    c++;
  }
  for(c=0;c<256;c++){
    if(first_str[c]!=second_str[c]){
      return 0;
    }
  }
  return 1;
}
