#include"Tree.h"
#include"Node.h"
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

Tree::Tree(const Tree& tr){
  fitness_ = tr.fitness_ ;
  head_ = tr.head_ ;
  std::vector<Node*> Nodes_ ;
}

Tree::~Tree(){
  //delete head_;
  for(const auto& obj : Nodes_){
    delete obj;
  }
}

Leaf* Tree::head(){
  return head_;
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
  delete op ;
  delete leaf ;
  return *this ;
}

void Tree::append(Node* new_node, int position){
  
  Node* node_to_replace = Nodes_.at(position) ;
  if (node_to_replace->previous() != nullptr) {
    new_node->set_previous(node_to_replace->previous()) ;
    if (node_to_replace == node_to_replace->previous()->next()) {
      node_to_replace->previous()->set_next(new_node) ;
    } else {
      node_to_replace->previous()->set_second_next(new_node) ;
    }
  }
  
  new_node->set_next(node_to_replace) ;
  node_to_replace->set_previous(new_node);
  if (new_node->oper()->binary() == true) {
    Leaf* new_second_leaf = new Leaf() ;
    new_node->set_second_next(new_second_leaf) ;
    delete new_second_leaf ;
  }
  
  Nodes_.push_back(new_node) ;
  
  /*
  Node* head = Nodes_.at(position);
  Nodes_.at(position)=new_node;
  head->previous()->set_next(new_node);
  new_node->set_next(head_);
  new_node->set_previous(head->previous());
  
  head->set_previous(new_node) ;
   */
}


void Tree::replace(Node* new_node, int position) {
  
  Node* node_to_replace = Nodes_.at(position) ;
  if (node_to_replace->previous() != nullptr) {
    new_node->set_previous(node_to_replace->previous()) ;
    if (node_to_replace == node_to_replace->previous()->next()) {
      node_to_replace->previous()->set_next(new_node) ;
    } else {
      node_to_replace->previous()->set_second_next(new_node) ;
    }
  }
  
  if (new_node->WhatAmI() == "Operator") {
    if (node_to_replace->WhatAmI() == "Operator") {
      new_node->set_next(node_to_replace->next()) ;
      if (new_node->oper()->binary() == true) {
        if (node_to_replace->oper()->binary() == true) {
          new_node->set_second_next(node_to_replace->second_next()) ;
        } else {
          Leaf* new_second_leaf = new Leaf() ;
          new_node->set_second_next(new_second_leaf) ;
        }
      }
    }
  }  
  Nodes_.push_back(new_node) ;
}
