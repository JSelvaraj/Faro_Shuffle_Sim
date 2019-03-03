#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
  if (argc != 2 || (strncmp(argv[1], "RANKSUIT", 8) != 0 && strncmp(argv[1], "NUMERICAL", 9) != 0 )) {
    printf("Usage: ./faro_shuffle RANKSUIT||NUMERICAL\n");
    exit(-1);
  } else {

  }


}
