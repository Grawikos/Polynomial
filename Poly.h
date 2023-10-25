#include <fstream>
#include <iostream>
#include <map>
#pragma once


class Poly {
	
	private:
		std::map<int, double> coeff;
	public:
		Poly();
		Poly(const double d);
		Poly(const Poly& p);
		double& operator[](int index);
		friend std::ostream& operator<<(std::ostream& out, const Poly& p);
		void freeZeros();
		
		Poly operator+(const Poly rhs) const;
		Poly operator-(const Poly rhs) const;
		Poly operator-() const;
		Poly operator*(const Poly rhs) const;
		friend Poly operator*(double d, Poly p);
		double operator()(const double d) const;

};

Poly operator+(double d, Poly p);

Poly operator-(double d, Poly p);






//#endif
