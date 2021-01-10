#include <iostream>
#include <fstream>
#include <string>
#include "racional.h"

Racional::Racional(int numerator, int denominator) {
  numerator_ = numerator;
  denominator_ = denominator;
}

void Racional::Print() {
  std::cout << numerator_ << "/" << denominator_ << std::endl;
}

void Racional::WriteOperations(const std::string &filename,  const Racional &racional2) {
  
  std::ofstream file;
  file.open(filename, std::ios::out | std::ios::app);
  Racional racional1{numerator_ , denominator_};
  Racional result = racional1.Add(racional2);
  file << numerator_ << "/" << denominator_  << " + " << racional2.numerator_ << "/" << racional2.denominator_ << " = " << result.numerator_ << "/" << result.denominator_ << std::endl;
  
  result = racional1.Sub(racional2);
  file << numerator_ << "/" << denominator_  << " - " << racional2.numerator_ << "/" << racional2.denominator_ << " = " << result.numerator_ << "/" << result.denominator_ << std::endl;
  
  result = racional1.Multiplication(racional2);
  file << numerator_ << "/" << denominator_  << " * " << racional2.numerator_ << "/" << racional2.denominator_ << " = " << result.numerator_ << "/" << result.denominator_ << std::endl;

  result = racional1.Division(racional2);
  file << numerator_ << "/" << denominator_  << " / " << racional2.numerator_ << "/" << racional2.denominator_ << " = " << result.numerator_ << "/" << result.denominator_ << std::endl << std::endl;
  file.close();
}

Racional Racional::Add(const Racional &racional2) {
  int denominator{denominator_ * racional2.denominator_};
  int numerator{(numerator_*(denominator/denominator_)) + (racional2.numerator_*(denominator/racional2.denominator_))};
  Racional result = Racional(numerator, denominator);
  return result;
}

Racional Racional::Sub(const Racional &racional2) {
  int denominator{denominator_ * racional2.denominator_};
  int numerator{(numerator_*(denominator/denominator_)) - (racional2.numerator_*(denominator/racional2.denominator_))};
  Racional result = Racional(numerator, denominator);
  return result;
}

Racional Racional::Multiplication(const Racional &racional2) {
  int numerator{numerator_ * racional2.numerator_};
  int denominator{denominator_ * racional2.denominator_};
  Racional result = Racional(numerator, denominator);
  return result;
}

Racional Racional::Division(const Racional &racional2) {
  int numerator{numerator_ * racional2.denominator_};
  int denominator{denominator_ * racional2.numerator_};
  Racional result = Racional(numerator, denominator);
  return result;
}