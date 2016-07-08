#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char p1throw[2];
  char p2throw[] = "sc";

  printf("What would you like to throw? \n");

  printf("Rock (r)\nPaper (p)\nScissors (sc)\nLizard (l)\nSpock(sp)\n");

  if (fgets(p1throw, sizeof(p1throw), stdin) == NULL) {
    printf("couldn't read your input");
  }
  p1throw [strcspn(p1throw, "\n")] = 0;

  printf("You threw %s \n", p1throw);

  printf("The computer thew %s \n", p2throw);

  if (strcmp(p1throw, "r") == 0) {
    printf("good job\n");
  } else {
    printf("you lost\n");
  }
  return EXIT_SUCCESS;
}
