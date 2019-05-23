#include <iostream>
#include "Node.h"
#include "Operation.h"
#include "Operator.h"
#include "Leaf.h"
#include"Tree.h"
#include"Generation.h"
int main() {

  std::cout<<"Hello, World"<<std::endl;
  
  //Operation Test
  Operation o1 ;
  Operation o2 ;
  Operation o3 ;
  std::cout<< o1.operation() << o1.binary() <<std::endl;
  std::cout<< o2.operation() << o2.binary() <<std::endl;
  std::cout<< o3.operation() << o3.binary() <<std::endl;
  
  //Nodes Test
  Operator op1 ;
  Operator op2 ;
  Operator op3 ;
  Leaf l1 ;
  Leaf l2 ;
  std::cout<< op1.oper()->operation() << op1.oper()->binary() <<std::endl;
  std::cout<< op2.oper()->operation() << op2.oper()->binary() <<std::endl;
  std::cout<< l1.value() <<std::endl;
  std::cout<< l2.value() <<std::endl;


  //Generation Test
  //Generation* g = new Generation(4);

  //Tree Test
  std::cout<< "Test Tree" <<std::endl;
  Tree t1 ;
  Tree t2 ;

  std::cout<< "Test PrintTree1" <<std::endl;
  t1.PrintTree() ;

  t1.append(&op1,0) ;
  //std::cout<< t1.Nodes().size() <<std::endl;
  
  std::cout<< "Test PrintTree2" <<std::endl;
  t1.PrintTree() ;

  t1.append(&op2,1) ;
  //std::cout<< t1.Nodes().size() <<std::endl;

  std::cout<< "Test PrintTree3" <<std::endl;
  t1.PrintTree() ;
 /*
  t1.replace(&l2,2) ;
  std::cout<< t1.Nodes().size() <<std::endl;

  std::cout<< "Test PrintTree4" <<std::endl;
  t1.PrintTree(t1.head()) ;

  t1.append(&op3,2) ;
  std::cout<< t1.Nodes().size() <<std::endl;


  t1.PrintTree(&op2);
  
  std::cout<< "Test Fitness" <<std::endl;
  std::vector<std::string> xlabels;
  xlabels.push_back("x1");
  xlabels.push_back("x2");
  bool x[] = {1,0};
  
  int f = t1.CalcFormula(&op2, x, xlabels);
  std::cout<< f <<std::endl;
  std::cout<< t1.CalcFitness(&op2, x, xlabels,1) <<std::endl;;

  std::cout<< "Test PrintTree5" <<std::endl;
  t1.PrintTree(t1.head()) ;
  */
  t2.Mutation() ;
  std::cout<< "Test Mutation" <<std::endl;
  std::cout<< "Test PrintTree" <<std::endl;
  t2.PrintTree() ;
  t2.Mutation() ;
  std::cout<< "Test Mutation" <<std::endl;
  std::cout<< "Test PrintTree" <<std::endl;
  t2.PrintTree() ;
  t2.Mutation() ;
  std::cout<< "Test Mutation" <<std::endl;
  std::cout<< "Test PrintTree" <<std::endl;
  t2.PrintTree() ;
  t2.Mutation() ;
  
  Tree t3;
  for(int i = 0; i<8; ++i){
  std::cout<< "Test PrintTree" <<std::endl;
  t3 = t3.Mutation();
  t3.PrintTree();
  }


  std::cout<< "AppendTree" <<std::endl;
  t1.PrintTree();
  Generation g(30);
  g.AppendTree(t1);
  g.AppendTree(t2);
  g.AppendTree(t2);
  g.AppendTree(t2);
  g.AppendTree(t2);
  //Generation g2=g.Evolve(5,5,5,true);
  
  std::cout<< "Print generation :" <<std::endl; 
  g.PrintTree();
  

std::vector<std::string> xlabels={"x1","x2"};
bool x[]={true,true};
std::string* bestIndividual_=new std::string[100];
Generation g2=g.Evolve(10,x,0,true,xlabels,bestIndividual_);
Generation g3=g2.Evolve(50,x,0,true,xlabels,bestIndividual_);

  std::cout<< "Print generation2 :" <<std::endl;
 
  g2.PrintTree();
  for (size_t i=0; i<100;i++){
    std::cout<<i<<" "<<bestIndividual_[i]<<std::endl;
  }




















  
  return 0 ;
}

