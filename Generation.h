#include "Tree.h"
#include "Operator.h"
#include <iostream>
#ifndef GEN_
#define GEN_

class Generation{
  public : 
    Generation(size_t nbr_trees_,bool,std::vector<std::string> xlabels);
    Generation(std::vector<std::string> xlabels);
    ~Generation();

    Tree GetBestIndividual( bool x[], int y) const;
    std::string GetBestFormula(bool x[], int y) const;

    
    

    //Generation Evolve(int n,int x,int y,int record) const;//std::vector<std::string> xlabels
    Generation Evolve(int n, bool x[],int y,int record,std::string* bestIndividual_ );
    void PrintTree();
    void AppendTree(Tree t);
    void set_nbr_trees(size_t a);



  protected : 
    Tree * Trees_;
    size_t nbr_trees_;
    size_t size_;
    std::vector<std::string> xlabels_;

};
#endif
