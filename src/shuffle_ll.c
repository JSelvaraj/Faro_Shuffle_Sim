#include "headers.h"

/*
@brief This function iterates through a linked list and splits it at the halfway point.
then it returns the bottom half of the list.
*/

Card* split(Card* deck, int size) {
  int mid = size/2;
  Card* current_node = deck;
  for (int i = 0; i < mid; i++) {
    current_node = current_node->next;
  }
  Card* bottom_half = current_node->next;
  current_node->next = NULL;
  return bottom_half;
}

Card* shuffle(Card* top, Card* bot) {
  Card* new_deck = top;
  Card* current_node = top;
  Card* top_ptr = top;
  Card* bot_ptr = bot;
  top_ptr = top_ptr->next;
  current_node->next = bot_ptr;
  while (current_node->next != NULL) {
    bot_ptr = bot_ptr->next;
    current_node = current_node->next;
    current_node->next = top_ptr;
    top_ptr = top_ptr->next;
    current_node = current_node->next;
    current_node->next = bot_ptr;
  }
  return new_deck;
}
