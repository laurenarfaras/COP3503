#include <iostream>
#include <fstream>
#include <string>
#include "tres.h"

int main(int argc, char **args) {

  if (argc !=2) {
    //crash
    std::cout << "sorry filename input needed" << std::endl;
    return 1;
  }

  std::cout << "hello you made it" << std::endl;

  Stack s;

  //make a string of the name of the file
  std::string filename(args[1]);
  std::cout << filename << std::endl;

  //read from the file test1.txt
  std::ifstream ifs("test1.txt");
  int i = 0;

  bool fur = false;
  int depth = 0;
  int max_depth = 0;
  std::string keyfor = "FOR";
  bool rof = false;
  std::string keybegin = "BEGIN";
  bool nigeb = false;
  std::string keyend = "END";
  bool dne = false;

  while (ifs) {
    std::string temp_in;
    ifs >> temp_in;
    //std::cout << temp_in << std::endl;
    if (temp_in.compare(keyfor) == 0) {
      //std::cout << "I am in the FOR if statement" << std::endl;
      fur = true;
      rof = true;
    }
    else if (temp_in.compare(keybegin) == 0) {
      nigeb = true;
      if (fur) {
        //std::cout << "I should be increasing depth" << std::endl;
        s.push("BEGIN");
        depth = s.size();
        if (depth > max_depth) {
          max_depth = depth;
        }
        fur = false;
      }
    }
    else if (temp_in.compare(keyend) == 0) {
      dne = true;
      s.pop();
    }

  }

  ifs.close();

  std::cout << "Maximum depth of the nested loop(s): " << max_depth << std::endl;
  std::cout << "\nKeywords: ";
  if (rof) {
    std::cout << "FOR ";
  } if (nigeb) {
    std::cout << "BEGIN ";
  } if (dne) {
    std::cout << "END "<< std::endl;
  }



}
