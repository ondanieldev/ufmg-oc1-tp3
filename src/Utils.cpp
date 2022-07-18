#include <bitset>
#include "Utils.h"

string Utils::dec_to_bin_32(int decimal)
{
  string binary = bitset<32>(decimal).to_string();
  return binary;
}

int Utils::bin_to_dec_32(string binary)
{
  int decimal = std::bitset<32>(binary).to_ulong();
  return decimal;
}

string Utils::dec_to_bin_2(int decimal)
{
  string binary = bitset<2>(decimal).to_string();
  return binary;
}

int Utils::bin_to_dec_2(string binary)
{
  int decimal = std::bitset<2>(binary).to_ulong();
  return decimal;
}