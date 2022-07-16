#ifndef CACHE_BLOCK_H
#define CACHE_BLOCK_H

#include <string>
using namespace std;

class CacheBlock
{
private:
  string tag;
  string words[4];
  bool isValid;
  bool isDirty;

public:
  CacheBlock();
  ~CacheBlock();

  friend class Cache;
};

#endif