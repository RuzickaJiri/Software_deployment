#include <iostream>
#include "Operation.h"

Operation::Operation(){
  int r = std::rand() %11;
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
    case 4 :
      operation_ = "^2";
      binary_ = false;
      break;
    case 5 :
      operation_ = "exp";
      binary_ = false;
      break;
    case 6 :
      operation_ = "sin";
      binary_ = false;
      break;
    case 7 :
      operation_ = "cos";
      binary_ = false;
      break;
    case 8 :
      operation_ = "^3";
      binary_ = false;
      break;
    case 9 :
      operation_ = "ln";
      binary_ = false;
      break;
    case 10 :
      operation_ = "--";
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


