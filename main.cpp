#include <iostream>
#include "Node.h"
#include "Operation.h"
#include "Operator.h"
#include "Leaf.h"
#include"Tree.h"
#include"Generation.h"
int main() {

  std::cout<<"Hello, World"<<std::endl;

  Operation o ;
  Operator op ;
  Leaf l ;
  //Generation* g = new Generation(4);

  Tree t ;
  t.append(&op,0) ;
  t.head()->previous();
  t.head();

  //t.Mutation() ;



  return 0 ;
}
