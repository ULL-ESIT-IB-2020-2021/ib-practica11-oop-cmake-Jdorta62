#ifndef RACIONAL_H
#define RACIONAL_H

class Racional {
 private:
  int numerator_;
  int denominator_;

 public:
  Racional(int numerator, int denominator);

  void Print();
  void WriteOperations(const std::string &filename, const Racional &racional2);
  Racional Add(const Racional &racional2);
  Racional Sub(const Racional &racional2);
  Racional Multiplication(const Racional &racional2);
  Racional Division(const Racional &racional2);
};

#endif