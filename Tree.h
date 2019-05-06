#ifndef TREE_
#define TREE_
#include<iostream>
#include<string>
#include"Node.h"
#include<vector>
class Tree{
  public : 

    //Constructors
    Tree();
    //Destructor
    ~Tree()=default;
    //Methods

    Tree Mutation();

    void append(Node* new_node);
    
    float fitness();
    float Nodes();
    
    
  protected : 
    
    std::vector<Node*> Nodes_;
    float fitness_;
  
};





#endif//TREE_
