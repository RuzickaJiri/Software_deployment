#include <string>
#include "Operation.h"

#ifndef NODE_
#define NODE_

class Node{

public:   

  //Setters
    void set_next(Node* newval);
    void set_previous(Node* newval);
  //Getters
    Node* next();
    Node* previous();


  //Methods
    virtual std::string WhatAmI() const = 0;
  	virtual void set_second_next(Node* newval) ;
  	virtual Operation* oper() const ; 
  	virtual Node* second_next() const ;
    virtual int value() const ;
    
  //Constructors
    Node(const Node& model) ; // copy constructor - deleted
    Node() ; // constructor of node

    ~Node() = default ;	
    
protected:

  Node* next_; // adress of the next node 
  Node* previous_; // adress of the previous node 
  
};

#endif // NODE_ 
