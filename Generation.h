#include "Tree.h"
#include "Operator.h"
#include <iostream>
#ifndef GEN_
#define GEN_

class Generation{
  public : 
    Generation(size_t nbr_trees_);
    Generation();
    ~Generation();

    Tree GetBestIndividual() const;
    Tree GetBestFormula() const;
    Generation Evolve(int n,int x,int y,int record);
    void PrintTree(int a);
  protected : 
    Tree * Trees_;
    size_t nbr_trees_;
    size_t size_;
};
#endif
