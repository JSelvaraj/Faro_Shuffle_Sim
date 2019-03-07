typedef struct Card Card;
struct Card {
  char rank;
  char suit;
  Card *next;
};



Card* get_cards();
