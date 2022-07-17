#include <iostream>
#include "Cache.h"
#include "Utils.h"

Cache::Cache()
{
  this->reads = 0;
  this->writes = 0;
  this->hits = 0;
  this->misses = 0;
}

Cache::~Cache()
{
}

string Cache::get_tag(string bin_address)
{
  return bin_address.substr(0, Cache::tag_size);
}

string Cache::get_index(string bin_address)
{
  return bin_address.substr(Cache::tag_size, Cache::index_size);
}

string Cache::get_offset(string bin_address)
{
  return bin_address.substr(Cache::tag_size + Cache::index_size, Cache::offset_size);
}

string Cache::get_word_offset(string bin_address)
{
  return bin_address.substr(Cache::tag_size + Cache::index_size + Cache::offset_size, Cache::word_offset_size);
}

void Cache::copy_from_memory(string bin_address)
{
  string tag = this->get_tag(bin_address);
  string index = this->get_index(bin_address);
  string word_offset = this->get_word_offset(bin_address);
  int dec_index = Utils::bin_to_dec_32(index);
  string memory_offset, memory_address;

  this->blocks[dec_index].tag = tag;
  this->blocks[dec_index].isValid = true;
  for (int i = 0; i < 4; ++i)
  {
    memory_offset = Utils::dec_to_bin_2(i);
    memory_address = tag + index + memory_offset + word_offset;
    this->blocks[dec_index].words[i] = this->memory.read(memory_address);
  }
}

string Cache::read(string bin_address)
{
  string tag = this->get_tag(bin_address);
  string index = this->get_index(bin_address);
  string offset = this->get_offset(bin_address);
  int dec_index = Utils::bin_to_dec_32(index);
  int dec_offset = Utils::bin_to_dec_32(offset);
  string data;

  this->reads++;

  if (this->blocks[dec_index].isValid && this->blocks[dec_index].tag == tag)
  {
    this->hits++;
    data = this->blocks[dec_index].words[dec_offset];
    return "H";
  }

  this->misses++;
  copy_from_memory(bin_address);
  data = this->blocks[dec_index].words[dec_offset];
  return "M";
}

string Cache::write(string bin_address, string data)
{
  string tag = this->get_tag(bin_address);
  string index = this->get_index(bin_address);
  string offset = this->get_offset(bin_address);
  int dec_index = Utils::bin_to_dec_32(index);
  int dec_offset = Utils::bin_to_dec_32(offset);

  this->writes++;

  if (!this->blocks[dec_index].isValid || this->blocks[dec_index].tag != tag)
  {
    copy_from_memory(bin_address);
  }

  this->blocks[dec_index].words[dec_offset] = data;
  this->blocks[dec_index].isDirty = true;
  return "W";
}

int Cache::getReads()
{
  return this->reads;
}

int Cache::getWrites()
{
  return this->writes;
}

int Cache::getHits()
{
  return this->hits;
}

int Cache::getMisses()
{
  return this->misses;
}

float Cache::getHitRate()
{
  return (float(this->hits) / float(this->hits + this->misses));
}

float Cache::getMissRate()
{
  return (float(this->misses) / float(this->hits + this->misses));
}
