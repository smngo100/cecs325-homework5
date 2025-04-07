//
// Created by sophi on 4/5/2025.
//

#include "Rational.h"

int Rational::gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Normalizes the rational number by finding the GCD of its numerator and denominator, and dividing both by the GCD
void Rational::normalize() {
    // Handle special cases (like zero numerator)
    if (m_denominator == 0) {
      return;
    }
    if (m_numerator == 0) {
        m_denominator = 1;
        return;
    }

    // Handle sign issues (ensure denominator is positive)
    if (m_numerator < 0 && m_denominator < 0) {
        m_numerator = std::abs(m_numerator);
        m_denominator = std::abs(m_denominator);
    }
    else if (m_denominator < 0) {
        m_numerator = -m_numerator;
        m_denominator = std::abs(m_denominator);
    }

    // Find the GCD of the absolute values
    int gcdValue = gcd(std::abs(m_numerator), std::abs(m_denominator));

    // Divide both numerator and denominator by the GCD
    m_numerator /= gcdValue;
    m_denominator /= gcdValue;
}

// A public default constructor
Rational::Rational()
    : m_numerator(0), m_denominator(1) {}

// A public constructor taking two integer parameters for the numerator and denominator
Rational::Rational(int numerator, int denominator)
    : m_numerator(numerator), m_denominator(denominator) {
    normalize();
}

// Accessors
int Rational::getNumerator() const {
    return m_numerator;
}

int Rational::getDenominator() const {
    return m_denominator;
}

// Mutators
void Rational::setNumerator(int numerator) {
    m_numerator = numerator;
    normalize();
}

void Rational::setDenominator(int denominator) {
    m_denominator = denominator;
    normalize();
}

Rational Rational::operator+(const Rational &rhs) const {
    int newNumerator{m_numerator * rhs.m_denominator + rhs.m_numerator * m_denominator};
    int newDenominator{m_denominator * rhs.m_denominator};

    return Rational(newNumerator, newDenominator);
}

Rational Rational::operator*(const Rational &rhs) const {
    return Rational(m_numerator * rhs.m_numerator, m_denominator * rhs.m_denominator);
}

bool Rational::operator<(const Rational &rhs) const {
    return m_numerator * rhs.m_denominator < m_denominator * rhs.m_numerator;
}

Rational& Rational::operator+=(const Rational &rhs) {
    m_numerator = m_numerator * rhs.m_denominator + rhs.m_numerator * m_denominator;
    m_denominator *= rhs.m_denominator;
    normalize();
    return *this;
}

Rational operator+(int lhs, const Rational& rhs) {
    return Rational(lhs * rhs.getDenominator() + rhs.getNumerator(), rhs.getDenominator());
}

std::ostream &operator<<(std::ostream &lhs, const Rational &rhs) {
    if (rhs.m_denominator == 1) {
        lhs << rhs.m_numerator;
    } else {
        lhs << rhs.m_numerator << '/' << rhs.m_denominator;
    }
    return lhs;
}