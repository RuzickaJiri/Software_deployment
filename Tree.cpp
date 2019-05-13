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
  Nodes_ = tr.Nodes_;
  this->CopyTree(tr.head_, head_);
}

Tree::~Tree(){
  for(const auto& obj : Nodes_){
    //delete obj;
  } 
}

Node* Tree::head(){
  return head_;
}

std::vector<Node*> Tree::Nodes(){
  return Nodes_;
}

Tree Tree::Mutation() {
  Tree* newTree = new Tree(*this);
  int position = std::rand()%Nodes_.size() ;
  int r = std::rand() %4;
  if (r > 2) {
	Operator* new_node = new Operator() ;
	newTree->append(new_node, position);
	} else if (r==1){
	  Operator* new_node = new Operator() ;
      newTree->replace(new_node, position) ;
	} else {
      Leaf* new_node = new Leaf() ;
      newTree->replace(new_node, position) ;
  }
  

  
  return *newTree ;
}

void Tree::append(Node* new_node, int position){
  
  Node* node_to_replace = Nodes_.at(position) ;// get node to append
  if (node_to_replace->previous() != nullptr) {
    new_node->set_previous(node_to_replace->previous()) ;
    if (node_to_replace == node_to_replace->previous()->next()) {//if first next
      node_to_replace->previous()->set_next(new_node) ;
    } else {//second next
      node_to_replace->previous()->set_second_next(new_node) ;
    }
  }
  
  new_node->set_next(node_to_replace) ;
  node_to_replace->set_previous(new_node);
  if (new_node->WhatAmI() == "Operator") {
	if (new_node->oper()->binary()) {
      Leaf* new_second_leaf = new Leaf() ;
      new_node->set_second_next(new_second_leaf) ;
      //delete new_second_leaf ;
      Nodes_.push_back(new_second_leaf) ;
    }
  }
  if (head_ == node_to_replace) {
    head_ = new_node ;
  }
  
  Nodes_.push_back(new_node) ;
  

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
          Nodes_.push_back(new_second_leaf) ;
        }
      }
    }
  }  
  Nodes_.erase(Nodes_.begin()+position) ;
  Nodes_.push_back(new_node) ;
  if (head_ == node_to_replace) {
    head_ = new_node ;
  }
}

void Tree::PrintTree(Node* x){
  
  if (x != nullptr){
    if (x->WhatAmI() == "Leaf"){
      std::cout<< x->print() <<std::endl;
    } else {
      std::cout<< x->print() <<std::endl;
      PrintTree(x->next());
      if (x->oper()->binary()) {
        PrintTree(x->second_next());
      }
    }
  }
}

void Tree::CopyTree(Node* x, Node* new_x){
  
  if (x != nullptr){
    if (x->WhatAmI() == "Operator"){
      if (x->next()->WhatAmI() == "Leaf"){
        Leaf* temp = new Leaf(x->next()->value());
        new_x->set_next(temp);
        temp->set_previous(new_x);
      } else {
        Operator* temp = new Operator(x->next()->oper());
        new_x->set_next(temp);
        temp->set_previous(new_x);
      }
      
      CopyTree(x->next(), new_x->next());
      if (x->oper()->binary()) {
        if (x->second_next()->WhatAmI() == "Leaf"){
          Leaf* temp = new Leaf(x->second_next()->value());
          new_x->set_second_next(temp);
          temp->set_previous(new_x);
        } else {
          Operator* temp = new Operator(x->second_next()->oper());
          new_x->set_second_next(temp);
          temp->set_previous(new_x);
        }
        
        CopyTree(x->second_next(), new_x->second_next());
      }
    }
  }
}

/*
std::vector<std::string> Tree::Formula(Node* x){
  
  std::vector<std::string> s;
  if (x != nullptr){
    if (x->WhatAmI() == "Leaf"){
      //s.push_back(std::to_string(x->value()));
      s.push_back("x->WhatAmI()");
    } else {
      Formula(x->next());
      s.push_back(x->oper()->operation());
      Formula(x->second_next());
    }
  }
  return s;
 }*/

int Tree::CalcFormula(Node* n, bool x[], std::vector<std::string> xlabels){
  
  int size = xlabels.size();
  if (n != nullptr){
    if (n->WhatAmI() == "Leaf"){
      for (int i=0; i<size; i++) {
        if (n->value() == xlabels[i]){
          return x[i];
        }
      }

    } else {
      if(n->oper()->operation() == "AND") {
        return CalcFormula(n->next(),x,xlabels) && CalcFormula(n->second_next(),x,xlabels);
      }
      if(n->oper()->operation() == "OR") {
        return CalcFormula(n->next(),x,xlabels) || CalcFormula(n->second_next(),x,xlabels);
      }
      if(n->oper()->operation() == "NOT") {
        return !CalcFormula(n->next(),x,xlabels);
      }
    }
  }
}

float Tree::CalcFitness(Node* n, bool x[], std::vector<std::string> xlabels, int y){
  return CalcFormula(n,x,xlabels) - y;
}


  
