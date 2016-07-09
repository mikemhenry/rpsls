#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getThrowCode(char throw [3]) {

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
  default:
    i_throw = -1;
  }

  return i_throw;
}

int getThrow(char throw [3]) {
  bool badInput = 1;
  int throwcode;
  while (badInput == 1) {
    if (fgets(throw, 3, stdin) == NULL) {
      printf("Couldn't read your input, try again\n");
    }
    throwcode = getThrowCode(throw);
    if (throwcode == -1) {
      printf("That was not a valid choice, try again\n");
    } else {
      badInput = 0;
    }
  }

  printf("You threw %s\n", throw);
  printf("Which is choice %d\n", throwcode);
  return throwcode;
}

int getWinner(int throw1, int throw2) {
  // 0 = lost
  // -1 = tie
  // 1 = win

  if ((((throw1 + 2) % 5) == throw2) | (((throw1 + 4) % 5) == throw2)) {
    return 0;
  } else if (throw1 == throw2) {
    return -1;
  } else {
    return 1;
  }
}
int main() {
  char p1throw[3];
  char p2throw[3];
  int throwcode1;
  int throwcode2;
  int status;

  printf("What would you like to throw? \n");

  printf("Rock (ro)\nPaper (pa)\nScissors (sc)\nLizard (li)\nSpock(sp)\n");

  throwcode1 = getThrow(p1throw);
  throwcode2 = getThrow(p2throw);
  status = getWinner(throwcode1, throwcode2);
  if (status == 0) {
    printf("You lost :(\n");
  } else if (status == 1) {
    printf("You won :)\n");
  } else {
    printf("Tie game =/\n");
  }
    return EXIT_SUCCESS;
}
