#include "Node.h"
#include "Operation.h"
#include <string>

#ifndef LEAF_
#define LEAF_

class Leaf:public Node{

public:   

  //Setters

  //Getters
  std::string value() const override;

  //Methods
  std::string WhatAmI() const override ;
    
  //Constructors
  Leaf() ;

  //Destructor
  ~Leaf();
    
protected:
  
  std::string value_ ;
  
  
};

#endif // LEAF_ 
