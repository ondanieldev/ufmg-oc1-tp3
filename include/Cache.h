#ifndef CACHE_H
#define CACHE_H

#include <string>
#include "CacheBlock.h"
using namespace std;

class Cache
{
private:
  CacheBlock blocks[64];

  static const int totalSize = 32;
  static const int tagSize = 22;
  static const int indexSize = 6;
  static const int offsetSize = 2;
  static const int wordOffsetSize = 2;

  string getTag(string bin_address);
  string getIndex(string bin_address);
  string getOffset(string bin_address);
  string getWordOffset(string bin_address);

public:
  Cache();
  ~Cache();
  string read(string bin_address);
  bool write(string bin_address, string data);
};

#endif