#include "headers.h"
#include <limits.h>

typedef struct Cart Cart;
struct Cart {
  char* value;
  unsigned int number; //for the NUMERICAL extension
  Cart* next;
};




Cart* get_cards(int size) {
  char* string = malloc((sizeof(wchar_t) * size) + (size * sizeof(char) * 2));
  fgets(string, (size * 5), stdin);
  // printf("%s\n", string);
  char* token = strtok(string, " ");

  Cart* head = NULL;
  Cart* current_node;
  Cart* new_node;
  while (token != NULL){
    // printf("%s ", token );
    new_node = malloc(sizeof(Cart));
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
      token = strtok(token,"\n");
    }
  }
  return head;
}

int main(void) {
  int size = 6;
  scanf("%d\n", &size);
  // fgetc(stdin);
  Cart* deck;
  deck = get_cards(size);
  print_faro_val("",PREFIX_IN);
  for (int i = 0; i < size; i ++) {
    // printf("%s",deck->value);
    print_faro_val(deck->value,CARD_VAL);
    deck = deck->next;
  }
  print_faro_val("",SUFFIX);

}
