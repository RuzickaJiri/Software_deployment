#include"Tree.h"
#include"Node.h"
#include"Leaf.h"
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
#include"Operator.h"
#include <cmath>

Tree::Tree(std::vector<std::string> xlabels){
   fitness_ = 0;
   size_ = 1 ;
   xlabels_=xlabels;
   head_ = new Leaf(xlabels_);
   
}

Tree::Tree(){
   fitness_ = 0;
   size_ = 0 ;
   //xlabels_=0;
   head_ = 0;
   
}
Tree::Tree(const Tree& tr){
  fitness_ = tr.fitness_ ;
  size_ = tr.size_ ;
   xlabels_=tr.xlabels_;
  if (tr.head_->WhatAmI() == "Leaf"){
    head_ = new Leaf(tr.head_->value()) ;
  } else {
    head_ = new Operator(tr.head_->oper()) ;
  }
  this->CopyTree(tr.head_, head_);
}

Tree::~Tree(){
  //delete head_ ; 

}

Node* Tree::head(){
  return head_;
}


Tree Tree::Mutation(float x[][10], float y[], int x_size) {

  Tree newTree(*this);
  int position = std::rand()%size_ ;
  int r = std::rand() %4;
  if (r >= 2) {
	  Operator* new_node = new Operator() ;
	  newTree.append(new_node, position);
	} else if (r==1){
	  Operator* new_node = new Operator() ;
    newTree.replace(new_node, position) ;
	} else {
    Leaf* new_node = new Leaf(xlabels_) ;
    newTree.replace(new_node, position) ;
  }
  
  newTree.set_fitness(x, y,x_size);
  
  return newTree ;
}

void Tree::append(Node* new_node, int position){
  
  Node* node_to_replace = SearchInTree(head_, position) ;
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
      Leaf* new_second_leaf = new Leaf(xlabels_) ;
      new_node->set_second_next(new_second_leaf) ;
      new_second_leaf->set_previous(new_node);
      //delete new_second_leaf ;
      ++size_ ;
    }
  }
  if (head_ == node_to_replace) {
    head_ = new_node ;
  }
  
  ++size_ ;
  

}


void Tree::replace(Node* new_node, int position) {
  
  Node* node_to_replace = SearchInTree(head_, position) ;
  //size_ -= FindSize(node_to_replace) ;
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
      node_to_replace->next()->set_previous(new_node);
      if (new_node->oper()->binary() == true) {
        if (node_to_replace->oper()->binary() == true) {
          new_node->set_second_next(node_to_replace->second_next()) ;
          node_to_replace->second_next()->set_previous(new_node);
        } else {
          Leaf* new_second_leaf = new Leaf(xlabels_) ;
          new_node->set_second_next(new_second_leaf) ;
          new_second_leaf->set_previous(new_node);
          //++size_ ;
        }
      }
    } else {
      Leaf* new_leaf = new Leaf(xlabels_) ;
      new_node->set_next(new_leaf) ;
      new_leaf->set_previous(new_node);
      ++size_;
      if (new_node->oper()->binary() == true) {
        Leaf* new_second_leaf = new Leaf(xlabels_) ;
        new_node->set_second_next(new_second_leaf) ;
        new_second_leaf->set_previous(new_node);
        //++size_ ;
      }
    }
  }  
  if (head_ == node_to_replace) {
    head_ = new_node ;
  }
  //++size_ ;
  size_ = FindSize(head_) ;
}

void Tree::PrintTree(){
  
  std::cout<< Formula(head_) <<std::endl;
  std::cout<< "fitness :" << fitness_ <<std::endl;
}

void Tree::CopyTree(Node* x, Node* new_x){
  
  if (x == nullptr){ return;}
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


std::string Tree::Formula(Node* x){
  
  if (x != nullptr){
    if (x->WhatAmI() == "Leaf"){
      return x->value();
    }
    else {
      if (x->oper()->binary()) {
        return "("+ Formula(x->next()) +" "+ x->oper()->operation()
        +" "+ Formula(x->second_next()) + ")";
      }
      else {
        return "("+ x->oper()->operation()+" "+ Formula(x->next())+")";
      }
    }
  } return "";
}

int Tree::FindSize(Node* x) const{
  
  if (x == nullptr) {
    return 0 ;
  } else {
    if (x->WhatAmI() == "Operator" && x->oper()->binary()){
      return FindSize(x->next()) + 1 + FindSize(x->second_next());
    } else {
      return FindSize(x->next()) + 1 ;
      
    }
  }
}

Node* Tree::SearchInTree(Node* x, int position) const{
  
  if (position == 0) {
    return x ;
  }
  if (x->WhatAmI() == "Operator"){
    if (x->oper()->binary()) {
      if (position > FindSize(x->next())){
        return SearchInTree(x->second_next(), position - FindSize(x->next()) -1);
      }
      else {
        return SearchInTree(x->next(), position - 1);
      }
      
    } else {
      return SearchInTree(x->next(), position - 1);
    }
  }
  return nullptr;
}



float Tree::CalcFormula(Node* n, float x[]){
  
  int size = xlabels_.size();
  if (n != nullptr){
    if (n->WhatAmI() == "Leaf"){
      for (int i=0; i<size; i++) {
        if (n->value() == xlabels_[i]){
          return x[i];
        } else {
          return 1;
        }
      }

    } else {
      if(n->oper()->operation() == "+") {
        return CalcFormula(n->next(),x) + CalcFormula(n->second_next(),x);
      }
      if(n->oper()->operation() == "-") {
        return CalcFormula(n->next(),x) - CalcFormula(n->second_next(),x);
      }
      if(n->oper()->operation() == "*") {
        return CalcFormula(n->next(),x) * CalcFormula(n->second_next(),x);
      }
      if(n->oper()->operation() == "/") {
        return CalcFormula(n->next(),x) / CalcFormula(n->second_next(),x);
      }
    }
  }
  return 0;
}

float Tree::CalcFitness(float x[][10], float y[], int x_size){
  float fit = 0;
  for (int i=0; i< x_size; i++) {
    fit += pow(CalcFormula(head_ ,x[i]) - y[i],2);
  }
  return fit;
}

float Tree::fitness(){
  return fitness_;
}
  
void Tree::set_fitness(float x[][10], float y[], int x_size){
  fitness_ = CalcFitness(x,y,x_size);
}
