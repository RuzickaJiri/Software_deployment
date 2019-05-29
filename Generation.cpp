#include <iostream>
#include "Generation.h"

Generation::Generation(size_t size, std::vector<std::string> xlabels){
  size_=size;
  nbr_trees_=0;
  Trees_= new Tree[size_];
  xlabels_=xlabels;
  fit_ = new float[size_];
  for(size_t i =0;i<size_;++i){
    fit_[i]=Trees_[i].fitness();
  }
     for (size_t i=0; i <size_;++i){
      Tree* t=new Tree(xlabels);
      Trees_[nbr_trees_]=*t;
      ++nbr_trees_;
    }

}


void Generation::PrintTree(){
  for(size_t a=0 ; a< nbr_trees_;a++){
      std::cout<<"Tree : "<<a+1<<std::endl;
      Trees_[a].PrintTree();
  }
}

Generation::~Generation(){
  delete[] Trees_ ;
}

void Generation::set_nbr_trees(size_t a){
 nbr_trees_=a;
}

void Generation::set_fitness(bool **x,int y[], int x_size){
  for (size_t i=0; i < nbr_trees_;i++){
    Trees_[i].set_fitness(x,y,x_size); // Set fitness_(should be inside constructor but here for now)
  }
}


size_t Generation::size(){
  return size_;
}

float* Generation::fit(){
  return fit_;
}

Tree Generation::GetBestIndividual(bool **x,int y[], int x_size) const{
    float fit = Trees_[0].CalcFitness(x, y, x_size);
    Tree best_tree = Trees_[0]; 
    for(size_t i=0; i<size_; ++i){
      if(Trees_[i].CalcFitness(x, y, x_size)<=fit){
        fit = Trees_[i].CalcFitness(x, y, x_size);
        best_tree = Trees_[i];
      }
    }
    return best_tree;
}
      
    


std::string Generation::GetBestFormula(bool** x,  int y[], int x_size) const{
    Tree best = GetBestIndividual( x, y, x_size);
    return best.Formula(best.head());
}




void Generation::AppendTree(Tree t){
	if(nbr_trees_<size_) {
		Trees_[nbr_trees_]=t;	
		nbr_trees_++;
	}
}

Generation* Generation::Evolve(int n,bool**x,int y[], int x_size, int record, std::string* bestIndividual_ ){
 /*bestIndividual_ must be in stack and of size n*/

	Generation* g = new Generation(size_,xlabels_);
	if (!record){
		bestIndividual_[0]="Record is false";	
	}

	Tree best = GetBestIndividual(x,y,x_size);
	for(int i = 0; i<n; ++i){
          g->set_nbr_trees(0);
	  for (size_t j=0; j < nbr_trees_;++j){
	    g->AppendTree(best.Mutation(x,y, x_size));
            g->Trees_[j].set_fitness(x,y, x_size);
            g->fit_[j]=Trees_[j].fitness();
	  }

	  if (record){	  
	    //if (g->GetBestIndividual(x,y, x_size).fitness() < best.fitness() || i==0) {
	       bestIndividual_[i]=g->GetBestFormula(x,y, x_size) + " with fitness " + std::to_string(g->GetBestIndividual(x,y, x_size).fitness());
	    //} else {
	      //bestIndividual_[i] = bestIndividual_[i-1] ;
	    //}
    }
    //if (g->GetBestIndividual(x,y, x_size).fitness() < best.fitness()) {
      best = g->GetBestIndividual(x,y,x_size);
    //}
	}

  return g;

}
