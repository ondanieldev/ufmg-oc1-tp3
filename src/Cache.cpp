#include <iostream>
#include "Cache.h"
#include "Utils.h"

Cache::Cache()
{
}

Cache::~Cache()
{
}

string Cache::getTag(string bin_address)
{
  return bin_address.substr(0, Cache::tagSize);
}

string Cache::getIndex(string bin_address)
{
  return bin_address.substr(Cache::tagSize, Cache::indexSize);
}

string Cache::getOffset(string bin_address)
{
  return bin_address.substr(Cache::tagSize + Cache::indexSize, Cache::offsetSize);
}

string Cache::getWordOffset(string bin_address)
{
  return bin_address.substr(Cache::tagSize + Cache::indexSize + Cache::offsetSize, Cache::wordOffsetSize);
}

string Cache::read(string bin_address)
{
  string tag = this->getTag(bin_address);
  string index = this->getIndex(bin_address);
  string offset = this->getOffset(bin_address);
  int dec_index = Utils::bin_to_dec(index);
  int dec_offset = Utils::bin_to_dec(offset);
  if (this->blocks[dec_index].isValid && this->blocks[dec_index].tag == tag)
  {
    return this->blocks[dec_index].words[dec_offset];
  }
  return "miss";
}

bool Cache::write(string bin_address, string data)
{
  string tag = this->getTag(bin_address);
  string index = this->getIndex(bin_address);
  string offset = this->getOffset(bin_address);
  int dec_index = Utils::bin_to_dec(index);
  int dec_offset = Utils::bin_to_dec(offset);
  this->blocks[dec_index].isValid = true;
  this->blocks[dec_index].isDirty = true;
  this->blocks[dec_index].tag = tag;
  this->blocks[dec_index].words[dec_offset] = data;
}