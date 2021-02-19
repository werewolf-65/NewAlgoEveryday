def can_construct(target_string,word_bank=[],memo={}):
	#base case 
	if (target_string==""):
		return True 

	#memoized base case 
	if target_string in memo:
		return memo[target_string]
	#iterate through the word bank and perform recursive can_construct in the suffix 
	for word in word_bank:
		#slice out the suffix if word matches the string portion from the start 
		if (word == target_string[:len(word)]):
			suffix=target_string[len(word):]
			if(can_construct(suffix,word_bank)==True):
				memo[target_string]=True
				return True 
			
	memo[target_string]=False	
	return False 
		

def main():
	memo={}
	print(can_construct("hello",["he","l","o"],memo))
	print(can_construct("rajamati",["s","raj","amat","raja","ma","i","t"],memo))

main()

