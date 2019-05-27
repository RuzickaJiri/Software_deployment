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
  std::vector<std::string> xlabels={"x1","x2","x3","x4","x5"};
  bool x[][10]={{1,1,0,0,0},{1,0,1,0,1},{0,1,1,0,0}};
  int y[]={1,1,0};
  
  Generation* g = new Generation(5, true, xlabels);
  g->set_fitness(x,y,3);
 
  std::cout<< "Print generation :" <<std::endl; 
  g->PrintTree();

  std::string* bestIndividual_=new std::string[100];
  Generation g2=g->Evolve(10,x,y,3,true,bestIndividual_);
  Generation g3=g2.Evolve(10,x,y,3,true,bestIndividual_);


  std::cout<< "Print generation2 :" <<std::endl;
 
  g2.PrintTree();
  for (size_t i=0; i<10;i++){
    std::cout<<i<<" "<<bestIndividual_[i]<<std::endl;
  }

  //Test 2
  std::vector<std::string> xlabels2={"x1","x2","x3"};
  bool x2[][10]={{1,1,0,0,0,1,0,0},{1,1,0,0,0,1,0,1},{0,1,1,1,0,1,1,0}};
  int y2[]={0,1,1,1,1,1,1,0};
  
  Generation g4(3, true, xlabels2);
  g4.set_fitness(x2,y2,8);
 
  std::cout<< "Print generation :" <<std::endl; 
  g4.PrintTree();


  std::string* bestIndividual_2=new std::string[100];
  Generation g5=g4.Evolve(10,x2,y2,8,true,bestIndividual_2);

  std::cout<< "Print generation2 :" <<std::endl;
 
  g5.PrintTree();
  for (size_t i=0; i<10;i++){
    std::cout<<i<<" "<<bestIndividual_2[i]<<std::endl;
  }


















  
  return 0 ;
}

