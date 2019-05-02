
#include "Node.h"
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
