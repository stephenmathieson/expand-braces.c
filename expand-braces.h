
#ifndef EXPAND_BRACES_H
#define EXPAND_BRACES_H  1

/**
 * Populate the given `array` by expanding "parts"
 * contained in braces in `str`.
 *
 * Returns -1 on failure, 0 if there are no "parts"
 * or braces to expand, or the number of expanded
 * "parts".
 *
 * Free each member of `array` and `array` itself
 * when done.
 *
 * Example:
 *
 *     char *str = "hello {world,friends,jerks}!";
 *     char **greetings = NULL;
 *     int greeting_count = expand_braces(greetings, str);
 *     for (int i = 0; i < greeting_count; i++) {
 *       printf("%s", greetings[i]);
 *       free(greetings[i]);
 *     }
 *     free(greetings);
 *
 */

int
expand_braces(char ***array, const char *str);

#endif
