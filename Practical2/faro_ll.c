#include "headers.h"

/*
@brief This function reads in a number of rank + suit values = to 'size' and returns the
head of a linked list of the deck of cards

@param size the number of values being read in.
*/
Card* get_cards_ranksuit(int size) {
  Card* head = NULL;
  Card* current_node;
  Card *new_node;
  fgetc(stdin);
  for (int i = 0; i < size; i++) {
    new_node = malloc(sizeof(Card));
    new_node->rank = fgetc(stdin);
    new_node->suit = fgetc(stdin);
    new_node->next = NULL;
    if (head == NULL) {
      head = new_node;
      current_node = new_node;
    } else {
      current_node->next = new_node;
      current_node = current_node->next;
    }
    if (i < (size -1)) { // The last card won't have a space after it
      fgetc(stdin);
    }
  }
  return head;
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
  Card* top_ptr = top;
  Card* bot_ptr = bot;
  top_ptr = top_ptr->next;
  current_node->next = bot_ptr;
  current_node = current_node->next;
  size -= 2;
  while (size > 0) {
    bot_ptr = bot_ptr->next;
    current_node->next = top_ptr;
    top_ptr = top_ptr->next;
    current_node = current_node->next;
    current_node->next = bot_ptr;
    current_node = current_node->next;
    size -= 2;
  }
  return new_deck;
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
  return bottom_half;
}
/*
@brief This function prints the deck of cards when its a linked list

@param deck the linked list of Cards being printed
@param size the length of the linked list 'deck'
@param prefix whether an IN shuffle or OUT shuffle was performed.

*/
void print_deck(Card* current_node, int size, Stringplace prefix) {
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
/**
@brief This function handles the faro shuffle by calling the other
functions.

@param deck is the deck of cards to be shuffled
@param size is the length of the deck
@param k_binary is the binary representation of the position k
specified by the user.
@param k_length is the length of the binary k

@return void
*/
void faro(Card** deck,int size, int* k_binary, int k_length) {
  Card* bottom_half = NULL;
  for (int i = k_length - 1; i >= 0; i--) {
    bottom_half = split(*deck, size);
    if (k_binary[i] == 1) {
      *deck = shuffle(bottom_half, *deck, size);
      print_deck(*deck, size, PREFIX_IN);
    } else {
      *deck = shuffle(*deck, bottom_half, size);
      print_deck(*deck, size, PREFIX_OUT);
    }
  }
}
/**
@brief This function takes the head node of the linked list of cards and
iteratively frees all the allocated memory from the list.

@param current_node the head node of the linked list
@param size the length of the linked list
*/
void free_ll(Card* current_node, int size) {
  while (size > 0) {
    Card* temp = current_node->next;
    free(current_node);
    current_node = temp;
    size--;
  }
}


/**
@brief This function handles the faro shuffle by calling the other
functions. Used for when the deck has numerical values.

@param deck is the deck of cards to be shuffled
@param size is the length of the deck
@param k_binary is the binary representation of the position k
specified by the user.
@param k_length is the length of the binary k

@return void
*/
void faro_numerical(Card** deck,int size, int* k_binary, int k_length) {
  Card* bottom_half = NULL;
  for (int i = k_length - 1; i >= 0; i--) {
    bottom_half = split(*deck, size);
    if (k_binary[i] == 1) {
      *deck = shuffle(bottom_half, *deck, size);
      print_deck_numerical(*deck, size, PREFIX_IN);
    } else {
      *deck = shuffle(*deck, bottom_half, size);
      print_deck_numerical(*deck, size, PREFIX_OUT);
    }
  }
}
/*
@brief This function prints the deck of cards with numerical values

@param deck the linked list of Cards being printed
@param size the length of the linked list 'deck'
@param prefix whether an IN shuffle or OUT shuffle was performed.

*/
void print_deck_numerical(Card* current_node, int size, Stringplace prefix) {
  int length = getIntLength(current_node->number);
  char* card = malloc((sizeof(char) * length) + 1);
  for (int i = 0; i < length - 1; i++) {
    card[i] = (char) "";
  }
  card[length - 1] = (char) NULL;
  print_faro_val("", prefix);
  while (size > 0) {
    sprintf(card,"%d",current_node->number);
    current_node = current_node->next;
    print_faro_val(card, CARD_VAL);
    size--;
  }
  print_faro_val("", SUFFIX);
}
/*
@brief This function reads in a number of numeric values = to 'size' and returns the
head of a linked list of the deck of cards

@param size the number of values being read in.
*/
Card* get_cards_numerical(int size) {
  Card* head = NULL;
  Card* current_node;
  Card *new_node;

  for (int i = 0; i < size; i++) {
    new_node = malloc(sizeof(Card));
    scanf("%d\n", &new_node->number);
    new_node->next = NULL;
    if (head == NULL) {
      head = new_node;
      current_node = new_node;
    } else {
      current_node->next = new_node;
      current_node = current_node->next;
    }
    if (i < (size -1)) {
    }
  }
  return head;
}
