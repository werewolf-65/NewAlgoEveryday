#include <stdio.h>
#include <stdlib.h> 

int min(int a,int b,int c){
  if(a<=b){
    if(a<=c){
      return a;
    }
    else{
      return c;
    }
  }
  else{
    if(b<=c){
      return b;
    }
    else{
      return c;
    }
  }
}

int edit_distance(int* A,int size_a,int* B,int size_b){
  int i,j;
  int D[size_a+1][size_b+1];
  int insertion,deletion,match,mismatch;  

  for(i=0;i<size_a;i++){
    D[i][0]=i;
  }
  for(j=1;j<size_b;j++){
    D[0][j]=j;
  }

  for(i=1;i<=size_a;i++){
    for(j=1;j<=size_b;j++){
      insertion=D[i][j-1]+1;
      deletion=D[i-1][j]+1;
      match=D[i-1][j-1];
      mismatch=D[i-1][j-1]+1;
      if(A[i-1]==B[j-1]){
        D[i][j]=min(insertion,deletion,match);
      }
      else{
        D[i][j]=min(insertion,deletion,mismatch);
      }
    }
  }
  return D[size_a][size_b];

}


int main(){
  int A[]={1,3,5,7,9};
  int B[]={2,3,5,9};
  int size_a,size_b,result;
  size_a=sizeof(A)/sizeof(A[0]);
  size_b=sizeof(B)/sizeof(B[0]);
  result=edit_distance(A,size_a,B,size_b);
  printf("Result:%d",result);
  return 0;
}
