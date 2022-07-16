#include "MainMemory.h"
#include "Utils.h"

MainMemory::MainMemory()
{
}

MainMemory::~MainMemory()
{
}

string MainMemory::read(string bin_address)
{
  int address = Utils::bin_to_dec(bin_address);
  return this->words[address];
}

void MainMemory::write(string bin_address, string data)
{
  int address = Utils::bin_to_dec(bin_address);
  this->words[address] = data;
}