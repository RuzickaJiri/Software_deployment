#include <iostream>
#include "Generation.h"
Generation::Generation(size_t nbr_trees){
  nbr_trees_=nbr_trees;
  Trees_= new Tree[nbr_trees_];
}

Generation::~Generation(){
  delete[] Trees_ ;
}

Tree Generation::GetBestIndividual() const{
    return Trees_[0];
}
Tree Generation::GetBestFormula() const{
    return Trees_[0];
}
Generation Generation::Evolve(int n,int x,int y,int record){
  /*if(!record){
    for(int i = 0, i<n, ++i){
      for(const auto& obj : Trees_){
        obj = obj.Mutation;
      }
    }
  }
  else{
    for(int i = 0, i<n, ++i){
      Generation* g = new Generation(this.nbr_trees);
      for(const auto& obj : Trees_){
        obj = obj.Mutation;
      }
    }*/
    
  return* this;
}
