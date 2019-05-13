#include "Node.h"
#include "Operation.h"
#include <string>

#ifndef OPERATOR_
#define OPERATOR_

class Operator:public Node{

public:   

  //Setters

  void set_second_next(Node* newval) override;

  //Getters
  Operation* oper() const override; 
  Node* second_next() const override;

  //Methods
  std::string WhatAmI() const  override;
  std::string print() const override;
  //Constructors
  Operator() ;
  Operator(Operation *op);

  //Destructor
  ~Operator();
    
protected:
   Operation* oper_ ;
   Node* second_next_ ;
  
  
};

#endif // OPERATOR_ 
