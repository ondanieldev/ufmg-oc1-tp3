#ifndef CACHE_BLOCK_H
#define CACHE_BLOCK_H

#include <string>
#include "Utils.h"
using namespace std;

/**
 * @brief classe cujos objetos armazenam os dados e controles de cada bloco da cache
 *
 */
class CacheBlock
{
private:
  // armazena a tag e as palavras do bloco
  string tag;
  string words[Utils::BLOCK_SIZE];

  // controla se o bloco está em uso
  bool is_valid;

  // constrola se o bloco foi alterado e ainda não foi persistido na memória
  bool is_dirty;

public:
  /**
   * @brief constrói um novo objeto CacheBlock
   *
   */
  CacheBlock();

  /**
   * @brief destrói um objeto CacheBlock
   *
   */
  ~CacheBlock();

  /**
   * @brief permite que as propriedades privadas sejam acessadas pelos objetos do tipo Cache
   *
   */
  friend class Cache;
};

#endif