#include "Operator.h"
#include "Operation.h"
#include <iostream>

std::string Operator::WhatAmI() const {
  return "Operator" ;
}

Operator::Operator(){
  next_ = nullptr ; //initialization of the next node on the null pointer
  previous_ = nullptr ; //initialization of the previous node on the null pointer

  oper_ =  new Operation() ;
  second_next_ = nullptr ; //initialization of the next node on the null pointer
} 

Operator::~Operator(){
  delete oper_ ;
}
