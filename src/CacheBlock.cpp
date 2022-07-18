#include "CacheBlock.h"

CacheBlock::CacheBlock()
{
  this->is_dirty = false;
  this->is_valid = false;
  this->tag = "";
  for (int i = 0; i < 4; ++i)
  {
    this->words[i] = "";
  }
}

CacheBlock::~CacheBlock()
{
}
