#ifndef MAIN_MEMORY_H
#define MAIN_MEMORY_H

#include <string>
using namespace std;

class MainMemory
{
private:
  string words[1024];

public:
  MainMemory();
  ~MainMemory();
  string read(string bin_address);
  void write(string bin_address, string data);
};

#endif