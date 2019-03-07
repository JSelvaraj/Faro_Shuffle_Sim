#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"





/* This function reads in a number rank, suit values = to size and returns the
head of a linked list of the deck of cards*/

Card* get_cards(int size) {
  Card* head; 
  Card* current_node;
  head = NULL;
   do {
    Card *new_node = malloc(sizeof(Card));
    new_node->rank = (char) fgetc(stdin);
    new_node->suit = (char) fgetc(stdin);
    new_node->next = NULL;
    if (head == NULL) {
      head = new_node;
      current_node = new_node;
    } else {
      current_node->next = new_node;
      current_node = current_node->next;
    }
  } while (fgetc(stdin) != EOF);
  return head;
}
