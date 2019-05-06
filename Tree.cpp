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
  position = std::rand()%Nodes_.size() ;
  random_node = Nodes_.at(position) ;
    int r = std::rand() %3;
  switch(r) {
    case 0 :
      this->replace(random_node) ;
      break;
    case 1 :
      this->append(random_node)
      break;
    case 2 :
      this->Delete(random_node) ;
      break;
  }
  return this ;

void Tree::append(Node* new_node){
  Node* head = Nodes_.at(Nodes_.size());
  Nodes_.push_back(new_node);
  new_node->set_previous(head);
  head->set_next(new_node) ;
}
