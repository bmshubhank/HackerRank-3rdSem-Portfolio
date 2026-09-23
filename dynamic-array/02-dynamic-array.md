# Dynamic Array

## HackerRank

[HackerRank problem URL]

## Difficulty

Easy

## Approach

The solution maintains `N` variable-length sequences. For a type 1 query, the value is appended to the sequence selected by `(x ^ lastAnswer) % N`.

For a type 2 query, the required value is read from the selected sequence using `y` modulo its current length. Each type 2 result updates `lastAnswer` and is stored in the returned array.

## Complexity

Time Complexity: O(N + Q)  
Space Complexity: O(N)

## Local Test Cases

1. **Test Case 1 - Typical Case:** Queries `1 0 5`, `1 1 7`, `1 0 3`, `2 1 0`, `2 1 1` -> Expected output: `7 3`
2. **Test Case 2 - Edge Case:** One sequence with queries `1 0 42`, `2 0 0` -> Expected output: `42`

## Notes

The C implementation dynamically grows each sequence with `realloc()`. The local `main()` demonstrates the logic and can be removed or adapted for HackerRank's submission interface.
