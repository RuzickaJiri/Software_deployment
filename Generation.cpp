#include <iostream>
#include "Generation.h"
Generation::Generation(size_t nbr_trees){
  nbr_trees_=nbr_trees;
  Trees_= new Tree[nbr_trees_];
}

Tree Generation::GetBestIndividual() const{
    return Trees_[0];
}
Tree Generation::GetBestFormula() const{
    return Trees_[0];
}
Generation Generation::Evolve(int n,int x,int y,int record){
  return* this;
}
