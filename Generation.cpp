#include <iostream>
#include "Generation.h"

Generation::Generation(size_t size){
  size_=size;
  nbr_trees_=0;
  Trees_= new Tree[size_];
  }

Generation::Generation(){
 nbr_trees_=1;
 size_=1;
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

void Generation::PrintTree(){
  for(int a=0 ; a< nbr_trees_;a++){
      std::cout<<"Tree : "<<a+1<<std::endl;
      Trees_[a].PrintTree(Trees_[a].head());
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


void Generation::AppendTree(Tree t){
	if(nbr_trees_<size_) {
		Trees_[nbr_trees_]=t;	
		nbr_trees_++;
	}
}

Generation Generation::Evolve(int n,int x,int y,int record){
  int numberoftrees=n*size_;
	Generation* g = new Generation(numberoftrees);
	std::string bestOfEachEvolution;
	for(int i = 0; i<n; ++i){
	  for (int j=0; j < nbr_trees_;++j){
	    g->AppendTree(Trees_[j].Mutation());
	  }
	  if (record){
	    g->GetBestFormula();
	  }
		/*for(const auto& obj : Trees_){
      AppendTree(obj.mutation());
		
		} */
	}

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

  return* g;

}
