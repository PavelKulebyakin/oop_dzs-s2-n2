#include "Complex.h"


Complex Complex::operator + (Complex number_2)
{
	return { number_2.im + this->im , number_2.re + this->re };
}

Complex Complex::operator - (Complex number_2)
{
	return { number_2.im - this->im , number_2.re - this->re };
}

Complex Complex::operator * (Complex number_2)
{
	return { number_2.re * this->re - number_2.im * this->im ,
		number_2.im * this->re + number_2.re * this->im };
}

Complex Complex::operator / (Complex number_2)
{

	if (pow(number_2.im, 2) + pow(number_2.re, 2) == 0) {
		std::cout << "Error: Incorrect value!";
		return { 0 , 0 };
	}
	else {
		double re = (number_2.re * this->re + number_2.im * this->im) /
			pow(number_2.im, 2) + pow(number_2.re, 2);

		double im = (number_2.re * this->im - number_2.im * this->re) /
			pow(number_2.im, 2) + pow(number_2.re, 2);

		return { re, im };
	}


}

double Complex::mod() {
	return pow(pow(this->im, 2) + pow(this->re, 2), 0.5);
}

//Complex Complex::random(int range)
//{
//	return Complex { rand() % range * pow(-1, rand() % 2) , rand() % range * pow(-1, rand() % 2) };
//}

void Complex::random_c(int range)
{
	this->im = rand() % range * pow(-1, rand() % 2);
	this->re = rand() % range * pow(-1, rand() % 2);
}

std::ostream& operator<<(std::ostream& out, Complex number)
{
	out << number.re << " + " << number.im << "i";
	return out;
}

std::istream& operator >> (std::istream& in, Complex& number)
{
	in >> number.re >> number.im;

	return in;
}
