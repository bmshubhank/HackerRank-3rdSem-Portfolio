# Diagonal Difference

## HackerRank

[HackerRank problem URL]

## Difficulty

Easy

## Approach

The matrix has two diagonals. The primary diagonal uses positions where the row and column indexes are equal. The secondary diagonal uses the column index `N - 1 - row`.

One loop adds both diagonal values at the same time. The absolute difference between the two sums is returned.

## Complexity

Time Complexity: O(N)  
Space Complexity: O(1)

## Local Test Cases

1. **Test Case 1 - Typical Case:** `[[11, 2, 4], [4, 5, 6], [10, 8, -12]]` -> Expected output: `15`
2. **Test Case 2 - Edge Case:** `[[-7]]` -> Expected output: `0`

## Notes

The HackerRank function is separate from the local `main()` test harness. The local harness can be removed before submitting if HackerRank requests only the function.
