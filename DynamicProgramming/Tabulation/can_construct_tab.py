def can_construct(target,word_bank=[]):
    table_size=len(target)+1 
    table=[]

    #populate table with false values 
    for i in range(table_size):
        table.append(False)
    #trivial case 
    table[0]=True #empty string can be generated all the time 

    #main logic 
    #here every position in the table stores the truth value for constructing the string upto that index 
    for i in range(table_size):
        #proceed only if the current value in the table is true 
        if (table[i]==True):
            for word in word_bank:
                #if the word matches with characters starting at position i
                if (target[i:i+len(word)] == word):
                    table[i+len(word)]=True

    return table[len(target)]

print(can_construct("abcdef",["ab","abc","cd","def","abcd"]))

print(can_construct("enterapotentpot",["a","p","ent","enter","ot","o","t"]))

print(can_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeef",["eeeeeee","eeee","eee","ee","e"]))
