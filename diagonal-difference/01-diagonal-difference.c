#include <stdio.h>
#include <stdlib.h>

/* HackerRank-compatible solution function. */
int diagonalDifference(int arr_rows, int arr_columns, int **arr)
{
    int primary_sum = 0;
    int secondary_sum = 0;

    for (int index = 0; index < arr_rows; index++)
    {
        primary_sum += arr[index][index];
        secondary_sum += arr[index][arr_columns - 1 - index];
    }

    return abs(primary_sum - secondary_sum);
}

void run_test_case(int test_number, int size, int values[][3], int expected)
{
    int *rows[3];

    for (int index = 0; index < size; index++)
    {
        rows[index] = values[index];
    }

    printf("Test Case %d - %s\n", test_number,
           test_number == 1 ? "Typical Case" : "Edge Case");
    printf("Actual result: %d\n", diagonalDifference(size, size, rows));
    printf("Expected result: %d\n\n", expected);
}

int main(void)
{
    int typical_case[3][3] = {
        {11, 2, 4},
        {4, 5, 6},
        {10, 8, -12}
    };
    /* Expected result: 15. */
    run_test_case(1, 3, typical_case, 15);

    int edge_case[1][3] = {{-7, 0, 0}};
    /* Expected result: 0 because a 1x1 matrix has identical diagonals. */
    run_test_case(2, 1, edge_case, 0);

    return 0;
}
