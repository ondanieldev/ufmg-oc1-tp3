#include "CacheBlock.h"

CacheBlock::CacheBlock()
{
  this->isDirty = false;
  this->isValid = false;
  this->tag = "";
}

CacheBlock::~CacheBlock()
{
}
