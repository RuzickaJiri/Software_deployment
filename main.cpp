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
  Generation* g = new Generation(4);

  //Tree Test
  std::cout<< "Test Tree" <<std::endl;
  Tree t1 ;
  Tree t2 ;

  std::cout<< "Test PrintTree1" <<std::endl;
  t1.PrintTree(t1.head()) ;  

  t1.append(&op1,0) ;
  std::cout<< t1.Nodes().size() <<std::endl;
  
  std::cout<< "Test PrintTree2" <<std::endl;
  t1.PrintTree(t1.head()) ;

  t1.append(&op2,1) ;
  std::cout<< t1.Nodes().size() <<std::endl;

  std::cout<< "Test PrintTree3" <<std::endl;
  t1.PrintTree(t1.head()) ;
 
  t1.replace(&l2,2) ;
  std::cout<< t1.Nodes().size() <<std::endl;

  std::cout<< "Test PrintTree4" <<std::endl;
  t1.PrintTree(t1.head()) ;

  t1.append(&op3,2) ;
  std::cout<< t1.Nodes().size() <<std::endl;

  std::cout<< "Test PrintTree5" <<std::endl;
  t1.PrintTree(t1.head()) ;
  
  t2.Mutation() ;
  std::cout<< "Test Mutation" <<std::endl;
  std::cout<< "Test PrintTree" <<std::endl;
  t2.PrintTree(t2.head()) ;
  t2.Mutation() ;
  std::cout<< "Test Mutation" <<std::endl;
  std::cout<< "Test PrintTree" <<std::endl;
  t2.PrintTree(t2.head()) ;
  t2.Mutation() ;
  std::cout<< "Test Mutation" <<std::endl;
  std::cout<< "Test PrintTree" <<std::endl;
  t2.PrintTree(t2.head()) ;
  t2.Mutation() ;



























  delete g ;
  return 0 ;
}
