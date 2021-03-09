def count_construct(target, word_bank=[], memo={}):
    # base case
    if (target == ""):
        return 1

    # memoization check
    if target in memo:
        return memo[target]

    # no of ways the target string can be formed from the words in the word bank
    no_of_ways = 0

    for word in word_bank:
        # slice out the suffix if word in word_bank matches the target string from the start
        if(word == target[:len(word)]):
            suffix = target[len(word):]
            no_of_ways_for_the_suffix = count_construct(suffix, word_bank)
            no_of_ways += no_of_ways_for_the_suffix

    memo[target] = no_of_ways
    return no_of_ways


def main():
    memo = {}
    print(count_construct("hello", ["he", "l", "o"], memo))
    print(count_construct("rajamati", [
          "s", "raj", "amat", "raja", "ma", "i", "t"], memo))
    print(count_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
          "e", "eee", "eeee", "eeeee"], memo))


main()
