#include "CacheBlock.h"

CacheBlock::CacheBlock()
{
  this->is_dirty = false;
  this->is_valid = false;
  this->tag = "";
  for (int i = 0; i < Utils::BLOCK_SIZE; ++i)
  {
    this->words[i] = "";
  }
}

CacheBlock::~CacheBlock()
{
}
