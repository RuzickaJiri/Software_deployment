#include <iostream>
#include "Generation.h"

Generation::Generation(size_t nbr_trees){
  nbr_trees_=nbr_trees;
  Trees_= new Tree[nbr_trees_];
}

Generation::Generation(){
  nbr_trees_=1;
  Trees_= new Tree[nbr_trees_];
  Operator op1 ;
 Operator op2 ;
 Operator op3 ;
  Tree t1 ;
  t1.append(&op1,0) ;
 t1.append(&op2,1) ;
 t1.append(&op3,2) ;


  t1.Mutation() ;
  
  t1.Mutation() ;
 

  t1.Mutation() ;
  
  t1.Mutation() ;


  Trees_[0]=t1;

}

void Generation::PrintTree(int a){
  if (a<nbr_trees_){
    Trees_[a].PrintTree(Trees_[a].Nodes()[0]);
  }
}

Generation::~Generation(){
  delete[] Trees_ ;
}

Tree Generation::GetBestIndividual(Node* n, bool x[], std::vector<std::string> xlabels, int y) const{
    float fit = Trees_[0].CalcFitness( n, x,xlabels,  y);
    Tree best_tree = Trees_[0]; 
    /*for(const Tree obj : Trees_){
      if(obj.CalcFitness( n,  x,  xlabels,  y)<=fit){
        fit = obj.CalcFitness( n, x,  xlabels,  y);
        best_tree = obj;
      }
    }*/
    return best_tree;
}
      
    


Tree Generation::GetBestFormula() const{
    return Trees_[0];
}
Generation* Generation::Evolve(int n,int x,int y,int record){
  /*if(!record){
    for(int i = 0, i<n, ++i){
      for(const auto& obj : Trees_){
        obj = obj.Mutation;
      }
      best_ind = 
    }
  }
  else{
    for(int i = 0, i<n, ++i){
      Generation* g = new Generation(this.nbr_trees);
      for(const auto& obj : Trees_){
        obj = obj.Mutation;
      }
    }*/
    
  return this;
}
