#include "vektor2D.hpp"

Vektor2D::Vektor2D(double x, double y) {
	_x = x;
	_y = y;
}

Vektor2D::Vektor2D(double a) {
	_x = a;
	_y = a;
}

Vektor2D Vektor2D::add(const Vektor2D &b) const{
	return {_x+b._x, _y+b._y};
}

double Vektor2D::mul(const Vektor2D &b) const{
	return _x*b._x + _y*b._y;
}

Vektor2D Vektor2D::operator+(const Vektor2D &b) const{
	return add(b);
}

double Vektor2D::operator*(const Vektor2D &b) const{
	return mul(b);
}

bool Vektor2D::operator<(const Vektor2D &b) const{
	return (_x < b._x) && (_y < b._y);
}

std::ostream& operator<<(std::ostream& os, const Vektor2D &v) {
	os << "(" << v._x << "|" << v._y << ")";
	return os;
}

std::istream& operator>>(std::istream& is, Vektor2D &v) {
	is >> v._x;
	is >> v._y;
	return is;
}