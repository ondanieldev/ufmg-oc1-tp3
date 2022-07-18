#ifndef CACHE_H
#define CACHE_H

#include <string>
#include "Utils.h"
#include "CacheBlock.h"
#include "MainMemory.h"
using namespace std;

/**
 * @brief classe que controla a cache e conversa com a memória sempre que precisa
 *
 */
class Cache
{
private:
  // variáveis que delimitam a quantidade de bits de cada parte do endereço
  static const int total_size = Utils::WORD_SIZE;
  static const int tag_size = Utils::TAG_SIZE;
  static const int index_size = Utils::INDEX_SIZE;
  static const int offset_size = Utils::OFFSET_SIZE;
  static const int word_offset_size = Utils::WORD_OFFSET_SIZE;

  // variáveis para apresentar os resultados dos acessos
  int reads;
  int writes;
  int hits;
  int misses;

  // memória que será acessada quando houver miss e quando realizar write_back
  MainMemory memory;

  // blocos da cache
  CacheBlock blocks[Utils::CACHE_SIZE];

  /**
   * @brief extrai a tag de um endereço
   *
   * @param bin_address endereço binário
   * @return string tag
   */
  string get_tag(string bin_address);

  /**
   * @brief extrai o índice de um endereço
   *
   * @param bin_address endereço binário
   * @return string índice
   */
  string get_index(string bin_address);

  /**
   * @brief extrai o offset de um endereço
   *
   * @param bin_address endereço binário
   * @return string offset
   */
  string get_offset(string bin_address);

  /**
   * @brief extrai o offset de palavra de um endereço
   *
   * @param bin_address endereço binário
   * @return string offset de palavra
   */
  string get_word_offset(string bin_address);

  /**
   * @brief copia um conjunto de palavras da memória para a cache
   *
   * @param bin_address endereço binário
   */
  void copy_from_memory(string bin_address);

  /**
   * @brief persiste, na memória, alterações que foram escritas na cache
   *
   * @param bin_address
   */
  void write_back(string bin_address);

public:
  /**
   * @brief constrói um novo objeto Cache
   *
   */
  Cache();

  /**
   * @brief destrói um objeto Cache
   *
   */
  ~Cache();

  /**
   * @brief lê o dado de um endereço da cache. em caso de miss, o dado é buscado na memória
   *
   */
  string read(string bin_address);

  /**
   * @brief escreve um dado em um endereço na cache.
   *
   */
  string write(string bin_address, string data);

  /**
   * @brief retorna o número de leituras
   *
   * @return int leituras
   */
  int get_reads();

  /**
   * @brief retorna o número de escritas
   *
   * @return int escritas
   */
  int get_writes();

  /**
   * @brief retorna o número de hits
   *
   * @return int
   */
  int get_hits();

  /**
   * @brief retorna o número de misses
   *
   * @return int
   */
  int get_misses();

  /**
   * @brief retorna a taxa de hits
   *
   * @return int
   */
  float get_hit_rate();

  /**
   * @brief retorna a taxa de misses
   *
   * @return int
   */
  float get_miss_rate();
};

#endif