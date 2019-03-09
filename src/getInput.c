#include "headers.h"
/*
@brief This function reads in a number rank, suit values = to 'size' and returns the
head of a linked list of the deck of cards

@param size the number of values being read in.

*/

Card* get_cards(int size) {
  Card* head;
  Card* current_node;
  Card *new_node;
  fgetc(stdin);
  for (int i = 0; i < size; i++) {
    // printf("I am here\n");
    new_node = malloc(sizeof(Card));
    new_node->rank = fgetc(stdin);
    new_node->suit = fgetc(stdin);
    new_node->next = malloc(sizeof(Card));
    // printf("%c\n", new_node->rank);
    // printf("%c\n", new_node->suit);
    if (head == NULL) {
      head = new_node;
      current_node = new_node;
    } else {
      current_node->next = new_node;
      current_node = current_node->next;
    }
    if (i < (size -1)) {
      fgetc(stdin);
    }
  }
  // printf("here\n");
  return head;
}
