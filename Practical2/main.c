#include "headers.h"


int main(int argc, char *argv[]) {
  if (argc < 2 || (strncmp(argv[1], "RANKSUIT", 8) != 0 && strncmp(argv[1], "NUMERICAL", 9) != 0 )) {
    printf("Usage: ./faro_shuffle RANKSUIT||NUMERICAL\n");
    exit(-1);
  }
  int size = 0;
  int pos_k = 0;
  while (true) {
    if (scanf("%d", &size) != 1) {
      printf ("Invalid input\n");
      exit(-1);
    }
    if (size == -1) {
      break;
    }
    if (scanf("%d", &pos_k) != 1) {
      printf ("Invalid input\n");
      exit(-1);
    }
    if (pos_k > size) { // if the given position is larger than the number of cards it gets remainder and takes that as the position.
      pos_k = pos_k % size;
    }
    Card* deck;
    int k_length = 0;
    int* k_binary = decToBinary(pos_k, &k_length);
    if (strncmp(argv[1], "RANKSUIT", 8) == 0 ){
      deck = get_cards_ranksuit(size);
      faro(&deck, size, k_binary, k_length);
    } else if (strncmp(argv[1], "NUMERICAL", 9) == 0 ) {
      deck = get_cards_numerical(size);
      faro_numerical(&deck, size, k_binary, k_length);
    }
    free_ll(deck, size);
    free(k_binary);
  }
}
