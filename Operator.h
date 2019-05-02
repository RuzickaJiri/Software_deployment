#include "Node.h"
#include "Operation.h"
#include <string>

#ifndef OPERATOR_
#define OPERATOR_

class Operator:public Node{

public:   

  //Setters

  //Getters

  //Methods
  std::string WhatAmI() const override ;
    
  //Constructors
  Operator() ;

  //Destructor
  ~Operator();
    
protected:
   Operation* oper_ ;
   Node* second_next_ ;
  
  
};

#endif // OPERATOR_ 
