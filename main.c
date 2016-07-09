#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getThrowCode(char throw [3]) {

  int i_throw = (int)throw [0];
  i_throw += (int)throw [1];

  switch (i_throw) {
  case 225:
    i_throw = 0;
    break;
  case 209:
    i_throw = 1;
    break;
  case 214:
    i_throw = 2;
    break;
  case 213:
    i_throw = 3;
    break;
  case 227:
    i_throw = 4;
    break;
  }

  printf("ASCII code throw %d\n", i_throw);
}

void getThrow(char throw[3]) {
  if (fgets(throw, 3, stdin) == NULL) {
    printf("Couldn't read your input");
  }
  //throw[strcspn(throw, "\n")] = 0;
}

int main() {
  char p1throw[3];
  char p2throw[] = "2";

  printf("What would you like to throw? \n");

  printf("Rock (ro)\nPaper (pa)\nScissors (sc)\nLizard (li)\nSpock(sp)\n");
  getThrow(p1throw);

  printf("You threw %s \n", p1throw);

  printf("The computer thew %s \n", p2throw);

  if (strcmp(p1throw, "r") == 0) {
    printf("good job\n");
  } else {
    printf("you lost\n");
  }
  getThrowCode(p1throw);

  return EXIT_SUCCESS;
}
