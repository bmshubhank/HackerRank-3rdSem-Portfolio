# Sparse Arrays

## HackerRank

[HackerRank problem URL]

## Difficulty

Medium

## Approach

Each query is compared with every input string, and a counter is increased when the strings are equal. The result array stores one count for each query in the original query order.

The implementation uses `strcmp()` for exact string matching and returns zero naturally for queries that do not occur in the input list.

## Complexity

Time Complexity: O(N + Q)  
Space Complexity: O(N)

## Local Test Cases

1. **Test Case 1 - Typical Case:** Strings `aba, baba, aba, xzxb`; queries `aba, xzxb, ab` -> Expected output: `2 1 0`
2. **Test Case 2 - Edge Case:** Strings `hello, world`; queries `missing, hello` -> Expected output: `0 1`

## Notes

The hash table uses open addressing and stores pointers to the original input strings, so it does not duplicate the string contents. The local `main()` can be removed or adapted before submission.
