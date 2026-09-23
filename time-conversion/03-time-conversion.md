# Time Conversion

## HackerRank

[HackerRank problem URL]

## Difficulty

Easy

## Approach

The first two characters are converted to an integer hour. For a PM time, 12 is added unless the hour is already 12. For an AM time, 12 is changed to 00.

The minutes and seconds remain unchanged, so the converted 24-hour value is formatted into a new string.

## Complexity

Time Complexity: O(1)  
Space Complexity: O(1)

## Local Test Cases

1. **Test Case 1 - Typical Case:** `07:05:45PM` -> Expected output: `19:05:45`
2. **Test Case 2 - Edge Case:** `12:00:00AM` -> Expected output: `00:00:00`

## Notes

The returned string is allocated with `malloc()`, matching the usual HackerRank C function contract. The local harness frees it after printing.
