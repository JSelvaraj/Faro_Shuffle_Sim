#include "headers.h"

/*
@brief This function iterates through a linked list and splits it at the halfway point.
then it returns the bottom half of the list.

@param deck the linked list representing the deck of cards. Half of the deck is
split into a new linked list.
@param size the size of the deck of cards.

@return bottom_half the bottom half of the 'deck' linked list.


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

/**
  @brief This function interweaves two equal length linked lists. Taking one
  node from top then from bottom, repeated until the end of the linked lists.

  @param top the elements of this linked list will make up the 1st, 3rd etc.
  elements of the list being returned.
  @param bot the the elements of this linked list will make up the 2nd, 4th etc.
  elements of the list being returned.

  @return new_deck the linked list made by interweaving the top and bot linked
  lists.
*/


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
