
#include "Leaf.h"
#include "Tree.h"
#include "Operator.h"
#include <iostream>

std::string Leaf::WhatAmI() const {
  return "Leaf" ;
}

//Constructor
Leaf::Leaf(std::vector<std::string> xlabels){
  int rand = std::rand() %2;
  if (rand == 0){
    int length=xlabels.size();
    int r = std::rand() % length;
    value_=xlabels[r];
  }
  else {
    value_="1";
  }

}

Leaf::Leaf(std::string s){
  
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

