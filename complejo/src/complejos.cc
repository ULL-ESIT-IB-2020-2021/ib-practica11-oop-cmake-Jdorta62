#include <iostream>
#include "complejo.cc"

int main () {

  Complejo complejo1{4,5};
  Complejo complejo2{7,-8};

  Complejo result = Add(complejo1, complejo2);
  result.Print();

  result = Sub(complejo1, complejo2);
  result.Print();
  

  return 0;
}