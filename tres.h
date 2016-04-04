#include <iostream>

std::string arr[1000];
int current = -1;

class Stack {

void push(std::string word) {
  ++current;
  arr[current] = word;
}

std::string pop() {
  std::string temp = arr[current];
  --current;
  return temp;
}

void keywords

};
