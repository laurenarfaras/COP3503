#include <iostream>
#include <cstdlib>

#include "pa2.h"

using namespace std;


int main(int argc, char ** argv) {
  for (int i = 0; i < argc; i++) {
    cout << "argv[" << i << "] = " << argv[i] << endl;
  }

  

  return 0;
}
