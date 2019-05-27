#include <iostream>
#include "Operation.h"

Operation::Operation(){
  int r = std::rand() %4;
  switch(r) {
    case 0 :
      operation_ = "+";
      binary_ = true;
      break;
    case 1 :
      operation_ = "-";
      binary_ = true;
      break;
    case 2 :
      operation_ = "*";
      binary_ = true;
      break;
    case 3 :
      operation_ = "/";
      binary_ = true;
      break;
  }
}

std::string Operation::operation() const{
  return operation_;
}

bool Operation::binary() const{
  return binary_;
}


