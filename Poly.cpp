#include "Poly.h"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;


Poly::Poly(){};
Poly::Poly(const double d){
	coeff[0] = d;
}
Poly::Poly(const Poly& p){
	this->coeff = p.coeff;
}


ostream& operator<<(ostream& out, const Poly& p) {
	int start = 1;
	for (auto it = p.coeff.crbegin(); it != p.coeff.crend(); ++it){
		if(!start){
			cout << " + "; 
		}
		if(it->first == 0){
			if(it->second != 1)
				cout << it->second;
		}
		else if(it->first == 1){
			if(it->second != 1)
				cout << it->second;
			cout << "x";
		}
        else {if(it->second != 1)
				cout << it->second;
			cout << "x^" << it->first;
		}
        start = 0;
	}
	if(start)
		cout << "0";
    return out;
}

double& Poly::operator[](int index){
	return coeff[index];
}

void Poly::freeZeros(){
	for (auto it = coeff.begin(); it != coeff.end();)
    {
        if (it->second == 0)
            it = coeff.erase(it);
        else
            ++it;
    }
}


Poly Poly::operator+(const Poly rhs) const{
	Poly newP(rhs);
	for(auto pair : coeff){
		newP[pair.first] += pair.second;
	}
	
	return newP;
}


Poly operator+(double d, Poly p){
	Poly newP(p);
	newP[0] += d;
	return newP;
}

Poly Poly::operator-() const{
	Poly p;
	for(auto pair : coeff){
		p[pair.first] = -pair.second;
	}
	return p;
}

Poly Poly::operator-(const Poly rhs) const{
	Poly newP(*this);
	for(auto pair : rhs.coeff){
		newP[pair.first] -= pair.second;
	}
	newP.freeZeros();
	return newP;
}

Poly operator-(double d, Poly p){
	Poly newP(-p);
	newP[0] += d;
	newP.freeZeros();
	return newP;
}

Poly Poly::operator *(const Poly rhs) const {
	Poly newP;
	int tmpExp;
	double tmpCoeff;
	for (auto it_1 = coeff.begin(); it_1 != coeff.end(); it_1++){
		for (auto it_2 = rhs.coeff.begin(); it_2 != rhs.coeff.end(); it_2++){
			tmpExp = it_1->first + it_2->first;
			tmpCoeff = it_1->second * it_2->second;
			newP[tmpExp] += tmpCoeff;
		}
    }
    return newP;
}

Poly operator*(double d, Poly p){
	Poly newP;
	for (auto it = p.coeff.begin(); it != p.coeff.end(); it++){
		newP[it->first] = d * it->second;
    }
    return newP;
}


double Poly::operator()(const double d) const{
	double value = 0;
	for (auto pair : coeff){
		value += pair.second * pow(d, pair.first);
    }
    return value;
}








/*
Poly::Poly(const double d): nCoef(1){
	this->arrOfCoef = (double*)malloc(1 * sizeof(double));
	this->arrOfPositions = (int*)malloc(1*sizeof(int));
	if(!arrOfCoef || !arrOfPositions){
		exit(1);
	}
	this->arrOfCoef[0] = d;
	this->arrOfPositions[0] = 0;
}

Poly::~Poly(){
	free(arrOfCoef);
	free(arrOfPositions);
}

double& Poly::operator[](int index){
}*/



