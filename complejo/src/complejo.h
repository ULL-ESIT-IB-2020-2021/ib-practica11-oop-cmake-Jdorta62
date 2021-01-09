#ifndef COMPLEJO_H
#define COMPLEJO_H

class Complejo {
 private:
    int real_part_{};
    int imaginary_part_{};

 public:
    
    Complejo(int, int);

    void Print();
    friend Complejo Add(Complejo &complex1, Complejo &complex2);
    friend Complejo Sub(Complejo &complex1, Complejo &complex2);
};

#endif