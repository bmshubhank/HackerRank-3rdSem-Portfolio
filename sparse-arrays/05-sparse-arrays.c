#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *value;
    int count;
} HashEntry;

unsigned long hash_string(const char *value)
{
    unsigned long hash = 5381;

    while (*value != '\0')
    {
        hash = ((hash << 5) + hash) + (unsigned char)*value;
        value++;
    }

    return hash;
}

/* HackerRank-compatible solution function. */
int *matchingStrings(int strings_count, char **strings,
                     int queries_count, char **queries)
{
    int *matches = calloc((size_t)queries_count, sizeof(int));
    int table_size = strings_count * 2 + 1;
    HashEntry *table = calloc((size_t)table_size, sizeof(HashEntry));

    for (int string_index = 0; string_index < strings_count; string_index++)
    {
        int slot = (int)(hash_string(strings[string_index]) % (unsigned long)table_size);

        while (table[slot].value != NULL &&
               strcmp(table[slot].value, strings[string_index]) != 0)
        {
            slot = (slot + 1) % table_size;
        }

        if (table[slot].value == NULL)
        {
            table[slot].value = strings[string_index];
        }
        table[slot].count++;
    }

    for (int query_index = 0; query_index < queries_count; query_index++)
    {
        int slot = (int)(hash_string(queries[query_index]) % (unsigned long)table_size);

        while (table[slot].value != NULL &&
               strcmp(table[slot].value, queries[query_index]) != 0)
        {
            slot = (slot + 1) % table_size;
        }

        if (table[slot].value != NULL)
        {
            matches[query_index] = table[slot].count;
        }
    }

    free(table);
    return matches;
}

void run_test_case(int test_number, char *strings[], int strings_count,
                   char *queries[], int queries_count, int expected[])
{
    int *actual = matchingStrings(strings_count, strings, queries_count, queries);

    printf("Test Case %d - %s\n", test_number,
           test_number == 1 ? "Typical Case" : "Edge Case");
    printf("Actual result: ");
    for (int index = 0; index < queries_count; index++)
    {
        printf("%d%s", actual[index], index + 1 == queries_count ? "" : " ");
    }
    printf("\nExpected result: ");
    for (int index = 0; index < queries_count; index++)
    {
        printf("%d%s", expected[index], index + 1 == queries_count ? "" : " ");
    }
    printf("\n\n");

    free(actual);
}

int main(void)
{
    char *typical_strings[] = {"aba", "baba", "aba", "xzxb"};
    char *typical_queries[] = {"aba", "xzxb", "ab"};
    int typical_expected[] = {2, 1, 0};
    /* Expected result: 2 1 0. */
    run_test_case(1, typical_strings, 4, typical_queries, 3, typical_expected);

    char *edge_strings[] = {"hello", "world"};
    char *edge_queries[] = {"missing", "hello"};
    int edge_expected[] = {0, 1};
    /* Expected result: 0 1, including a query with no matching string. */
    run_test_case(2, edge_strings, 2, edge_queries, 2, edge_expected);

    return 0;
}
