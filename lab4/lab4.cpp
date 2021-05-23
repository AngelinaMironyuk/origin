#include "lab4.h"
#include <iostream>
#include <cmath>

double Figure::checkValue(const double value) const
{
	if (value <= 0)
		throw std::out_of_range("Non-positive value");
	return value;
}

Cilinder::Cilinder(const double r, const double h)
{
	this->r = checkValue(r);
	this->h = checkValue(h);
}

double Cilinder::getPerimeter()
{
	this->perimeter = TWO_PI * this->r;
	return this->perimeter;
}

double Cilinder::getArea()
{
	this->area = CYLINDER_BASES * PI * this->r * this->r + getPerimeter() * h;
	return this->area;
}

Cube::Cube(const double a)
{
	this->a = checkValue(a);
}

double Cube::getPerimeter()
{
	this->perimeter = ADGES_OF_CUBE * this->a;
	return this->perimeter;
}

double Cube::getArea()
{
	this->area = FACES_OF_CUBE * this->a * this->a;
	return this->area;
}

Tetrahedron::Tetrahedron(const double a)
{
	this->a = checkValue(a);
}

double Tetrahedron::getPerimeter()
{
	this->perimeter = ADGES_OF_TETR * this->a;
	return this->perimeter;
}

double Tetrahedron::getArea()
{
	this->area = this->a * this->a * FACTOR_AREA_TETR;
	return this->area;
}

std::ostream& operator<<(std::ostream& out, const Figure& figure)
{
	out << "Perimetr " << figure.perimeter << std::endl << "Area " << figure.area << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Cilinder& cylindr)
{
	double r, h;
	in >> r >> h;
	cylindr = Cilinder(r,h);
	return in;
}

std::istream& operator>>(std::istream& in, Cube& cube)
{
	double a;
	in >> a;
	cube = Cube(a);
	return in;
}

std::istream& operator>>(std::istream& in, Tetrahedron& tetrahedron)
{
	double a;
	in >> a;
	tetrahedron = Tetrahedron(a);
	return in;
}
