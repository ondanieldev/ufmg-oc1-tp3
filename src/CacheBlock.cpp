#include "CacheBlock.h"

CacheBlock::CacheBlock()
{
  this->isDirty = false;
  this->isValid = false;
  this->tag = "";
  for (int i = 0; i < 4; ++i)
  {
    this->words[i] = "";
  }
}

CacheBlock::~CacheBlock()
{
}
