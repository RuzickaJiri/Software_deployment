#ifndef OPERATION_
#define OPERATION_

#include <iostream>

class Operation{
  protected:
    std::string operation_;
    bool binary_;
  public:
    //Constructors
    Operation();
    
    //Destructor
    ~Operation() = default;
    
    //Getters
    std::string operation() const;
    bool binary() const;
};

#endif //OPERATION_
