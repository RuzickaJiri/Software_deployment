#include <iostream>
#include "Operation.h"

Operation::Operation(){
  r = std::rand() %3;
  switch(r) {
    case 0 :
      operation_ = "AND";
      binary_ = true;
      break;
    case 1 :
      operation_ = "OR";
      binary_ = true;
      break;
    case 2 :
      operation_ = "NOT";
      binary_ = false;
      break;
  }
}

std::string Operation::operation() const{
  return operation_;
}

bool Operation::binary() const{
  return binary_;
}
