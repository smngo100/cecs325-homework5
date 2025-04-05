//
// Created by sophi on 4/5/2025.
//

#ifndef RATIONAL_H
#define RATIONAL_H
#include <ostream>

class Rational {

private:
  int m_numerator{0};
  int m_denominator{1};

  static int gcd(int a, int b);
  void normalize();

public:
  Rational();
  Rational(int numerator, int denominator);

  // Accessors
  int getNumerator() const;
  int getDenominator() const;

  // Mutators
  void setNumerator(int numerator);
  void setDenominator(int denominator);

  // Operators
  Rational operator+(const Rational& rhs) const;
  Rational operator*(const Rational& rhs) const;
  bool operator<(const Rational& rhs) const;
  Rational& operator+=(const Rational& rhs);

  // Friend operators
  friend Rational operator+(int lhs, const Rational& rhs);
  friend std::ostream& operator<<(std::ostream& lhs, const Rational& rhs);
};


#endif //RATIONAL_H