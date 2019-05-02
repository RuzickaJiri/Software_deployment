#include <string>

#ifndef NODE_
#define NODE_

class Node{

public:   

  //Setters

  //Getters
    Node* next();
    Node* previous();

  //Methods
    virtual std::string WhatAmI() const = 0;
    
  //Constructors
    Node(const Node& model) ; // copy constructor - deleted
    Node() ; // constructor of node
    
protected:

  Node* next_; // adress of the next node 
  Node* previous_; // adress of the previous node 
  
};

#endif // NODE_ 
