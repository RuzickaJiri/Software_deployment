#include "Node.h"
#include "Operation.h"
#include <iostream>

Node::Node(){
  next_ = nullptr ; //initialization of the next node on the null pointer
  previous_ = nullptr ; //initialization of the previous node on the null pointer
} 

// Getters
Node* Node::next(){
  return next_;
}

Node* Node::previous(){
  return previous_;
}

void Node::set_next(Node* newval){
  next_ = newval; 
}


void Node::set_previous(Node* newval){
  previous_ = newval; 
}

Operation* Node::oper() const {
  return 0 ;
}

Node* Node::second_next() const {
  return 0 ;
}

void Node::set_second_next(Node* newval){
}

int Node::value() const {
  return 0 ;
}
