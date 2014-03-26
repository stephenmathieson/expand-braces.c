
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "expand-braces.h"

int
main(void) {
  char *str = "hello {friends,people,dogs,cats,fish}!!!";
  char **array = NULL;
  int count = expand_braces(&array, str);
  assert(5 == count && array);
  assert(0 == strcmp("hello friends!!!", array[0]));
  assert(0 == strcmp("hello people!!!", array[1]));
  assert(0 == strcmp("hello dogs!!!", array[2]));
  assert(0 == strcmp("hello cats!!!", array[3]));
  assert(0 == strcmp("hello fish!!!", array[4]));
  for (int i = 0; i < count; i++) free(array[i]);
  free(array);
  return 0;
}
