#include <bitset>
#include "Utils.h"

#define ADDRESS_SIZE 32

string Utils::dec_to_bin(int decimal)
{
  string binary = bitset<ADDRESS_SIZE>(decimal).to_string();
  return binary;
}

int Utils::bin_to_dec(string binary)
{
  int decimal = std::bitset<ADDRESS_SIZE>(binary).to_ulong();
  return decimal;
}