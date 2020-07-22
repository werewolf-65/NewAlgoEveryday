#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
//returns the max of 2 integers 

  return ((a>b)?a:b);
}

int knapsack(int(*option_weights_array)[2],int n_opt,int capacity){
  int (*final_value_arr)[capacity+1]=malloc(sizeof(int)*n_opt*(capacity+1));
  int i,j,best;
  //we are having the items as rows 
  //and required weight as cols
  //populate with zeros for the first column since it's for weight 0 and value for '0' weight is 0 too 
  for(i=0;i<n_opt;i++){
    final_value_arr[i][0]=0;
  }

  //now first fill up the first row 
  for(j=1;j<(capacity+1);j++){
    if(option_weights_array[0][0]<=j){
      final_value_arr[0][j]=option_weights_array[0][1];
    }
    else{
      final_value_arr[0][j]=0;
    }
  }
  //then proceed row-wise in order to find the best value for each capacity 
  for(i=1;i<n_opt;i++){
    for(j=1;j<(capacity+1);j++){
       //if the weight of item is less than or equal to required capacity 
       if(option_weights_array[i][0]<=j){
        //choose the maximum of the two values
        //the value of the item selected + the value of final_value_arr[i-1][j-weight of the current item]
        //or the value of final_value_array[i-1][j]
        final_value_arr[i][j]=max(option_weights_array[i][1]+final_value_arr[i-1][j-option_weights_array[i][0]]
                                  ,final_value_arr[i-1][j]);
        }
        else{
        //or the value of final_value_array[i-1][j]
        final_value_arr[i][j]=final_value_arr[i-1][j];
        }
    }
  }

  return final_value_arr[n_opt-1][capacity];

}


int main(){
  int option_weights_array[4][2]={{5,60},{3,50},{4,70},{2,30}};
  int n_opt=sizeof(option_weights_array)/sizeof(option_weights_array[0]);
  int capacity=5;
  int result;

  result=knapsack(option_weights_array,n_opt,capacity);

  printf("result:%d\n",result);

  return 0;
}


