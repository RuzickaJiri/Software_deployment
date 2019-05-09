#ifndef TREE_
#define TREE_
#include<iostream>
#include<string>
#include"Node.h"
#include<vector>
#include"Leaf.h"
class Tree{
  public : 

    //Constructors
    Tree();
    //Destructor
    ~Tree();
    //Methods

    Tree  Mutation();
    void Delete(Node* new_node);
    void replace(Node* new_node,int position);
    void append(Node* new_node, int position);
    void go_through();
    
    float fitness();
    float Nodes();
    
    
  protected : 
    
    std::vector<Node*> Nodes_;
    float fitness_;
    Leaf* head_;
};





#endif//TREE_
