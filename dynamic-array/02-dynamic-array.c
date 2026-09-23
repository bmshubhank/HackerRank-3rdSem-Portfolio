#include <stdio.h>
#include <stdlib.h>

/* HackerRank-compatible solution function. */
int *dynamicArray(int n, int queries_rows, int queries_columns,
                  int **queries, int *result_count)
{
    int **sequences = calloc((size_t)n, sizeof(int *));
    int *sequence_sizes = calloc((size_t)n, sizeof(int));
    int *answers = malloc((size_t)queries_rows * sizeof(int));
    int answer_index = 0;
    int last_answer = 0;

    (void)queries_columns;

    for (int query_index = 0; query_index < queries_rows; query_index++)
    {
        int query_type = queries[query_index][0];
        int x = queries[query_index][1];
        int y = queries[query_index][2];
        int sequence_index = (x ^ last_answer) % n;

        if (query_type == 1)
        {
            int new_size = sequence_sizes[sequence_index] + 1;
            sequences[sequence_index] = realloc(
                sequences[sequence_index], (size_t)new_size * sizeof(int));
            sequences[sequence_index][new_size - 1] = y;
            sequence_sizes[sequence_index] = new_size;
        }
        else
        {
            int position = y % sequence_sizes[sequence_index];
            last_answer = sequences[sequence_index][position];
            answers[answer_index++] = last_answer;
        }
    }

    for (int index = 0; index < n; index++)
    {
        free(sequences[index]);
    }
    free(sequences);
    free(sequence_sizes);

    *result_count = answer_index;
    return answers;
}

void print_test_case(int test_number, int n, int query_count,
                     int queries[][3], int expected[], int expected_count)
{
    int *query_pointers[query_count];
    int result_count;
    int *actual;

    for (int index = 0; index < query_count; index++)
    {
        query_pointers[index] = queries[index];
    }

    actual = dynamicArray(n, query_count, 3, query_pointers, &result_count);

    printf("Test Case %d - %s\n", test_number,
           test_number == 1 ? "Typical Case" : "Edge Case");
    printf("Actual result: ");
    for (int index = 0; index < result_count; index++)
    {
        printf("%d%s", actual[index], index + 1 == result_count ? "" : " ");
    }
    printf("\nExpected result: ");
    for (int index = 0; index < expected_count; index++)
    {
        printf("%d%s", expected[index], index + 1 == expected_count ? "" : " ");
    }
    printf("\n\n");

    free(actual);
}

int main(void)
{
    int typical_queries[][3] = {
        {1, 0, 5}, {1, 1, 7}, {1, 0, 3},
        {2, 1, 0}, {2, 1, 1}
    };
    int typical_expected[] = {7, 3};
    /* Expected result: 7 3. */
    print_test_case(1, 2, 5, typical_queries, typical_expected, 2);

    int edge_queries[][3] = {{1, 0, 42}, {2, 0, 0}};
    int edge_expected[] = {42};
    /* Expected result: 42 for one sequence and one query result. */
    print_test_case(2, 1, 2, edge_queries, edge_expected, 1);

    return 0;
}
