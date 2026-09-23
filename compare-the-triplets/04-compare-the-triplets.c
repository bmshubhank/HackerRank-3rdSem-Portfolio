#include <stdio.h>
#include <stdlib.h>

/* HackerRank-compatible solution function. */
int *compareTriplets(int a_count, int *a, int b_count, int *b)
{
    int *scores = calloc(2, sizeof(int));
    int count = a_count < b_count ? a_count : b_count;

    for (int index = 0; index < count; index++)
    {
        if (a[index] > b[index])
        {
            scores[0]++;
        }
        else if (a[index] < b[index])
        {
            scores[1]++;
        }
    }

    return scores;
}

void run_test_case(int test_number, int a[], int b[], const int expected[])
{
    int *actual = compareTriplets(3, a, 3, b);

    printf("Test Case %d - %s\n", test_number,
           test_number == 1 ? "Typical Case" : "Edge Case");
    printf("Actual result: %d %d\n", actual[0], actual[1]);
    printf("Expected result: %d %d\n\n", expected[0], expected[1]);

    free(actual);
}

int main(void)
{
    int typical_a[] = {5, 6, 7};
    int typical_b[] = {3, 6, 10};
    int typical_expected[] = {1, 1};
    /* Expected result: Alice 1, Bob 1. */
    run_test_case(1, typical_a, typical_b, typical_expected);

    int edge_a[] = {1, 1, 1};
    int edge_b[] = {1, 1, 1};
    int edge_expected[] = {0, 0};
    /* Expected result: 0 0 because all scores are tied. */
    run_test_case(2, edge_a, edge_b, edge_expected);

    return 0;
}
