#ifndef CACHE_H
#define CACHE_H

#include <string>
#include "CacheBlock.h"
#include "MainMemory.h"
using namespace std;

class Cache
{
private:
  static const int tota_sSize = 32;
  static const int tag_size = 22;
  static const int index_size = 6;
  static const int offset_size = 2;
  static const int word_offset_size = 2;

  MainMemory memory;
  CacheBlock blocks[64];
  int reads;
  int writes;
  int hits;
  int misses;

  string get_tag(string bin_address);
  string get_index(string bin_address);
  string get_offset(string bin_address);
  string get_word_offset(string bin_address);
  void copy_from_memory(string bin_address);
  void write_back(string bin_address);

public:
  Cache();
  ~Cache();
  string read(string bin_address);
  string write(string bin_address, string data);
  int getReads();
  int getWrites();
  int getHits();
  int getMisses();
  float getHitRate();
  float getMissRate();
};

#endif