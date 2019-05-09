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

    Tree GetBestIndividual(Node* n, bool x[], std::vector<std::string> xlabels, int y) const;
    Tree GetBestFormula() const;
    Generation Evolve(int n,int x,int y,int record);
    void PrintTree(int a);
  protected : 
    Tree * Trees_;
    size_t nbr_trees_;
};
#endif
