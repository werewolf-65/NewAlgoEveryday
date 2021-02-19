def best_sum(target_sum,num_list=[],memo={}):
	if(target_sum == 0):
		return []
	if(target_sum < 0):
		return None 
	if target_sum in memo:
		return memo[target_sum]

	shortest_combination=None
	for num in num_list:
		remainder=target_sum-num
		remainder_combination=best_sum(remainder,num_list)	
		if(remainder_combination is not None):
			combination=remainder_combination+[num]
			
			if(shortest_combination is None or (len(combination) < len(shortest_combination))):
				shortest_combination=combination 

	memo[target_sum]=shortest_combination
	return shortest_combination 

def main():
	memo={}
	print(best_sum(7,[5,3,4,7],memo))
	print(best_sum(10,[4,2,5],memo))
	print(best_sum(100,[1,2,5,25],memo))

main()
