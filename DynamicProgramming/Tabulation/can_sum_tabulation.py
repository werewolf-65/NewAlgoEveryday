
def can_sum(target_sum,num_list=[]):
   #create a table 
   #of size target_sum+1  
   table_size=target_sum+1 
   table=[];

   #initialize the table with false 
   for i in range(table_size):
        table.append(False)

   #trivial values to be put into the table 
   table[0]=True 
   
   #update the table values based on the current position in the table 
   for i in range(table_size):
    if(table[i]==True):
        for num in num_list:
            if((i+num)<table_size):
                table[i+num]=True 
    
   return table[target_sum]

def main():
    print(can_sum(7,[5,3,4,7]))
    print(can_sum(300,[7,14]))


main()
