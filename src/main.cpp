#include <iostream>
#include <iomanip>
#include "Cache.h"
#include "Utils.h"
using namespace std;

int main()
{
  Cache cache;

  string input;

  int address, operation;
  string data;

  string bin_address;

  string output = "", cpuResult;

  while (cin >> address)
  {
    bin_address = Utils::dec_to_bin_32(address);
    cin >> operation;
    output += to_string(address) + " " + to_string(operation);
    if (operation == 1)
    {
      cin >> data;
      cpuResult = cache.write(bin_address, data);
      output += " " + data;
    }
    else if (operation == 0)
    {
      cpuResult = cache.read(bin_address);
    }
    output += " " + cpuResult + "\n";
  }

  cout << setprecision(3) << "READS:"
       << " " << cache.getReads() << endl
       << "WRITES:"
       << " " << cache.getWrites() << endl
       << "HITS:"
       << " " << cache.getHits() << endl
       << "MISSES:"
       << " " << cache.getMisses() << endl
       << "HIT RATE:"
       << " " << cache.getHitRate() << endl
       << "MISS RATE:"
       << " " << cache.getMissRate() << endl
       << endl
       << output;

  return 0;
}