#include <stdio.h>
#include <math.h>  
#include "ExtendibleHash.h"
#include "LinkedList.h"
#include "ExtendibleLeaf.h" 

int Ehash(int value, int bits)
{
  return value >> (18 - bits) ;
} // Ehash()

ExtendibleHash::ExtendibleHash(const int & notFound, int b, int LSize) :
  bits(b), LeafSize(LSize)
{
    size = pow(2, 18 - bits);
    directory = new ExtendibleLeaf* [size];
    directory[0] = new ExtendibleLeaf(LeafSize);
    for(int i = 1; i < (18 - bits) * 2; i++)
    {
      directory[i] = directory[0];
    }
} // ExtendibleHash()

void ExtendibleHash::insert(const int &object)
{
    //parse through the directory
    // check if full
    // if not full then insert
    // else split
    
  int mask = Ehash(object, bits);
  //splits if directory is full
  if(!directory[mask]->isFull())
  {
    directory[mask]->insert(object);
  }

  else
  {
    ExtendibleLeaf *new_leaf = directory[mask]->insert_full(object, bits, mask);
    while(new_leaf == NULL);
    {
      split(object);
      new_leaf = directory[mask]->insert_full(object, bits, mask);
    }  
    mask = Ehash(new_leaf->get_sample(), bits);
    directory[mask] = new_leaf;
  
  }
} // insert()


void ExtendibleHash::remove(const int &object)
{   
  int mask = Ehash(object, bits);  
  
  // delete value
  directory[mask]->remove(object);  
}  // remove()


const int & ExtendibleHash::find(const int &object)
{
  // extract bits from find value
  // compare with the parents
  // iterate through leafnode
  // if there -> found
  // if not, return notFound
  //
  int mask = Ehash(object, bits);

  return directory[mask]->find(object);  
}  // find()



void ExtendibleHash::split(const int &object)
{
    
    ExtendibleLeaf **temp = new ExtendibleLeaf*[size * 2];
    //iterate the array and put one pointer to two pointers. 
    for(int curr_pos = 0, temp_pos = 0; curr_pos < size; curr_pos++, temp_pos+=2)
    {
      temp[temp_pos] = directory[curr_pos];
      temp[temp_pos + 1] = directory[curr_pos];
    }
    
    size *= 2;
    bits++;

    delete[] *directory;

    directory = temp;
  //temp = NULL;
  // update length
  // children will point to 2 parents
  // iterate through array, find first item that can be moved, then stop
  // move item into new leaf
  // move anything else that can fit in that one leaf

 
}  // split()


int ExtendibleHash::GetBits()const 
{
  return bits;
}
