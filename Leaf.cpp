#include "Leaf.h"
#include <iostream>

std::string Leaf::WhatAmI() const {
  return "Leaf" ;
}

//Constructor
Leaf::Leaf(){
  next_ = nullptr ; //initialization of the next node on the null pointer
  previous_ = nullptr ; //initialization of the previous node on the null pointer
  int r = std::rand() %2;
  switch(r) {
    case 0 :
      value_ = 0; //constant
      break;
    case 1 :
      value_ = 1; //variable
      break;
  }
} 

//Destructor
Leaf::~Leaf(){
}

//Getters
int Leaf::value() const {
  return value_ ;
}

std::string Leaf::print() const {
  return "Leaf" + value_;
}
