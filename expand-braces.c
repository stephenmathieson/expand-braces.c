
#include <stdlib.h>
#include <string.h>
#include "expand-braces.h"

/**
 * Create a "part".
 */

static char *
make_part(
      const char *str
    , size_t len
    , int open_brace_position
    , int close_brace_position
    , int part_start
    , int part_end
  ) {
  int part_length = part_end - part_start;
  int total_length = open_brace_position
    + (len - close_brace_position)
    + part_length;
  char *part = malloc(total_length);
  if (part) {
    memset(part, '\0', total_length);
    memcpy(part, str, open_brace_position);
    memcpy(&part[open_brace_position], &str[part_start], part_length);
    memcpy(
        &part[open_brace_position + part_length]
      , &str[close_brace_position + 1]
      , (len - close_brace_position)
    );
  }
  return part;
}

/**
 * Destroy the array and all of its parts.
 */

static void
destroy_array(char **array, int size) {
  for (int i = 0; i < size; i++) {
    if (array[i]) free(array[i]);
  }
  free(array);
  array = NULL;
}

int
expand_braces(char ***array, const char *str) {
  size_t len = strlen(str);
  int open_position = 0;
  int close_position = 0;
  int count = 0;
  int last_comma_position = 0;
  int index = 0;

  // find offsets & count parts
  for (size_t i = 0; i < len; i++) {
    if (!open_position) {
      if ('{' == str[i]) open_position = i;
    } else {
      if (',' == str[i]) {
        count++;
      } else if ('}' == str[i]) {
        close_position = i;
      }
    }
  }

  // no parts or braces
  if (!open_position || !close_position || !count) {
    return 0;
  }

  count++;
  *array = calloc(count, sizeof(char *));
  if (NULL == array) return -1;

  last_comma_position = open_position;
  // create each part
  for (int i = open_position; i < close_position; i++) {
    if (',' == str[i]) {
      char *part = make_part(
          str
        , len
        , open_position
        , close_position
        , last_comma_position + 1
        , i
      );
      if (!part) {
        destroy_array(*array, count);
        return -1;
      }
      (*array)[index++] = part;
      last_comma_position = i;
    }
  }

  // create last part
  char *part = make_part(
      str
    , len
    , open_position
    , close_position
    , last_comma_position + 1
    , close_position
  );
  if (NULL == part) {
    destroy_array(*array, count);
    return -1;
  }
  (*array)[index++] = part;

  return count;
}
