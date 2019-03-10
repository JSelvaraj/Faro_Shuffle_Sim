#include "headers.h"

int getIntLength(int n) {
  int length = 0;
  while (n > 0) {
    n = n / 10;
    n++;
  }
  printf("int Length: %d", length);
  return n;
}
