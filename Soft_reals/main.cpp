#include <iostream>
#include "Node.h"
#include "Operation.h"
#include "Operator.h"
#include "Leaf.h"
#include"Tree.h"
#include"Generation.h"
int main() {

  std::cout<<"Hello, World"<<std::endl;
  

  //Test 1
  std::vector<std::string> xlabels={"x"};
  float x[][10]={{1},{2},{3}};
  float y[]={2,4,6};
  
  Generation* g = new Generation(5, true, xlabels);
  g->set_fitness(x,y,3);
 
  std::cout<< "Print generation :" <<std::endl; 
  g->PrintTree();

  std::string* bestIndividual_=new std::string[100];
  Generation g2=g->Evolve(20,x,y,3,true,bestIndividual_);
  g2.PrintTree();
  //Generation g3=g2.Evolve(10,x,y,3,true,bestIndividual_);


  std::cout<< "Print generation2 :" <<std::endl;
 
  g2.PrintTree();
  for (size_t i=0; i<20;i++){
    std::cout<<i<<" "<<bestIndividual_[i]<<std::endl;
  }

  //Test 2
  std::vector<std::string> xlabels2={"x"};
  float x2[][10]={{0.1},{1},{2},{3},{4},{5},{10}}; // f(x) = ln(x) + (x-1)^2
  float y2[]={-1.5,0,1.7,5.09,10.39,17.61,83.30};
  
  Generation g4(1000, true, xlabels2);
  g4.set_fitness(x2,y2,7);
 
  std::cout<< "Print generation :" <<std::endl; 
  g4.PrintTree();


  std::string* bestIndividual_2=new std::string[10000];
  Generation g5=g4.Evolve(20,x2,y2,7,true,bestIndividual_2);

  std::cout<< "Print generation2 :" <<std::endl;
 
  g5.PrintTree();
  for (size_t i=0; i<20;i++){
    std::cout<<i<<" "<<bestIndividual_2[i]<<std::endl;
  }


















  
  return 0 ;
}

