
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
    Tree(std::vector<std::string> xlabels_);
    Tree(const Tree& tr);
    Tree();
    //Destructor
    ~Tree();
    //Methods

    Tree  Mutation(bool x[][10], int y[], int x_size);
    void Delete(Node* new_node);
    void replace(Node* new_node,int position);
    void append(Node* new_node, int position);

    

    void PrintTree();
    void CopyTree(Node* x, Node* new_x);

    int FindSize(Node* x) const;
    Node* SearchInTree(Node* x, int position) const;
    float fitness();
    Node* head();
    //std::vector<Node*> Nodes();

    std::string Formula(Node* x);
    int CalcFormula(Node* n, bool x[]);
    float CalcFitness(bool x[][10], int y[], int x_size);
  
    void set_fitness(bool x[][10], int y[], int x_size);
 
    
  protected : 
    
    //std::vector<Node*> Nodes_;
    float fitness_;
    Node* head_;
    int size_;
    std::vector<std::string> xlabels_;
};





#endif//TREE_

