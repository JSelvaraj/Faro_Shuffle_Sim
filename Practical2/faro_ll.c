#include "headers.h"
#include "files/print_faro_val.h"

/*
@brief This function reads in a number of rank + suit values = to 'size' and returns the
head of a linked list of the deck of cards

@param size the number of values being read in.
*/
Card* get_cards_ranksuit(int size) {
  char* string = malloc((sizeof(wchar_t) * size) + (size * sizeof(char) * 2));
  fgetc(stdin); //unknown why but function doesn't work without this
  fgets(string, (sizeof(wchar_t) * size) + (size * sizeof(char) * 2), stdin);
  char* token = strtok(string, " ");
  Card* head = NULL;
  Card* current_node;
  Card* new_node;
  while (token != NULL){
    new_node = malloc(sizeof(Card));
    new_node->value = token;
    new_node->next = NULL;
    if (head == NULL) {
      head = new_node;
      current_node = new_node;
    } else {
      current_node->next = new_node;
      current_node = current_node->next;
    }
    token = strtok(NULL," ");
    size--;
    if (size == 1) {
      token = strtok(token,"\n"); // removes newline char from last token
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
Card* shuffle(Card* top_ptr, Card* bot_ptr, int size) {
  Card* new_deck = top_ptr;
  Card* current_node = top_ptr;
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
  print_faro_val("", prefix);
  while (size > 0) {
    print_faro_val(current_node->value, CARD_VAL);
    current_node = current_node->next;
    size--;
  }
  print_faro_val("", SUFFIX);
}
/**
@brief This function takes the head node of the linked list of cards and
iteratively frees all the allocated memory from the list.

@param current_node the head node of the linked list
@param size the length of the linked list
*/
void free_ll(Card* current_node, int size, int k) {
  for (int i = 0; i < size; i++) {
    Card* temp = current_node->next;
    if(i == k) {
       /*the first value should be in position k of the linked list
       therefore only the value in position k needs to be freed for
       all the vales to be freed.*/
      free(current_node->value);
    }
    free(current_node);
    current_node = temp;
  }
}
/**
@brief This function calculates the length of a decimal number.
It is used to calculate how much memory needs to be mallocd
to contain a string for that number

@param n is the number being measured
*/
int getIntLength(int n) {
  int length = 0;
  while (n > 0) {
    n = n / 10;
    length++;
  }
  return length;
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
void faro(Card** deck,int size, int* k_binary, int k_length, int k) {
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
  free_ll(*deck, size, k);
  free(k_binary);
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
    scanf("%d", &new_node->number);
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
