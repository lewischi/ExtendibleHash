#ifndef ExtendibleLeafH
#define ExtendibleLeafH

#include "ExtendibleHash.h"

class ExtendibleLeaf
{
private:
  int index;
  int length;
  int *arr;

public:
  ExtendibleLeaf(int Lsize);
  //void split(ExtendibleLeaf **direct, int value, int bits);
  void insert(const int &object);
  ExtendibleLeaf* insert_full(const int &object, int bits, int dir_index); 
  void remove(int value);
  int find(int value);
  bool isFull();
  bool isEmpty();
  int size();
  int leaf_hash(int value, int bits);
  int get_sample();
};

#include "ExtendibleLeaf.cpp"
#endif
