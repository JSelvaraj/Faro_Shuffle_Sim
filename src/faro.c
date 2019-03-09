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
  for (int i = 0; i < mid -1; i++) {
    current_node = current_node->next;
  }
  Card* bottom_half = current_node->next;
  current_node->next = NULL;
  print_deck(shuffle(deck, bottom_half, size), size, PREFIX_IN);
  // print_deck(deck, size/2, PREFIX_IN);
  // print_deck(bottom_half, size/2, PREFIX_IN);
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
Card* shuffle(Card* top, Card* bot, int size) {
  Card* new_deck = top;
  Card* current_node = top;
  // printf("Current Node Val %c%c\n", current_node->rank, current_node->suit);
  Card* top_ptr = top;
  Card* bot_ptr = bot;
  top_ptr = top_ptr->next;
  current_node->next = bot_ptr;
  current_node = current_node->next;
  // printf("Current Node Val %c%c\n", current_node->rank, current_node->suit);
  size -= 2;
  while (size > 0) {
    bot_ptr = bot_ptr->next;
    current_node->next = top_ptr;
    top_ptr = top_ptr->next;
    current_node = current_node->next;
    // printf("Current Node Val %c%c\n", current_node->rank, current_node->suit);
    current_node->next = bot_ptr;
    current_node = current_node->next;
    // printf("Current Node Val %c%c\n", current_node->rank, current_node->suit);
    size -= 2;
    // printf("%d\n", size);
  }
  return new_deck;
}

/*
@brief This function prints the deck of cards when its a linked list

@param deck the linked list of Cards being printed
@param size the length of the linked list 'deck'
@param prefix whether an IN shuffle or OUT shuffle was performed.

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
