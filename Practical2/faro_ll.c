#include "headers.h"

/*
@brief This function reads in a number rank, suit values = to 'size' and returns the
head of a linked list of the deck of cards

@param size the number of values being read in.
*/
Card* get_cards(int size) {
  // printf("get_cards size: %d\n", size);
  Card* head = NULL;
  Card* current_node;
  Card *new_node;
  fgetc(stdin);
  for (int i = 0; i < size; i++) {
    // printf("I am here i:%d\n", i);
    new_node = malloc(sizeof(Card));
    new_node->rank = fgetc(stdin);
    new_node->suit = fgetc(stdin);
            // printf("I'm still here i:%d\n", i);
    new_node->next = NULL;
    // printf("%c\n", new_node->rank);
    // printf("%c\n", new_node->suit);
    if (head == NULL) {
            // printf("hiiiiashd");
      head = new_node;
      current_node = new_node;

    } else {
      current_node->next = new_node;
      current_node = current_node->next;
    }
    // printf("Omai wa Shindeiru\n");
    if (i < (size -1)) {
      // printf("test2\n");
      fgetc(stdin);
      // printf("test\n");
    }
  }
  // printf("here\n");
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
// printf("what\n");
  for (int i = 0; i < mid -1; i++) {
    // printf("Hi there\n");
    current_node = current_node->next;
    // printf("Hi there!!\n");
  }
  Card* bottom_half = current_node->next;
  current_node->next = NULL;
  // print_deck(deck, size/2, PREFIX_IN);
  // print_deck(bottom_half, size/2, PREFIX_IN);
  return bottom_half;
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
Card* faro(Card** deck,int size, int* k_binary, int k_length) {
  Card* bottom_half = NULL;
  // printf("General Kenobi!!\n");
  for (int i = k_length - 1; i >= 0; i--) {
    // printf("You were the chosen one\n");
    bottom_half = split(*deck, size);
    // printf("General Kenobi!!!\n");
    if (k_binary[i] == 1) {
      // printf("General Kenobi!\n");
      *deck = shuffle(bottom_half, *deck, size);
      print_deck(*deck, size, PREFIX_IN);
    } else {
      *deck = shuffle(*deck, bottom_half, size);
      print_deck(*deck, size, PREFIX_OUT);
    }
  }
  return *deck;

}

void free_ll(Card* current_node, int size) {
  while (size > 0) {
    Card* temp = current_node->next;
    free(current_node);
    current_node = temp;
    size--;
  }


  // if (deck->next != NULL) {
  //   free_ll(deck->next);
  // }
  // free(deck);
}
