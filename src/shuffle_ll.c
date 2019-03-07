#include "headers.h"

Card* split(Card* deck, int size) {
  int mid = size/2;
  Card* current_node = deck;
  for (int i = 0; i < mid; i++) {
    current_node = current_node->next;
  }
  Card* bottom_half = current_node->next;
  current_node->next = NULL;

}
