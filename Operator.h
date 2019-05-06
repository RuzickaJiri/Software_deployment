#include "Node.h"
#include "Operation.h"
#include <string>

#ifndef OPERATOR_
#define OPERATOR_

class Operator:public Node{

public:   

  //Setters
  void set_second_next(Node* newval);
  //Getters
  Operation* oper() const ; 
  Node* second_next() const ;

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
