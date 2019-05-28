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
  float x2[][10]={{1},{3},{10},{20},{30},{40},{50},{60},{70},{80}};
  float y2[]={1,4,9,18,20,15,9,4,30};
  
  Generation g4(3, true, xlabels2);
  g4.set_fitness(x2,y2,10);
 
  std::cout<< "Print generation :" <<std::endl; 
  g4.PrintTree();


  std::string* bestIndividual_2=new std::string[10000];
  Generation g5=g4.Evolve(1000,x2,y2,10,true,bestIndividual_2);

  std::cout<< "Print generation2 :" <<std::endl;
 
  g5.PrintTree();
  for (size_t i=0; i<1000;i++){
    std::cout<<i<<" "<<bestIndividual_2[i]<<std::endl;
  }


















  
  return 0 ;
}

