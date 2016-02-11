#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
  int num;
  int type;
  scanf("%d", &num);  // get number of expression
  int stackTop = -1;
  char output[401];
  char stack[401];
  char input[401];
  while (fgets(input, 401, stdin) != NULL){   // also can use "\0"
    if (c == "("){
      stack[stackTop++] = c;
    }
    else if (c == "+" || c == "-" || c == "/" || c == "*"){
      // operator case
    }
  }
  return 0;

}
