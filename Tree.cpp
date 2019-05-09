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



void Tree::Delete(Node* new_node){
}


void Tree::replace(Node* new_node, int position){
      
       
}

void go_through(){
  
