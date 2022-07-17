#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

class Utils
{
public:
  Utils();
  static string dec_to_bin_32(int decimal);
  static int bin_to_dec_32(string binary);
  static string dec_to_bin_2(int decimal);
  static int bin_to_dec_2(string binary);
};

#endif