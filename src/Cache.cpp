#include <iostream>
#include "Cache.h"
#include "Utils.h"

Cache::Cache()
{
  this->reads = 0;
  this->writes = 0;
  this->hits = 0;
  this->misses = 0;

  for (int i = 0; i < Utils::CACHE_SIZE; ++i)
  {
    this->blocks[i].is_dirty = false;
    this->blocks[i].is_valid = false;
  }
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
  // extrai as partes do endereço
  string tag = this->get_tag(bin_address);
  string index = this->get_index(bin_address);
  string word_offset = this->get_word_offset(bin_address);
  int dec_index = Utils::bin_to_dec_32(index);
  string memory_offset, memory_address;

  // atualiza o bloco da cache, atribuindo uma cache e ligando o bit de validade
  this->blocks[dec_index].tag = tag;
  this->blocks[dec_index].is_valid = true;

  // para cada palavra que cabe no bloco, busca na memória e salva na cache
  for (int i = 0; i < Utils::BLOCK_SIZE; ++i)
  {
    memory_offset = Utils::dec_to_bin_2(i);
    memory_address = tag + index + memory_offset + word_offset;
    this->blocks[dec_index].words[i] = this->memory.read(memory_address);
  }
}

void Cache::write_back(string bin_address)
{
  // extrai as partes do endereço
  string index = get_index(bin_address);
  int dec_index = Utils::bin_to_dec_32(index);
  string tag = this->blocks[dec_index].tag;
  string word_offset = get_word_offset(bin_address);
  string memory_offset, memory_address;

  // para cada palavra do bloco da cache, atualiza a palavra na memória
  for (int i = 0; i < Utils::BLOCK_SIZE; ++i)
  {
    memory_offset = Utils::dec_to_bin_2(i);
    memory_address = tag + index + memory_offset + word_offset;
    this->memory.write(memory_address, this->blocks[dec_index].words[i]);
  }

  // uma vez que o bloco não precisa mais ser persistido na memória, o bit sujo pode ser desligado
  this->blocks[dec_index].is_dirty = false;
}

string Cache::read(string bin_address)
{
  // extrai as partes do endereço
  string tag = this->get_tag(bin_address);
  string index = this->get_index(bin_address);
  string offset = this->get_offset(bin_address);
  int dec_index = Utils::bin_to_dec_32(index);
  int dec_offset = Utils::bin_to_dec_32(offset);
  string data;

  // atualiza o número de leituras
  this->reads++;

  // se encontrar a palavra no bloco, então é um hit. pega o dado da cache
  if (this->blocks[dec_index].is_valid && this->blocks[dec_index].tag == tag)
  {
    this->hits++;
    data = this->blocks[dec_index].words[dec_offset];
    return "H";
  }

  // caso contrário, é um miss. o dado precisa ser buscado na memória
  this->misses++;
  // se o bloco estiver marcado como sujo, então é preciso persistir suas alterações na memória (write_back)
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
  // extrai as partes do endereço
  string tag = this->get_tag(bin_address);
  string index = this->get_index(bin_address);
  string offset = this->get_offset(bin_address);
  int dec_index = Utils::bin_to_dec_32(index);
  int dec_offset = Utils::bin_to_dec_32(offset);

  // atualiza o número de escritas
  this->writes++;

  // se não encontrar a palavra no bloco, então é um miss. copia o dado da memória
  if (!this->blocks[dec_index].is_valid || this->blocks[dec_index].tag != tag)
  {
    copy_from_memory(bin_address);
  }

  // independente de miss ou hit, o bloco já vai estar na cache nesse passo. pega o dado e marca o bloco como sujo
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
