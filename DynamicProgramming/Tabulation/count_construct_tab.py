def count_construct(target,word_bank=[]):
    table_size=len(target)+1
    table=[] 

    for i in range(table_size):
        table.append(0)
    
    #initialize table[0] with 1 as there is ONE way to create an empty string 
    table[0]=1

    #now iterate through the indices of the table 
    for i in range(table_size):
        #iterate through the words of the word_bank
        for word in word_bank:
            #check if the word matches the part of the string starting from this index
            if(target[i:i+len(word)]==word):
                #update the other positions of the table by adding the current position's number to those positions
                table[i+len(word)]+=table[i]


    return table[len(target)]







def main():
    print(count_construct("hello", ["he", "l", "o"]))
    print(count_construct("purple",["purp","p","ur","le","purpl"]))
    print(count_construct("rajamati", [
          "s", "raj", "amat", "raja", "ma", "i", "t"]))
    print(count_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
          "e", "eee", "eeee", "eeeee"]))


main()
