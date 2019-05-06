#include"Tree.h"
#include"Node.h"
#include"Leaf.h"
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>

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
  int position = std::rand()%Nodes_.size() ;
  Node* random_node = Nodes_.at(position) ;
    int r = std::rand() %3;
  switch(r) {
    case 0 :
      this->replace(random_node) ;
      break;
    case 1 :
      this->append(random_node,position);
      break;
    case 2 :
      this->Delete(random_node) ;
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

void Tree::replace(Node* new_node){
}

void Tree::Delete(Node* new_node){
}
