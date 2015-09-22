// Derek Chung  ID#
// Lewis Chi  966905905

//#include "ExtendibleHash.h"
#include "ExtendibleLeaf.h"

//using namespace std;

ExtendibleLeaf::ExtendibleLeaf(int Lsize)
{
  index = 0;
  length = Lsize;
  arr = new int[Lsize];
}

int ExtendibleLeaf::find(int value)
{
  for(int i = 0; i < index; i++)
  {
    if(arr[i] == value)
      return value;
  }
  return -1;
}

void ExtendibleLeaf::insert(const int &object)
{
  arr[index] = object;
  index++;
}

ExtendibleLeaf* ExtendibleLeaf::insert_full(const int &object, int bits, int dir_index) // O(1)
{
  ExtendibleLeaf* new_leaf = new ExtendibleLeaf(length);
  bool leaf_inserted = false;
  for(int i = 0; i < length; i++)
  {
    if(leaf_hash(arr[i], bits) == dir_index)
    {
      new_leaf->insert(arr[i]);
      remove(arr[i]);
      leaf_inserted = true;
    }
  }

  if(leaf_inserted)
  {
    return new_leaf;
  }
  /*
  else
  {
    return NULL;
  }
*/
  return NULL;
}

int ExtendibleLeaf::get_sample()
{
  return arr[0];
}

void ExtendibleLeaf::remove(int value) // void or int?
{
  int temp;
  
  for(int i = 0; i < index; i++)  
  {
    if(arr[i] == value) // if value is found
    {
      arr[i] = arr[index - 1];
      index--;
    }
  }  
}
/*
void ExtendibleLeaf::split(ExtendibleLeaf **direct, int value, int bits) // bool this?
{
  int temp;
  int mask = EHash(value, bits);
  for(int i = 0; i < index; i++)
  {
    temp = EHash(arr[i], bits);
    if temp != mask; // found a leaf value to split
  }
  
  int newMask = EHash(arr[i], bits);
  direct[newMask] = new ExtendibleLeaf(LSize);
  arr[index] = value;
  direct[newMask] = arr[newMask];// insert into new MIGHT HAVE TO WRITE SEPARATE FUNCTION
  index++;
  
  for(int j = 0; i < LSize; i++) // delete from old
  {
    if(EHash(data[j], bits) = newMask) 
    {
      
      arr[newMark] //insert into new
      // delete from old
      j--; // shif 
    }
  }
  
}

*/

int ExtendibleLeaf::leaf_hash(int value, int bits)
{
  return value >> (18 - bits) ;
} // Ehash()

bool ExtendibleLeaf::isFull(){return index == length;}

bool ExtendibleLeaf::isEmpty()
{ return (index == 0);} 

int ExtendibleLeaf::size()
{return index;}

