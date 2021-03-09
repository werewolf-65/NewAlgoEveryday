def all_construct(target,word_bank=[],memo={}):
    """ returns all combinations of target from the words of the word bank """
    #base case 
    
    if (target == ""):
        return [[]] #returns an empty double array/list 

    #memoization case check 
    if target in memo:
        return memo[target]

    result=[]


    for word in word_bank:
        #slice out the suffix to work on recursively 
        if(word == target[:len(word)]):
            suffix=target[len(word):]
            suffix_ways=all_construct(suffix,word_bank) #ways in which suffix can be combined 
            target_ways=list(map(lambda way:[word]+way,suffix_ways))
            #ways in which target can be combined using suffix ways i.e. add the edge word to the front of every suffix_ways lists
            
            #now add that to the final result 
            result+=target_ways

    memo[target]=result
    return result 


def main():
    memo={}

    print(all_construct("hello", ["he", "l", "o"],memo))
    print(all_construct("rajamati", ["s", "raj", "amat", "raja", "ma", "i", "t"],memo))

if __name__ == "__main__":
    main()

