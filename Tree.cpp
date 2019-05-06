#include"Tree.h"
#include"Node.h"
#include"Operator.h"
#include"Leaf.h"
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
#include"Operator.h"

Tree::Tree(){
   fitness_ = 0;
   head_ = new Leaf();
   Nodes_.push_back(head_);
   
}

Tree::~Tree(){
  delete head_;
  for(const auto& obj : Nodes_){
    delete obj;
  }
}

Tree Tree::Mutation() {
  Operator* op = new Operator() ;
  Leaf* leaf = new Leaf() ;
  Node* new_node;
  int position = std::rand()%Nodes_.size() ;
  Node* random_node = Nodes_.at(position) ;
  int r = std::rand() %2;
  switch(r) {
    case 0 :
    {
        new_node = op ;
        
        break;
        
    }
    case 1 :
    {
      new_node=leaf;
      
      break;
    }
  }

  r = std::rand() %2;
  switch(r) {
    case 0 :
      this->replace(new_node, position) ;
      break;
    case 1 :
      this->append(new_node, position);
      break;
  }
  return *this ;
}

void Tree::append(Node* new_node, int position){
  Node* head = Nodes_.at(position);
  Nodes_.at(position)=new_node;
  head->previous()->set_next(new_node);
  new_node->set_next(head_);
  new_node->set_previous(head->previous());
  
  head->set_previous(new_node) ;
}




void Tree::replace(Node* new_node, int position) {
  
  node_to_replace = Nodes_.at(position) ;
  new_node->set_previous(node_to_replace->previous_) ;
  if (to_replace_node == node_to_replace->previous_->next_) {
    node_to_replace->previous_->set_next(new_node) ;
  } else {
    node_to_replace->previous_->set_second_next(new_node) ;
  }  
  
  if (new_node->WhatAmI() == "Operator") {
    if (to_replace_node->WhatAmI() == "Operator") {
      new_node->set_next(to_replace_node->next_) ;
      if (new_node->binary() == true) {
        if (to_replace_node->binary() == true) {
          new_node->set_second_next(to_replace_node->second_next_) ;
        } else {
          Leaf* new_second_leaf = new Leaf() ;
          new_node->set_second_next(new_second_leaf) ;
        }
      }
    }
  }  
}
