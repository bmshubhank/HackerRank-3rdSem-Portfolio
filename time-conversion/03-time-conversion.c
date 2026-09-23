#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* HackerRank-compatible solution function. Caller owns the returned string. */
char *timeConversion(char *s)
{
    char *converted = malloc(9 * sizeof(char));
    int hour;

    sscanf(s, "%2d", &hour);
    memcpy(converted, s, 8);
    converted[8] = '\0';

    if (s[8] == 'P' && hour != 12)
    {
        hour += 12;
    }
    else if (s[8] == 'A' && hour == 12)
    {
        hour = 0;
    }

    snprintf(converted, 9, "%02d%s", hour, s + 2);
    return converted;
}

void run_test_case(int test_number, char input[], const char expected[])
{
    char *actual = timeConversion(input);

    printf("Test Case %d - %s\n", test_number,
           test_number == 1 ? "Typical Case" : "Edge Case");
    printf("Actual result: %s\n", actual);
    printf("Expected result: %s\n\n", expected);

    free(actual);
}

int main(void)
{
    /* Expected result: 19:05:45. */
    run_test_case(1, "07:05:45PM", "19:05:45");

    /* Expected result: 00:00:00 for midnight. */
    run_test_case(2, "12:00:00AM", "00:00:00");

    return 0;
}
