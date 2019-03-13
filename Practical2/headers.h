#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**@struct Card
@brief this struct represents a single card in a deck of cards.
@var Card::value
Member value stores the rank and suit ofthe vard being read in
@var Card::number
Member 'number' stores the number if the NUMERICAL option is chosen.
@var Card::next
Member 'next' stores a pointer to the next card in a linked list of Cards.
*/
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
