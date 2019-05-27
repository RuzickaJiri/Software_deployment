
#include "Leaf.h"
#include "Tree.h"
#include "Operator.h"
#include <iostream>

std::string Leaf::WhatAmI() const {
  return "Leaf" ;
}

//Constructor
Leaf::Leaf(std::vector<std::string> xlabels){
  next_ = nullptr ; //initialization of the next node on the null pointer
  previous_ = nullptr ; //initialization of the previous node on the null pointer
  int length=xlabels.size();
  int r = std::rand() % length;
  value_=xlabels[r];

}

Leaf::Leaf(std::string s){
  next_ = nullptr ; //initialization of the next node on the null pointer
  previous_ = nullptr ; //initialization of the previous node on the null pointer
  
  value_ = s;
}


//Destructor
Leaf::~Leaf(){
}

//Getters
std::string Leaf::value() const {
  return value_ ;
}

std::string Leaf::print() const {
  return "Leaf";
}

