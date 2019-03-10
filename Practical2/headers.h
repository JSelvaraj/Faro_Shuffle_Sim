#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "files/print_faro_val.h"

typedef struct Card Card;
struct Card {
  char rank;
  char suit;
  unsigned int number; //for the NUMERICAL extension
  Card *next;
};

Card* get_cards_ranksuit(int size);
Card* get_cards_numerical(int size);
void print_deck(Card* deck, int size, Stringplace prefix);
Card* shuffle(Card* top, Card* bot,int size);
Card* split(Card* deck, int size);
void faro(Card** deck,int size, int* k_binary, int k_length);
int* decToBinary(int number, int* length);
void free_ll(Card* deck, int size);
void print_deck_numerical(Card* deck, int size, Stringplace prefix);

int getIntLength(int n);
