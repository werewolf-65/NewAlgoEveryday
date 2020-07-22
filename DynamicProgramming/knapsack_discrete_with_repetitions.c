#include <stdio.h>
#include <stdlib.h>

int knapsack(int(* option_weights_array)[2],int n_opt,int capacity){
  int* final_value_arr;
  int i,j,best,min_index,temp;

  final_value_arr=(int *)calloc(capacity+1,sizeof(int));

  //to find the minimum given weight 
  min_index=option_weights_array[0][0];
  for(i=1;i<n_opt;i++){
    if(option_weights_array[i][0]<min_index){
      min_index=option_weights_array[i][0];
    }
  }

  for(i=0;i<min_index;i++){
    final_value_arr[i]=0;
  }

  for(i=min_index;i<capacity+1;i++){
    best=0;
    for(j=0;j<n_opt;j++){
      if(i>=option_weights_array[j][0]){
              temp=option_weights_array[j][1]
                   +final_value_arr[i-option_weights_array[j][0]];

              best=(temp>best)?temp:best;
      }
    }
    final_value_arr[i]=best;
  }

  return final_value_arr[capacity];
}

int main(){
  int option_weights_array[4][2]={{6,30},{3,14},{4,16},{2,9}};
  int n_opt=sizeof(option_weights_array)/sizeof(option_weights_array[0]);
  int capacity=10;
  int result;

  result=knapsack(option_weights_array,n_opt,capacity);

  printf("result:%d\n",result);

  return 0;
}

  



