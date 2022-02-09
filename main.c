#include <stdio.h>

unsigned int my_strlen(char const *str);
char *my_strcat(char const *s1, char const *s2);

int main()
{
    printf("my_strlen:\n\tTest: %d\n\tHello: %d\n\tRun test with criterion: %d\n\n", my_strlen("Test"), my_strlen("Hello"), my_strlen("Run test with criterion"));
    printf("my_strcat:\n\t%s\n\t%s\n\t%s", my_strcat("Te", "st"), my_strcat("Hel", "lo"), my_strcat("Run test wi", "th criterion"));
    return 0;
}