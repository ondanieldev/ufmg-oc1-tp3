#include <iostream>
#include "OS.h"
#include "Utils.h"
using namespace std;

int main()
{
  OS os;

  string input;

  int address, operation;
  string data;

  string bin_address;

  string output = "", cpuResult;

  while (cin >> address)
  {
    bin_address = Utils::dec_to_bin(address);
    cin >> operation;
    output += to_string(address) + " " + to_string(operation);
    if (operation == 1)
    {
      cin >> data;
      cpuResult = os.write(bin_address, data);
      output += " " + data;
    }
    else if (operation == 0)
    {
      cpuResult = os.read(bin_address);
    }
    output += " " + cpuResult + "\n";
  }

  cout << "READS:"
       << " " << os.getReads() << endl
       << "WRITES:"
       << " " << os.getWrites() << endl
       << "HITS:"
       << " " << os.getHits() << endl
       << "MISSES:"
       << " " << os.getMisses() << endl
       << "HIT RATE:"
       << " " << os.getHitRate() << endl
       << "MISS RATE:"
       << " " << os.getMissRate() << endl
       << output;

  return 0;
}