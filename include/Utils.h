#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

/**
 * @brief classe que armazena constantes e métodos de conversão de bases
 *
 */
class Utils
{
public:
  static const int WORD_SIZE = 32;       // cada palavra possui 32 bits
  static const int TAG_SIZE = 22;        // a tag utiliza 22 bits (31 ao 10)
  static const int INDEX_SIZE = 6;       // o índice utiliza 6 bits (9 ao 4)
  static const int OFFSET_SIZE = 2;      // o offset utiliza 2 bits (3 e 2)
  static const int WORD_OFFSET_SIZE = 2; // o offset de palavra utiliza 2 bits (1 e 0)
  static const int CACHE_SIZE = 64;      // a cache comporta 64 blocos
  static const int BLOCK_SIZE = 4;       // cada bloco comporta 4 palavras
  static const int MEMORY_SIZE = 4096;   // a memória comporta 1024 palavras. como cada uma possui 32 bits, cada palvra ocupa 4 posições (4096 entradas)

  /**
   * @brief constrói um novo objeto Utils
   *
   */
  Utils();

  /**
   * @brief destrói um objeto Utils
   *
   */
  ~Utils();

  /**
   * @brief converte um decimal para um binário de 32 bits
   *
   * @param decimal número decimal
   * @return string número binário
   */
  static string dec_to_bin_32(int decimal);

  /**
   * @brief converte um binário de até 32 bits para um decimal
   *
   * @param binary número binário
   * @return int número decimal
   */
  static int bin_to_dec_32(string binary);

  /**
   * @brief converte um decimal para um binário de 2 bits
   *
   * @param decimal número decimal
   * @return string número binário
   */
  static string dec_to_bin_2(int decimal);

  /**
   * @brief converte um binário de até 2 bits para um decimal
   *
   * @param binary número binário
   * @return string número decimal
   */
  static int bin_to_dec_2(string binary);
};

#endif