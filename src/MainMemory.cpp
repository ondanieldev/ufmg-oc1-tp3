#include "MainMemory.h"
#include "Utils.h"

MainMemory::MainMemory()
{
  for (int i = 0; i < Utils::MEMORY_SIZE; ++i)
  {
    this->words[i] = "data_" + to_string(i);
  }
}

MainMemory::~MainMemory()
{
}

string MainMemory::read(string bin_address)
{
  int address = Utils::bin_to_dec_32(bin_address);
  return this->words[address];
}

void MainMemory::write(string bin_address, string data)
{
  int address = Utils::bin_to_dec_32(bin_address);
  this->words[address] = data;
}