#include "Operator.h"
#include "Operation.h"
#include <iostream>

std::string Operator::WhatAmI() const {
  return "Operator" ;
}

//Constructor
Operator::Operator(){

  oper_ =  new Operation() ;
  second_next_ = nullptr ; //initialization of the next node on the null pointer
}

Operator::Operator(Operation *op){
  
  oper_ = op ;
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

void Operator::set_second_next(Node* newval){
  second_next_ = newval; 
}

std::string Operator::print() const {
  return "Operator" + oper_->operation() ;
}
