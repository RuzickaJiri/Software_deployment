#include "Tree.h"
#include "Operator.h"
#include <iostream>
#ifndef GEN_
#define GEN_

class Generation{
  public : 
    Generation(size_t nbr_trees_,bool,std::vector<std::string> xlabels);

    Generation(std::vector<std::string> xlabels,float x[][10], float y[], int x_size);

    ~Generation();

    Tree GetBestIndividual( float x[][10], float y[], int x_size) const;
    std::string GetBestFormula(float x[][10], float y[], int x_size) const;
    void set_fitness(float x[][10],float y[], int x_size);

    
    

    //Generation Evolve(int n,int x,int y,int record) const;//std::vector<std::string> xlabels
    Generation Evolve(int n, float x[][10],float y[],int x_size, int record,std::string* bestIndividual_ );
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
