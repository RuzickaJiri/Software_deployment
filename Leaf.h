#include "Node.h"
#include <string>

#ifndef LEAF_
#define LEAF_

class Leaf:public Node{

public:   

  //Setters

  //Getters
  int value() const ;

  //Methods
  std::string WhatAmI() const override ;
    
  //Constructors
  Leaf() ;

  //Destructor
  ~Leaf();
    
protected:
  
  int value_ ;
  
  
};

#endif // LEAF_ 