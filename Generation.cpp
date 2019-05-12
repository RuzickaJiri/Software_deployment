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

Tree Generation::GetBestIndividual() const{
    return Trees_[0];
}
Tree Generation::GetBestFormula() const{
    return Trees_[0];
}

void Generation::AppendTree(Tree t){
	if(nbr_trees_<size_) {
		Trees_[nbr_trees_]=t;	
		nbr_trees_++;
	}
}

Generation Generation::Evolve(int n,int x,int y,int record){
	Generation* g = new Generation(n);
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
