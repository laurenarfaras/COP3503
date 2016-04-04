#include <iostream>


//int current = -1;

class Stack {

private:
  std::string arr[1000];
  std::string werds[100];
  int werdcount = 0;
  int current = -1;

public:
void push(std::string word) {
  ++current;
  arr[current] = word;
}

int pop() {
  if (current < 0) {
    //nothing to pop
    return -1;
  } else {
    --current;
    return current;
    //if pop was successful
  }
  //std::string temp = arr[current];
  //--current;
  //return temp;
}

int size () {
  return current + 1;
}



};
