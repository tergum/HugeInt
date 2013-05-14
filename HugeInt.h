#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
using std::ostream;

class HugeInt {
  friend ostream &operator<<(ostream &, HugeInt &);
public:
	HugeInt(long = 0);
	HugeInt(const char *);
	HugeInt(const HugeInt &);
	HugeInt::HugeInt(int *, int);
	~HugeInt();

	HugeInt &operator=(const HugeInt &);

	HugeInt operator+(const HugeInt &) const;
	HugeInt operator+=(const HugeInt &);
	HugeInt operator-(const HugeInt &) const;
	HugeInt operator-=(const HugeInt &);
	HugeInt operator*(const HugeInt &) const;
	HugeInt operator*=(const HugeInt &);
	HugeInt operator/(const HugeInt &) const;
	HugeInt operator/=(const HugeInt &);
	HugeInt operator%(const HugeInt &) const;
	HugeInt operator%=(const HugeInt &);

	int operator>(const HugeInt &) const;
	int operator>=(const HugeInt &) const;
	int operator<(const HugeInt &) const;
	int operator<=(const HugeInt &) const;
	int operator==(const HugeInt &) const;
	int operator!=(const HugeInt &) const;
private:
	int *ptr;
	int size;

	int findSize(int *arrayName, int arraySize) const;
	void copy(int* dest, int* src, int destSize, int srcSize) const;
	void clear(int* arrayName, int arraySize) const;
};

#endif
