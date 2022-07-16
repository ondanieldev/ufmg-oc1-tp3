#include <iostream>
#include "OS.h"

OS::OS()
{
  this->reads = 0;
  this->writes = 0;
  this->hits = 0;
  this->misses = 0;
}

OS::~OS()
{
}

string OS::read(string bin_address)
{
  string data;
  this->reads++;
  data = this->cache.read(bin_address);
  if (data != "miss")
  {
    this->hits++;
    return "H";
  }
  this->misses++;
  data = this->memory.read(bin_address);
  return "M";
}

string OS::write(string bin_address, string data)
{
  this->writes++;
  this->cache.write(bin_address, data);
  return "W";
}

int OS::getReads()
{
  return this->reads;
}

int OS::getWrites()
{
  return this->writes;
}

int OS::getHits()
{
  return this->hits;
}

int OS::getMisses()
{
  return this->misses;
}

int OS::getHitRate()
{
  return this->hits / (this->hits + this->misses);
}

int OS::getMissRate()
{
  return this->misses / (this->hits + this->misses);
}
