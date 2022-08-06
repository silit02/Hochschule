#ifndef _VEKTOR2D_HPP
#define _VEKTOR2D_HPP

#include <iostream>

class Vektor2D {
	friend std::ostream& operator<<(std::ostream& os, const Vektor2D& v);
	friend std::istream& operator>>(std::istream& is, Vektor2D& v);
protected:
	double _x, _y;
public:
	Vektor2D(double x, double y);
	Vektor2D(double a = 0);
	Vektor2D add(const Vektor2D &b) const;
	double mul(const Vektor2D &b) const;
	//void drehe(double alpha);
	
	Vektor2D operator+(const Vektor2D &b) const;
	double operator*(const Vektor2D &b) const;
	bool operator<(const Vektor2D &b) const;
};

#endif	