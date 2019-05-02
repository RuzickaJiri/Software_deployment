#include "Leaf.h"
#include <iostream>

std::string Leaf::WhatAmI() const {
  return "Leaf" ;
}

Leaf::Leaf(){
  next_ = nullptr ; //initialization of the next node on the null pointer
  previous_ = nullptr ; //initialization of the previous node on the null pointer

  value_ = 0 ; //initialization of the next node on the null pointer
} 

Leaf::~Leaf(){
}
