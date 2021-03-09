def all_construct(target,word_bank=[]):
    #create a table 
    table_size=len(target)+1 
    table=[]
    for i in range(table_size):
        table.append([])

    #seed value 
    table[0]=[[]] #because empty string has empty combination (double)

    #iterate through the indices 
    for i in range(table_size):
        #condition 
        if (table[i] != []):
            for word in word_bank:
                #slice condition 
                if (target[i:i+len(word)]==word):
#                     print("TAble",table[i])
                    new_combinations=list(map(lambda way:[word]+way,table[i]))
#                     print("New combination",new_combinations)
                    #adds the word to every combination the current position holds
                    #now,push that combination to the table[i+len(word)]

                    table[i+len(word)]+=new_combinations


    return table[len(target)]


def main():
    print(all_construct("hello", ["he", "l", "o"]))
    print(all_construct("purple",["purp","p","ur","le","purpl"]))
    print(all_construct("rajamati", [
          "s", "raj", "amat", "raja", "ma", "i", "t"]))
#     print(all_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
#           "e", "eee", "eeee", "eeeee"]))


main()
