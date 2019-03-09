#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files/print_faro_val.h"

typedef struct Card Card;
struct Card {
  char rank;
  char suit;
  Card *next;
};

Card* get_cards(int size);
void print_deck(Card* deck, int size, Stringplace prefix);
Card* shuffle(Card* top, Card* bot,int size);
Card* split(Card* deck, int size);
void faro(Card* deck,int size, int* k_binary, int k_length);
int* decToBinary(int number, int* length);
