#include <iostream>
#include "Generation.h"

Generation::Generation(size_t size, bool add){
  size_=size;
  nbr_trees_=0;
  Trees_= new Tree[size_];
  bestformula_= new std::string[1];
  bestformula_[0] = "You have not asked to save history";

  if (add){
    for (size_t i=0; i <size_;++i){
      Tree* t=new Tree();
      Trees_[nbr_trees_]=*t;
      ++nbr_trees_;
    }
  }
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
  for(size_t a=0 ; a< nbr_trees_;a++){
      std::cout<<"Tree : "<<a+1<<std::endl;
      Trees_[a].PrintTree(Trees_[a].head());
  }
}

Generation::~Generation(){
  delete[] Trees_ ;
}

void Generation::set_nbr_trees(size_t a){
 nbr_trees_=a;
}




Tree Generation::GetBestIndividual( bool x[], std::vector<std::string> xlabels, int y) const{
    float fit = Trees_[0].CalcFitness( Trees_[0].head(), x,xlabels,  y);
    Tree best_tree = Trees_[0]; 
    for(unsigned int i(0); i<size_; ++i){
      if(Trees_[i].CalcFitness( Trees_[i].head(),  x,  xlabels,  y)<=fit){
        fit = Trees_[i].CalcFitness( Trees_[i].head(), x,  xlabels,  y);
        best_tree = Trees_[i];
      }
    }
    return best_tree;
}
      
    


std::string Generation::GetBestFormula() const{
    return "best ;)";//bestformula_[0];
}




void Generation::AppendTree(Tree t){
	if(nbr_trees_<size_) {
		Trees_[nbr_trees_]=t;	
		nbr_trees_++;
	}
}

Generation Generation::Evolve(int n,int x,int y,int record){
	int nbr_formulas_=0;
 	Generation* g = new Generation(size_, false);
	std::string bestOfEachEvolution;
	if(record){
          //delete (g->bestformula_);
	  g->bestformula_=new std::string[n];
	}
	for(int i = 0; i<n; ++i){
          g->set_nbr_trees(0);
	  for (int j=0; j < nbr_trees_;++j){
	    g->AppendTree(Trees_[j].Mutation());
	  }
	  if (record){
	    g->bestformula_[nbr_formulas_]=g->GetBestFormula();
            ++nbr_formulas_;
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
    

  return *this;

  return* g;

}
