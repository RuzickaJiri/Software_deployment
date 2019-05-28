
#include "Leaf.h"
#include "Tree.h"
#include "Operator.h"
#include <iostream>

std::string Leaf::WhatAmI() const {
  return "Leaf" ;
}

//Constructor
Leaf::Leaf(std::vector<std::string> xlabels){

  int length=xlabels.size();
  int r = std::rand() % length;
  value_=xlabels[r];

}

Leaf::Leaf(std::string s){
  value_ = s;
}


//Destructor


//Getters
std::string Leaf::value() const {
  return value_ ;
}

std::string Leaf::print() const {
  return "Leaf";
}

