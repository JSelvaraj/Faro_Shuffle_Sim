#include "headers.h"
int main(int argc, char *argv[]) {
  if (argc < 2 || (strncmp(argv[1], "RANKSUIT", 8) != 0 && strncmp(argv[1], "NUMERICAL", 9) != 0 )) {
    printf("Usage: ./faro_shuffle RANKSUIT||NUMERICAL\n");
    exit(-1);
  }
  int size = 0;
  while(scanf("%d", &size) != 1) {
    printf ("Invalid input\n");
    exit(-1);
  }
  int pos_k = 0;
  while(scanf("%d", &pos_k) != 1) {
    printf ("Invalid input\n");
    exit(-1);
  }
  if (pos_k > size) { // if the given position is larger than the number of cards it gets remainder and takes that as the position.
    pos_k = pos_k % size;
  }
  // printf("%d\n",size);
  // printf("%d\n",pos_k);
  Card* deck = get_cards(size);
  print_deck(deck, size, PREFIX_OUT);






}
