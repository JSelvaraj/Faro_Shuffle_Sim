#include "headers.h"

int getIntLength(int n) {
  int length = 0;
  while (n > 0) {
    n = n / 10;
    length++;
  }
  return n;
}
