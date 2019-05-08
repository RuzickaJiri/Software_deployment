
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
    Tree(const Tree& tr);
    //Destructor
    ~Tree();
    //Methods

    Tree  Mutation(int);
    void Delete(Node* new_node);
    void replace(Node* new_node,int position);
    void append(Node* new_node, int position);
    void PrintTree(Node* x);
    
    float fitness();
	Node* head();
    std::vector<Node*> Nodes();
    void PrintTree(Node* x) ;
    
    
  protected : 
    
    std::vector<Node*> Nodes_;
    float fitness_;
    Node* head_;
};





#endif//TREE_
