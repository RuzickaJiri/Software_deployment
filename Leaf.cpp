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
      value_ = "x1"; //constant
      break;
    case 1 :
      value_ = "x2"; //variable
      break;
  }
} 

//Destructor
Leaf::~Leaf(){
}

//Getters
std::string Leaf::value() const {
  return value_ ;
}
