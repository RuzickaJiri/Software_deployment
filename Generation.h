#include "Tree.h"
#include <iostream>
#ifndef GEN_
#define GEN_

class Generation{
  public : 
    Generation(size_t nbr_trees_);

    Tree GetBestIndividual() const;
    Tree GetBestFormula() const;
    Generation Evolve(int n,int x,int y,int record);
  protected : 
    Tree * Trees_;
    size_t nbr_trees_;
};
#endif
