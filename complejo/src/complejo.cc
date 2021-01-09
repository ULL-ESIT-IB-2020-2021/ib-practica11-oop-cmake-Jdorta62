#include "complejo.h"
#include <iostream>

Complejo::Complejo(int real_part, int imaginary_part) {
  real_part_ = real_part;
  imaginary_part_ = imaginary_part;
}

void Complejo::Print() {

  std::cout << "(" << real_part_ << ") + (" << imaginary_part_ << ")i" << std::endl; 

}

Complejo Add(Complejo &complex1, Complejo &complex2) {

  int realpart{complex1.real_part_ + complex2.real_part_};
  int imaginarypart{complex1.imaginary_part_ + complex2.imaginary_part_};
  Complejo result{realpart, imaginarypart};
  return result;

}

Complejo Sub(Complejo &complex1, Complejo &complex2) {

  int realpart{complex1.real_part_ - complex2.real_part_};
  int imaginarypart{complex1.imaginary_part_ - complex2.imaginary_part_};
  Complejo result{realpart, imaginarypart};
  return result;

}