#include "Specification.h"

Fraction::Fraction() {
	this->numerator = 0;
	this->denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
	this->setNumerator(numerator);

	// In the event the user tries to make a Fraction
	//  with a 0 in the denominator, set the denominator
	//  to 1.
	if (this->setDenominator(denominator) == false) {
		this->denominator = 1;
	}
}

int Fraction::getNumerator() {
	return this->numerator;
}

int Fraction::getDenominator() {
	return this->denominator;
}

bool Fraction::setNumerator(int newNumerator) {
	this->numerator = newNumerator;
	return true;
}

bool Fraction::setDenominator(int newDenominator) {
	bool goodValue = false;
	if (newDenominator != 0) {
		this->denominator = newDenominator;
		goodValue = true;
	}

	return goodValue;	// indicate if a new value was
						// accepted for the denominator
}

void Fraction::operator=(Fraction rFrac) {
	this->numerator = rFrac.getNumerator();
	this->denominator = rFrac.getDenominator();
}

Fraction Fraction::operator+(Fraction addMe) {
	Fraction returnMe;
	returnMe.setNumerator(this->numerator * addMe.denominator + this->denominator * addMe.numerator);
	returnMe.setDenominator(this->denominator * addMe.denominator);
	returnMe.reduce();
	return returnMe;
}

Fraction Fraction::operator-(Fraction subtractMe) {
	Fraction returnMe;
	returnMe.setNumerator(this->numerator * subtractMe.denominator - this->denominator * subtractMe.numerator);
	returnMe.setDenominator(this->denominator * subtractMe.denominator);
	returnMe.reduce();
	return returnMe;
}

Fraction Fraction::operator*(Fraction multiplyMe) {
	Fraction returnMe;
	returnMe.setNumerator(this->numerator * multiplyMe.numerator);
	returnMe.setDenominator(this->denominator * multiplyMe.denominator);
	returnMe.reduce();
	return returnMe;
}

Fraction Fraction::operator/(Fraction divideMe) {
	Fraction returnMe;
	returnMe.setNumerator(this->numerator * divideMe.denominator);
	returnMe.setDenominator(this->denominator * divideMe.numerator);
	returnMe.reduce();
	return returnMe;
}

ostream& operator<<(ostream& os, const Fraction& rFrac) {
	os << "(" << rFrac.numerator << " / " << rFrac.denominator << ")" << endl;
	return os;
}

void Fraction::reduce() {
	// Some basic storage
	short simplifyN = 0;
	short simplifyD = 1;
	bool simplified = false;

	// Store the numerator and denominator for manipulation
	simplifyN = this->getNumerator();
	simplifyD = this->getDenominator();

	do {
		simplified = true; // If both below conditions fail, fraction must be simplified
		if (simplifyN % 2 == 0 && simplifyD % 2 == 0){ // If divisible by 2
			simplifyN = simplifyN / 2;
			simplifyD = simplifyD / 2;
			simplified = false;
		}
		else {
			// If NOT divisible by 2
			for (short i = 3; i < (simplifyN / 2) && i < (simplifyD / 2); i = i + 2) { 
				// Finds the smallest factor to divide by to simplify fraction
				if (simplifyN % i == 0 && simplifyD % i == 0) {
					simplifyN = simplifyN / i;
					simplifyD = simplifyD / i;
					simplified = false;
					break;
				}
			}
		}
	} while (simplified == false);

	this->setNumerator(simplifyN);
	this->setDenominator(simplifyD);

	// Fraction simplified
}