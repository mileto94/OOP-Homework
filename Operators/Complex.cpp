#include<iostream>
#include<math.h>
#include "Complex.h"

using namespace std;


const double PI = atan(1.0) * 4;


Complex Complex::GetI()
{
	Complex number(0, 1);
	return number;
}


Complex Complex::Conjugate() const
{
	Complex newNumber(this->real, this->imaginary * (-1));
	return newNumber;
}


double Complex::Modulus() const
{
	return sqrt(pow(this->real,2) + pow(this->imaginary,2));
}


Complex Complex::Power(double n) const
{
	double r = this->Modulus();
	double Fi = acos(this->real / r);
	Complex result(int(pow(r, n) * cos(n * Fi)), int(pow(r, n) * sin(n * Fi)));
	return result;
}


Complex Complex::Root(double n, double k) const
{	
	double r = this->Modulus();
	double Fi = acos(this->real / r);

	if(n != 0)
	{
		Complex result(int(pow(r, 1/n) * cos((Fi + 2 * k * PI)/n)), int(pow(r, 1/n) * sin((Fi + 2 * k * PI)/n)));
		return result;
	}
	else
	{
		Complex r(1);
		return r;
	}
}


double Complex::Argument() const
{
	double arg = this->Real() / this->Imaginary();
	if(arg > 0 && arg < 360)
		return arg;
	else
	{
		while(arg > 0 && arg > 360)
			arg -= 360;
		return arg;
	}
}


bool Complex::IsReal() const
{
	return (this->Imaginary() == 0);
}


Complex operator+(const Complex& p, const Complex& q)
{
	Complex result(p.Real() + q.Real(), p.Imaginary() + q.Imaginary());
	return result;
}


Complex operator-(const Complex& p, const Complex& q)
{
	Complex result(p.Real() - q.Real(), p.Imaginary() - q.Imaginary());
	return result;
}


Complex operator*(const Complex& p, const Complex& q)
{
	double r = p.Real() * q.Real() - p.Imaginary() * q.Imaginary();
	double i = p.Imaginary() * q.Real() + p.Real() * q.Imaginary();
	Complex result(r, i);
	return result;
}


Complex operator/(const Complex& p, const Complex& q)
{
	double rP = p.Modulus();
	double FiP = acos(p.Real() / rP);

	double rQ = q.Modulus();
	double FiQ = acos(q.Real() / rQ);

	Complex result(int(rP * cos(FiP - FiQ) / rQ), int(rP / rQ * sin(FiP - FiQ)));
	return result;
}


Complex operator^(const Complex& number, double n)
{
	return number.Power(n);
}


bool operator==(const Complex& lhs, const Complex& rhs)
{
	return (lhs.Real() == rhs.Real() && lhs.Imaginary() == rhs.Imaginary());
}


bool operator!=(const Complex& lhs, const Complex& rhs)
{
	return !(operator==(lhs, rhs));
}


istream& operator>>(istream& stream, Complex& number)
{
	double r;
	double i;
	stream >> r >> i;
	Complex result(r, i);
	return stream;
}


ostream& operator<<(ostream& stream, const Complex& number)
{
	if(number.Imaginary() == 0)
		stream << number.Real() << endl;
	else if(number.Imaginary() == 1)
		stream << number.Real() << " + i" << endl;
	else if(number.Imaginary() == -1)
		stream << number.Real() << " - i" <<endl;
	else if(number.Imaginary() < 0)
		stream << number.Real() << " - " << abs(number.Imaginary()) << "i" << endl;
	else
		stream << number.Real() << " + " << number.Imaginary() << "i" << endl;
	return stream;
}

