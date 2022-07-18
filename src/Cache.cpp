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
  this->blocks[dec_index].is_valid = true;
  for (int i = 0; i < 4; ++i)
  {
    memory_offset = Utils::dec_to_bin_2(i);
    memory_address = tag + index + memory_offset + word_offset;
    this->blocks[dec_index].words[i] = this->memory.read(memory_address);
  }
}

void Cache::write_back(string bin_address)
{
  string index = get_index(bin_address);
  int dec_index = Utils::bin_to_dec_32(index);
  string tag = this->blocks[dec_index].tag;
  string word_offset = get_word_offset(bin_address);
  string memory_offset, memory_address;

  for (int i = 0; i < 4; ++i)
  {
    memory_offset = Utils::dec_to_bin_2(i);
    memory_address = tag + index + memory_offset + word_offset;
    this->memory.write(memory_address, this->blocks[dec_index].words[i]);
  }

  this->blocks[dec_index].is_dirty = false;
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

  if (this->blocks[dec_index].is_valid && this->blocks[dec_index].tag == tag)
  {
    this->hits++;
    data = this->blocks[dec_index].words[dec_offset];
    return "H";
  }

  this->misses++;
  if (this->blocks[dec_index].is_dirty)
  {
    write_back(bin_address);
  }
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

  if (!this->blocks[dec_index].is_valid || this->blocks[dec_index].tag != tag)
  {
    copy_from_memory(bin_address);
  }

  this->blocks[dec_index].words[dec_offset] = data;
  this->blocks[dec_index].is_dirty = true;
  return "W";
}

int Cache::get_reads()
{
  return this->reads;
}

int Cache::get_writes()
{
  return this->writes;
}

int Cache::get_hits()
{
  return this->hits;
}

int Cache::get_misses()
{
  return this->misses;
}

float Cache::get_hit_rate()
{
  return (float(this->hits) / float(this->hits + this->misses));
}

float Cache::get_miss_rate()
{
  return (float(this->misses) / float(this->hits + this->misses));
}
