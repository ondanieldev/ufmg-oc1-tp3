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

  string output = "", cpu_result;

  while (cin >> address)
  {
    bin_address = Utils::dec_to_bin_32(address);
    cin >> operation;
    output += to_string(address) + " " + to_string(operation);
    if (operation == 1)
    {
      cin >> data;
      cpu_result = cache.write(bin_address, data);
      output += " " + data;
    }
    else if (operation == 0)
    {
      cpu_result = cache.read(bin_address);
    }
    output += " " + cpu_result + "\n";
  }

  cout << setprecision(3) << "READS:"
       << " " << cache.get_reads() << endl
       << "WRITES:"
       << " " << cache.get_writes() << endl
       << "HITS:"
       << " " << cache.get_hits() << endl
       << "MISSES:"
       << " " << cache.get_misses() << endl
       << "HIT RATE:"
       << " " << cache.get_hit_rate() << endl
       << "MISS RATE:"
       << " " << cache.get_miss_rate() << endl
       << endl
       << output;

  return 0;
}