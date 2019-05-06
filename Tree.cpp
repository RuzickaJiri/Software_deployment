#include"Tree.h"
#include"Node.h"
#include"Leaf.h"
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>

Tree::Tree(){
   fitness_ = 0;
   Leaf* head = new Leaf();
   Nodes_.push_back(head);
   
}

Tree Tree::Mutation() {
  int r = std::rand() %2;
  switch(r) {
    case 0 :
      Operator* new_node = new Operator() ;
      break;
    case 1 :
      Leaf* new_node = new Leaf() ;
      break;
  }
  int position = std::rand()%Nodes_.size() ;
  switch(r) {
    case 0 :
      this->replace(new_node, position) ;
      break;
    case 1 :
      this->append(new_node, position)
      break;
  }
  return this ;

void Tree::append(Node* new_node){
  Node* head = Nodes_.at(Nodes_.size());
  Nodes_.push_back(new_node);
  new_node->set_previous(head);
  head->set_next(new_node) ;
}


void Tree::replace(Node* new_node, int position){
      
      new_node->set_previous(to_replace_node->previous_) ;
      if (to_replace_node == to_replace_node->previous_->next_) {
        to_replace_node->previous_->set_next(new_node) ;
      } else {
        to_replace_node->previous_->set_second_next(new_node) ;
      //while ()
      delete to_replace_node ;    
}
