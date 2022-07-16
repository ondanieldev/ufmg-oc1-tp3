#ifndef CACHE_H
#define CACHE_H

class Cache
{
private:
  int reads;
  int writes;
  int hits;
  int misses;

public:
  Cache();
  ~Cache();
  void read();
  void write();
};

#endif