#include "headers.h"
#include <assert.h>

int* decToBinary(int number, int* length);


/**@brief This is the main controlling function of the faro shuffle.
@param argc should be a minimum of 2
@param argv[] should contain either the option RANKSUIT or NUMERICAL
*/
int main(int argc, char *argv[]) {
  if (argc < 2 || (strncmp(argv[1], "RANKSUIT", 8) != 0 && strncmp(argv[1], "NUMERICAL", 9) != 0 )) {
    printf("Usage: ./faro_shuffle RANKSUIT||NUMERICAL\n");
    exit(-1);
  }
  int size = 0;
  int pos_k = 0;
  while (1) {
    if (scanf("%d", &size) != 1) { //reads in a size
      printf ("Invalid input\n");
      exit(1);
    }
    assert(size != 0);
    if (size == -1) {
      break;
    }
    if (scanf("%d", &pos_k) != 1) { // reads in a position
      printf ("Invalid input\n");
      exit(1);
    }
    if (pos_k > size) { // if the given position is larger than the number of cards it gets remainder and takes that as the position.
      pos_k = pos_k % size;
    }
    Card* deck;
    int k_length = 0;
    int* k_binary = decToBinary(pos_k, &k_length);
    if (strncmp(argv[1], "RANKSUIT", 8) == 0 ){
      deck = get_cards_ranksuit(size);
      faro(&deck, size, k_binary, k_length, pos_k);
    } else if (strncmp(argv[1], "NUMERICAL", 9) == 0 ) {
      deck = get_cards_numerical(size);
      faro_numerical(&deck, size, k_binary, k_length);
    }
  }
}
