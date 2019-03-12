#include "headers.h"


/*
@brief This function converts a decimal number to its binary representation

@param number the number "k" that is to be converted
@param *length an integer point that will contain the length of the binary number

@return the binary number stored in a integer array in reverse format (i.e. most
significant bit stored last and least significant stored first)
*/

int* decToBinary(int number, int* length) {
  *length = log10(number)/log10(2); // same as log2(number)
  (*length)++;
  int* binary = malloc(sizeof(int) * *length);
  int i = 0;
  while (number > 0) {
      binary[i] = number % 2;
      number = number / 2;
      i++;
  }
  return binary;
}
