def how_sum(target_sum,num_list=[]):
    #create a table of size taget_sum +1 
    table_size=target_sum+1 
    table=[]

    #populate the table with None objects
    for i in range(table_size):
        table.append(None)

    #fill the 0th position with empty array 

    table[0]=[]

    #update the values based on the current position in the table 
    for i in range(table_size):
        if(table[i] is not None):
            for num in num_list:
                #check the boundary conditions 
                if((i+num) < table_size):
                    table[i+num]=table[i]+[num]

    return table[target_sum]


def main():
    print(how_sum(7,[3,4,5,7]))
    print(how_sum(300,[7,14]))

main()
