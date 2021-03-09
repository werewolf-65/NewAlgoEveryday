def best_sum(target_sum,num_list=[]):
    #create a table of size target_sum+1 
    table_size=target_sum+1 
    table=[]

    #populate the table with None 
    for i in range(table_size):
        table.append(None)

    #fill the Oth position with empty array 
    table[0]=[]

    #update the values based on the current position in the table 
    for i in range(table_size):
        if(table[i] is not None):
            for num in num_list:
                if((i+num)<table_size):
                    combination=table[i]+[num]
                    #update the best sum values for the following conditions 
                    if((table[i+num]==None) or (len(table[i+num])>len(combination))):
                        table[i+num]=combination 

    return table[target_sum]

def main():
    print(best_sum(7,[3,4,5,7]))
    print(best_sum(300,[7,14]))
    print(best_sum(100,[1,2,5,7,25]))
main()

