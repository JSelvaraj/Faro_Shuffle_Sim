#include "files/print_faro_val.h"

typedef struct Card Card;  // print_faro_val("", PREFIX_IN);
  // print_faro_val("AC\0", CARD_VAL);
  // print_faro_val("", SUFFIX);
struct Card {
  char rank;
  char suit;
  Card *next;
};

Card* get_cards(int size);
void print_deck(Card* deck, int size, Stringplace prefix);
