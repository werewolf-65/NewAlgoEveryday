#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
  int res;
  res=(a>=b)?a:b;
  return res;
}

int longest_common_subsequence(int* A,int index_a,int* B,int index_b){
  if((index_a==-1)||(index_b==-1)){
    return 0;
  }
  else if(A[index_a]==B[index_b]){
    return 1+longest_common_subsequence(A,index_a-1,B,index_b-1);
  }
  else{
    return max(longest_common_subsequence(A,index_a-1,B,index_b),
                longest_common_subsequence(A,index_a,B,index_b-1));
  }

}








int main(){
  int A[]={1,3,5,7,9};
  int B[]={2,3,5,9};
  int size_a,size_b,result;
  size_a=sizeof(A)/sizeof(A[0]);
  size_b=sizeof(B)/sizeof(B[0]);
  result=longest_common_subsequence(A,size_a-1,B,size_b-1);
  printf("Result:%d\n",result);
  return 0;
}
