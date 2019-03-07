#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
#include "files/print_faro_val.h"
/*
  @brief This function prints the deck of cards if when its a linked list
*/

void print_deck(Card* deck, int size) {
  Card* current_node = deck;
  char card[3] = {0,0,"\0"};
  char* card_ptr = NULL;
  while (size > 0) {
    card[0] = current_node->rank;
    card[1] = current_node->suit;
    current_node = current_node->next;
    print_faro_val("", PREFIX_IN);
    print_faro_val(*card_ptr, CARD_VAL);
    print_faro_val("", SUFFIX);
    size--;
  }
}
