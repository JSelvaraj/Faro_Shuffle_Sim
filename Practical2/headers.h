#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Card Card;
struct Card {
  char* value;
  unsigned int number; //for the NUMERICAL extension
  Card *next;
};

Card* get_cards_ranksuit(int size);
void faro(Card** deck,int size, int* k_binary, int k_length, int k);


Card* get_cards_numerical(int size);
void faro_numerical(Card** deck,int size, int* k_binary, int k_length);
