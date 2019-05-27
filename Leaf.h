
#include "Node.h"
#include "Operation.h"
#include "Tree.h"
#include "Operator.h"
#include <iostream>





#ifndef LEAF_
#define LEAF_

class Leaf:public Node{

public:   

  //Setters

  //Getters
  std::string value() const override;

  //Methods
  std::string WhatAmI() const override ;
  std::string print() const override;
    
  //Constructors
  Leaf(std::vector<std::string> xlabels);
  Leaf(std::string s);

  //Destructor
  ~Leaf();
    
protected:
  
  std::string value_ ;
  
  
};

#endif // LEAF_ 
