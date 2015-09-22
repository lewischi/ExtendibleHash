#ifndef EXTENDIBLE_HASH_H
#define EXTENDIBLE_HASH_H
  //#define EXTENDIBLE_LEAF_H

#include "ExtendibleLeaf.h"

class ExtendibleHash
{
  ExtendibleLeaf **directory;
  int bits;
  int size;
  int LeafSize;


public:
  friend class ExtendibleLeaf;
  ExtendibleHash(const int & notFound, int s, int LSize = 2);
  void insert(const int &object);
  ExtendibleLeaf* insert_full(const int &object, int bits, int dir_index);
  void remove(const int &object);
  const int & find(const int &object);
  void split(const int &object);
  int GetBits()const;

}; // class ExtendibleHashing

#include "ExtendibleHash.cpp"
#endif

