
# expand-braces

  Simple shell-like brace expansion.

## Example

```c
#include <stdlib.h>
#include <stdio.h>
#include "expand-braces.h"

int
main(void) {
  char *str = "hello {world,friends,jerks}!";
  char **greetings = NULL;
  int greeting_count = expand_braces(&greetings, str);
  for (int i = 0; i < greeting_count; i++) {
    printf("%s\n", greetings[i]);
    free(greetings[i]);
  }
  free(greetings);
  return 0;
}
```

## License

  MIT