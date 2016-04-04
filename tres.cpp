#include <iostream>
#include <fstream>
#include "tres.h"

int main(int argc, char **args) {

  if (argc !=2) {
    //crash
    std::cout << "sorry filename input needed" << std::endl;
    return 1;
  }

  std::cout << "hello you made it" << std::endl;


  //make a string of the name of the file
  std::string filename(args[1]);
  std::cout << filename << std::endl;

  //read from the file test1.txt
  std::ifstream ifs("test1.txt");
  int i = 0;
  bool for = false;
  while (ifs) {
    std::string temp_in;
    ifs >> temp_in;
    std::cout << temp_in << std::endl;

  }

  ifs.close();


}
