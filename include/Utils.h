#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

class Utils
{
public:
  Utils();
  static string dec_to_bin(int decimal);
  static int bin_to_dec(string binary);
};

#endif