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
  std::string syntaxErr[100];
  int z = 0;
  std::string identifiers[100];

  bool fur = false;
  int depth = 0;
  int max_depth = 0;
  std::string keyfor = "FOR";
  bool rof = false;
  std::string keybegin = "BEGIN";
  bool nigeb = false;
  std::string keyend = "END";
  bool dne = false;

  bool equals = false;
  bool semicolon = false;
  bool comma = false;

  while (ifs) {
    std::string temp_in;
    ifs >> temp_in;
    std::cout << temp_in << std::endl;
    if (temp_in.compare("") == 0) {
      break;
    }
    //check for the keyword FOR
    else if (temp_in.compare(keyfor) == 0) {
      //std::cout << "I am in the FOR if statement" << std::endl;
      fur = true;
      rof = true;
      s.push("FOR");
      //compare the current depth with the max_depth and change as needed
      depth = s.size();
      if (depth > max_depth) {
        max_depth = depth;
      }
    }
    //check for the keyword BEGIN
    else if (temp_in.compare(keybegin) == 0) {
      nigeb = true;
      if (fur) {
        //std::cout << "I should be increasing depth" << std::endl;
        //s.push("BEGIN");
        //depth = s.size();
        //if (depth > max_depth) {
        //  max_depth = depth;
        //}
        fur = false;
      }
    }
    //check for the keyword END
    else if (temp_in.compare(keyend) == 0) {
      dne = true;
      s.pop();
    }
    //check to see there is a syntax error
    else if ((int)temp_in.at(0) >= 65 && (int)temp_in.at(0) <= 90) {
      syntaxErr[i] = temp_in;
      ++i;
      //std::cout << "i=" << i << std::endl;
    }
    //check to see if an identifier
    else if ((int)temp_in.at(0) >= 97 && (int)temp_in.at(0) <= 122) {
      std::string fire;
      for (int a = 0; a < temp_in.size(); a++) {
        if ((int)temp_in.at(a) >= 97 && (int)temp_in.at(a) <= 122) {
          fire = fire + temp_in.at(a);
        } else if ((int)temp_in.at(a) == 61) {
          equals = true;
          if (fire.compare("") != 0) {
            identifiers[z] = fire;
            ++z;
            fire = "";
          }
        } else if ((int)temp_in.at(a) == 59) {
          semicolon = true;
          if (fire.compare("") != 0) {
            identifiers[z] = fire;
            ++z;
            fire = "";
          }
        }
      }
      if (fire.compare("") != 0) {
        identifiers[z] = fire;
        ++z;
        fire = "";
      }
    } else if ((int)temp_in.at(0) == 40) {
      std::string parent;
      for (int y = 0; y < temp_in.size(); y++) {
        if ((int)temp_in.at(y) == 40) {
          identifiers[z] = parent;
          ++z;
          parent = "";
        }else if ((int)temp_in.at(y) >= 97 && (int)temp_in.at(y) <= 122) {
          parent = parent + temp_in.at(y);
        }else if ((int)temp_in.at(y) == 44) {
          comma = true;
          identifiers[z] = parent;
          ++z;
          parent = "";
        }
      }
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

  std::cout << "Syntax Error(s): ";
  for (int j = 0; j < i; j++) {
    std::cout << syntaxErr[j];
  }
  std::cout << "" << std::endl;

  //std::cout << "identifire: " << identifiers[0] << std::endl;

  std::cout << "Identifier(s): ";
  for (int k = 0; k < z; k++) {
    std::cout << identifiers[k] << " ";
  }
  std::cout << "" << std::endl;

  std::cout << "Operator(s): ";
  if (equals) {
    std::cout << "= ";
  }
  std::cout << "" << std::endl;

  std::cout << "Delimiter(s): ";
  if (semicolon) {
    std::cout << "; ";
  }
  if (comma) {
    std::cout << ",";
  }
  std::cout << "" << std::endl;


}
