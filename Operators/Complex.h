#ifndef COMPLEX_H_GUARD
#define COMPLEX_H_GUARD


#include<iostream>
#include<istream>
#include<ostream>


struct Complex
{
private:
	double real, imaginary;

public:
	Complex() : real(0), imaginary(0) {}

	Complex(double real) : real(real), imaginary(0) {}

	Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

	double Real() const
	{
		return this->real;
	}

	double Imaginary() const
	{
		return this->imaginary;
	}
	
	static Complex GetI();

	Complex Conjugate() const;

	double Modulus() const;

	Complex Power(double n) const;

	Complex Root(double n, double k) const;
	
	double Argument() const;

	bool IsReal() const;
};


Complex operator+(const Complex& p, const Complex& q);

Complex operator-(const Complex& p, const Complex& q);

Complex operator*(const Complex& p, const Complex& q);

Complex operator/(const Complex& p, const Complex& q);

Complex operator^(const Complex& number, double n);

bool operator==(const Complex& lhs, const Complex& rhs);

bool operator!=(const Complex& lhs, const Complex& rhs);

std::istream& operator>>(std::istream& stream, Complex& number);

std::ostream& operator<<(std::ostream& stream, const Complex& number);


#endif //COMPLEX_H_GUARD