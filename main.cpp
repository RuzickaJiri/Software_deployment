#include <iostream>
#include "Node.h"
#include "Operation.h"
#include "Operator.h"
#include "Leaf.h"
#include"Tree.h"
#include"Generation.h"
int main() {

  std::cout<<"Hello, World"<<std::endl;
  
 std::vector<std::string> xlabels={"x1","x2","x5","x13","x6","x13","x12","x14"};
  Generation g(30, true, xlabels);
 
  std::cout<< "Print generation :" <<std::endl; 
  g.PrintTree();
  


bool x[]={true,true};
std::string* bestIndividual_=new std::string[100];
Generation g2=g.Evolve(10,x,0,true,bestIndividual_);
Generation g3=g2.Evolve(50,x,0,true,bestIndividual_);

  std::cout<< "Print generation2 :" <<std::endl;
 
  g2.PrintTree();
  for (size_t i=0; i<100;i++){
    std::cout<<i<<" "<<bestIndividual_[i]<<std::endl;
  }




















  
  return 0 ;
}

