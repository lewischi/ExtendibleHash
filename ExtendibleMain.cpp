// Author: Sean Davis
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "ExtendibleHash.h"

using namespace std;
int main(int argc, char* argv[])
// argv[1] is data filename in the form: "Hash-" Maxsize "-" LeafSize "-"
//             StartBits "-" Seed ".dat"
{
  char command;
  int value, value2, StartBits, LeafSize;

  ifstream inf(argv[1]);//reads in the parameter
  strtok(argv[1], "-");//reads in the Maxsize
  strtok(NULL, "-"); //reads in LeafSize
  LeafSize = atoi(strtok(NULL, "-"));//Reads in StartBits
  StartBits = atoi(strtok(NULL, "-"));//Reads in Seed
  ExtendibleHash  hash(-1, StartBits, LeafSize);//creates an ExtendibleHash file called hash

  while(inf >> command)//reads in file contents
  {
    inf >> value;//value is what we insert/delete/find
    switch(command)//command: i, d, b, f
    {
      case 'i' : hash.insert(value); break;
      case 'd' : hash.remove(value); break;
      case 'f' :
        inf >> value2;//value2 is the value we are looking for
        if(value2 != hash.find(value))
          cout << "Bad find: Sought:" << value << " returned: " << hash.find(value) << endl;
        break;
      case 'b' :
        if(value != hash.GetBits())
          cout << "Bad bits: Expected: " << value << " got: " << hash.GetBits() << endl;
    } // switch
  } // while more in file
  return 0;
} // main()
