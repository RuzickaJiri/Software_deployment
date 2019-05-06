#include "Operator.h"
#include "Operation.h"
#include <iostream>

std::string Operator::WhatAmI() const {
  return "Operator" ;
}

//Constructor
Operator::Operator(){
  next_ = nullptr ; //initialization of the next node on the null pointer
  previous_ = nullptr ; //initialization of the previous node on the null pointer

  oper_ =  new Operation() ;
  second_next_ = nullptr ; //initialization of the next node on the null pointer
} 

//Destructor
Operator::~Operator(){
  delete oper_ ;
}


//Getters
Operation* Operator::oper() const {
  return oper_ ;
}

Node* Operator::second_next() const {
  return second_next_ ;
}
