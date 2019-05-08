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
  std::cout<< t1.head()->previous() <<std::endl;
  //std::cout<< t1.head()->value() <<std::endl;
  std::cout<< "Test PrintTree" <<std::endl;
  t1.PrintTree(&l1) ;  

  t1.append(&op1,0) ;
  std::cout<< t1.Nodes().size() <<std::endl;
  //std::cout<< t1.head()->value() <<std::endl;
  std::cout<< t1.head()->previous() <<std::endl;
  std::cout<< t1.head()->previous()->oper()->operation() <<std::endl;
  
  std::cout<< "Test PrintTree" <<std::endl;
  t1.PrintTree(&op1) ;

  t1.append(&op2,1) ;
  std::cout<< t1.Nodes().size() <<std::endl;

  std::cout<< "Test PrintTree" <<std::endl;
  t1.PrintTree(&op2) ;
 
  t1.replace(&l2,2) ;
  std::cout<< t1.Nodes().size() <<std::endl;
  std::cout<< t1.head()->previous()->oper() <<std::endl;

  std::cout<< "Test PrintTree" <<std::endl;
  t1.PrintTree(&op2) ;

  t1.append(&op3,2) ;
  std::cout<< t1.Nodes().size() <<std::endl;
  std::cout<< t1.head()->previous()->oper() <<std::endl;

  std::cout<< "Test PrintTree" <<std::endl;
  t1.PrintTree(&op3) ;
  
  t2.Mutation() ;
  std::cout<< "Test Mutation" <<std::endl;
  std::cout<< "Test PrintTree" <<std::endl;
  t2.PrintTree(t2.Nodes()[1]) ;
  t2.Mutation() ;
  std::cout<< "Test Mutation" <<std::endl;
  std::cout<< "Test PrintTree" <<std::endl;
  t2.PrintTree(t2.Nodes()[2]) ;
  t2.Mutation() ;
  std::cout<< "Test Mutation" <<std::endl;
  std::cout<< "Test PrintTree" <<std::endl;
  t2.PrintTree(t2.Nodes()[2]) ;
  t2.Mutation() ;


  Generation* g1=new Generation();
  std::cout<< "________________________________________________" <<std::endl;
  (*g1).PrintTree(0);

























  delete g ;
  return 0 ;
}
