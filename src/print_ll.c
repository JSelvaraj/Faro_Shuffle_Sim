#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
#include "files/print_faro_val.h"

/*
@brief This function prints the deck of cards if when its a linked list
*/
void print_deck(Card* deck, int size, Stringplace prefix) {
  Card* current_node = deck;
  char card[3];
  card[0] = (char) "";
  card[1] = (char) "";
  card[2] = (char) NULL; //the cast is to remove the warning
  print_faro_val("", prefix);
  while (size > 0) {
    card[0] = current_node->rank;
    card[1] = current_node->suit;
    current_node = current_node->next;
    print_faro_val(card, CARD_VAL);
    size--;
  }
  print_faro_val("", SUFFIX);
}
