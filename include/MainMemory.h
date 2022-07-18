#ifndef MAIN_MEMORY_H
#define MAIN_MEMORY_H

#include <string>
#include "Utils.h"
using namespace std;

/**
 * @brief classe que controla a memória principal. será acessada através da cache em casos de miss e write_back
 *
 */
class MainMemory
{
private:
  // entradas da memória
  string words[Utils::MEMORY_SIZE];

public:
  /**
   * @brief constrói um novo objeto MainMemory
   *
   */
  MainMemory();

  /**
   * @brief destrói um objeto MainMemory
   *
   */
  ~MainMemory();

  /**
   * @brief lê o dado de um endereço da memória
   *
   */
  string read(string bin_address);

  /**
   * @brief escreve um dado em um endereço da memória
   *
   */
  void write(string bin_address, string data);
};

#endif