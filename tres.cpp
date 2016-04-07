#include <iostream>
#include <fstream>
#include <string>
#include "tres.h"


bool search(std::string data[], std::string search, int size) {

  bool found = false;

  for (int i = 0; i < size; i++) {
    if (data[i].compare(search) == 0) {
      found = true;
    }
  }

  return found;
}


int main(int argc, char **args) {

  if (argc !=2) {
    //crash
    std::cout << "sorry filename input needed" << std::endl;
    return 1;
  }

  //std::cout << "hello you made it" << std::endl;

  Stack s;

  //make a string of the name of the file
  std::string filename(args[1]);
  //std::cout << filename << std::endl;

  //read from the file test1.txt
  std::ifstream ifs("test1.txt");
  int i = 0;
  std::string syntaxErr[100];
  int z = 0;
  std::string identifiers[100];
  int w = 0;
  std::string constants[100];

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
  bool p1 = false;
  bool p2 = false;
  bool plusplus = false;
  bool plus = false;
  bool doubleminus = false;
  bool minus = false;
  bool multiply = false;
  bool divide = false;

  bool found = false;

  while (ifs) {
    std::string temp_in;
    ifs >> temp_in;
    //std::cout << temp_in << std::endl;
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
      found = search(syntaxErr, temp_in, i);
      if (!found) {
        syntaxErr[i] = temp_in;
        ++i;
      }
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
            found = search(identifiers, fire, z);
            if (!found) {
              identifiers[z] = fire;
              ++z;
              fire = "";
            }
          }
          fire = "";
        } else if ((int)temp_in.at(a) == 59) {
          semicolon = true;
          if (fire.compare("") != 0) {
            found = search(identifiers, fire, z);
            if (!found) {
              identifiers[z] = fire;
              ++z;
              fire = "";
            }
          }
          fire = "";
        }
      }
      if (fire.compare("") != 0) {
        found = search(identifiers, fire, z);
        if (!found) {
          identifiers[z] = fire;
          ++z;
          fire = "";
        }
      }
    } else if ((int)temp_in.at(0) == 40) {
      std::string parent;
      for (int y = 0; y < temp_in.size(); y++) {
        if ((int)temp_in.at(y) == 40) {
          if (parent.compare("") != 0) {
            found = search(identifiers, parent, z);
            if (!found) {
              identifiers[z] = parent;
              ++z;
              parent = "";
            }
          }
        }else if ((int)temp_in.at(y) >= 97 && (int)temp_in.at(y) <= 122) {
          parent = parent + temp_in.at(y);
        }else if ((int)temp_in.at(y) == 44) {
          comma = true;
          if (parent.compare("") != 0) {
            found = search(identifiers, parent, z);
            if (!found) {
              identifiers[z] = parent;
              ++z;
              parent = "";
            }
          }
        }
      }
      if (parent.compare("") != 0) {
        found = search(identifiers, parent, z);
        if (!found) {
          identifiers[z] = parent;
          ++z;
          parent = "";
        }
      }
    } else if ((int)temp_in.at(0) >= 48 && (int)temp_in.at(0) <= 57) {
      std::string nochange;
      for (int x = 0; x < temp_in.size(); x++) {
        if ((int)temp_in.at(x) >= 48 && (int)temp_in.at(x) <= 57) {
          nochange = nochange + temp_in.at(x);
        } else if ((int)temp_in.at(x) == 44) {
          comma = true;
          if (nochange.compare("") != 0) {
            found = search(constants, nochange, w);
            if (!found) {
              constants[w] = nochange;
              ++w;
              nochange = "";
            }
          }

        }
      }
      if (nochange.compare("") != 0) {
        found = search(constants, nochange, w);
        if (!found) {
          constants[w] = nochange;
          ++w;
          nochange = "";
        }
      }
    } else if ((int)temp_in.at(0) == 43) {
      if (temp_in.size() > 1) {
        if ((int)temp_in.at(1) == 43) {
          plusplus = true;
        }
      } else {
        plus = true;
      }
    } else if ((int)temp_in.at(0) == 45) {
      if (temp_in.size() > 1) {
        if ((int)temp_in.at(1) == 45) {
          doubleminus = true;
        }
      } else {
        minus = true;
      }
    } else if ((int)temp_in.at(0) == 42) {
      multiply = true;
    } else if ((int)temp_in.at(0) == 61) {
      equals = true;
    } else if ((int)temp_in.at(0) == 47) {
      divide = true;
    }

  }

  ifs.close();

  std::cout << "Maximum depth of the nested loop(s): " << max_depth << std::endl;
  std::cout << "Keywords: ";
  if (rof) {
    std::cout << "FOR ";
  } if (nigeb) {
    std::cout << "BEGIN ";
  } if (dne) {
    std::cout << "END "<< std::endl;
  }

  std::cout << "Identifier(s): ";
  for (int k = 0; k < z; k++) {
    std::cout << identifiers[k] << " ";
  }
  std::cout << "" << std::endl;

  std::cout << "Constant(s): ";
  for (int v = 0; v < w; v++) {
    std::cout << constants[v] << " ";
  }
  std::cout << "" << std::endl;

  std::cout << "Operator(s): ";
  if (plusplus) {
    std::cout << "++ ";
  }
  if (equals) {
    std::cout << "= ";
  }
  if (plus) {
    std::cout << "+ ";
  }
  if (minus) {
    std::cout << "- ";
  }
  if (doubleminus) {
    std::cout << "-- ";
  }
  if (multiply) {
    std::cout << "* ";
  }
  if (divide) {
    std::cout << "/ ";
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

  std::cout << "Syntax Error(s): ";
  for (int j = 0; j < i; j++) {
    std::cout << syntaxErr[j];
  }
  std::cout << "" << std::endl;














}
