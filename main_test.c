#include <criterion/criterion.h>
#include <stdio.h>

unsigned int my_strlen(char const *str);
char *my_strcat(char const *s1, char const *s2);

Test(test_string_fct, my_strlen) {
    cr_expect(my_strlen("Test") == 4, "Expected \"Test\" to have a length of 4.");
    cr_expect(my_strlen("Hello") == 5, "Expected \"Hello\" to have a length of 5.");
    cr_assert(my_strlen("") == 0);
}

Test(test_string_fct, my_strcat) {
    cr_assert_str_eq(my_strcat("Te", ""), "Test", "%s", "my_strcat failed");
    cr_assert_str_eq(my_strcat("Hel", "lo"), "Hello", "%s", "my_strcat failed");
    cr_assert_str_eq(my_strcat("Run test wi", "th criterion"), "Run test with criterion", "%s", "my_strcat failed");
}

void setup(void) {
    puts("Runs before the test");
}

void teardown(void) {
    puts("Runs after the test");
}
