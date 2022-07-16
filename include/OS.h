#ifndef OS_H
#define OS_H

#include <string>
#include "Cache.h"
#include "MainMemory.h"
using namespace std;

class OS
{
private:
  Cache cache;
  MainMemory memory;

  int reads;
  int writes;
  int hits;
  int misses;

public:
  OS();
  ~OS();
  string read(string bin_address);
  string write(string bin_address, string data);
  int getReads();
  int getWrites();
  int getHits();
  int getMisses();
  int getHitRate();
  int getMissRate();
};

#endif