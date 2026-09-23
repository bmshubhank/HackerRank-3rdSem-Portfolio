# Compare the Triplets

## HackerRank

[HackerRank problem URL]

## Difficulty

Easy

## Approach

The three scores are compared position by position. When Alice's score is larger, her point total increases; when Bob's score is larger, his point total increases. Equal scores do not change either total.

The two totals are returned in an allocated two-element array in Alice-then-Bob order.

## Complexity

Time Complexity: O(1)  
Space Complexity: O(1)

## Local Test Cases

1. **Test Case 1 - Typical Case:** Alice `5 6 7`, Bob `3 6 10` -> Expected output: `1 1`
2. **Test Case 2 - Edge Case:** Alice `1 1 1`, Bob `1 1 1` -> Expected output: `0 0`

## Notes

The local harness prints the returned score array and then releases its memory. The HackerRank-compatible function remains separate from `main()`.
