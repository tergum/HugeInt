#include "hugeint.h"

#include <iostream>
using std::cout;
using std::endl;
#include <assert.h>

const int tempSize = 1000;

HugeInt::HugeInt(long val)  							
{
	//cout << "long constructor" << endl;
	int temp[tempSize] = {0};

	for (int i = tempSize-1; val > 0 && i >= 0; --i)
	{
		temp[i] = val%10;
		val /= 10;
	}
	size = findSize(temp, tempSize);
	if (size > 0)
	{
		ptr = new int [size];
		assert(ptr != 0);
		copy(ptr, temp, size, tempSize);
	}
	else
		ptr = 0;
}
HugeInt::HugeInt(int *arrayInt, int arraySize)
{
	size = findSize(arrayInt, arraySize);
	if (size > 0)
	{
		ptr = new int [size];
		assert(ptr != 0);
		copy(ptr, arrayInt, size, arraySize);
	}
	else
		ptr = 0;
}
HugeInt::HugeInt(const char *string)				
{
	//cout << "char* constructor" << endl;

	size = strlen(string);

	if (size > 0)
	{
		ptr = new int [size];
		assert(ptr != 0);
		for (int i = 0; i < size; ++i)
			ptr[i] = string[i] - '0';
	}
	else
		ptr = 0;
}
HugeInt::HugeInt(const HugeInt &copyMe)
{
	//cout << "copy constructor" << endl;
	size = copyMe.size;
	ptr = new int [size];
	assert(ptr != 0);
	copy(ptr, copyMe.ptr, size, copyMe.size);
}
HugeInt::~HugeInt()										
{
	//cout << "destructor for " << *this << endl;
	delete [] ptr;
}
HugeInt &HugeInt::operator =(const HugeInt &op2)
{
	//cout << "= call" << endl;
	if (this != &op2)
	{
		delete [] ptr;
		size = op2.size;
		ptr = new int [size];
		assert(ptr != 0);
		copy(ptr, op2.ptr, size, op2.size);
	}
	else
		cout << "self-evaluation" << endl;

	return *this;
}

HugeInt HugeInt::operator +(const HugeInt &op2) const
{
	if (size == 0)
		return op2;
	else if (op2.size == 0)
		return *this;
	
	int temp[tempSize] = {0};

	int carry = 0, leftOp, rightOp;

	for (int i = size-1, j = op2.size-1, t = tempSize-1; i >= 0 || j >= 0 || carry != 0; --i, --j, --t)
	{
		/*
		if ((i < 0 || j < 0) &&  carry != 0)
		{
			temp[t] = carry;
			carry = 0;
			break;
		}
		*/

		leftOp = (i >= 0)? ptr[i] : 0;
		rightOp = (j >= 0)? op2.ptr[j] : 0;

		temp[t] = leftOp + rightOp + carry;

		if (temp[t] > 9)
		{
			temp[t] %= 10;
			carry = 1;
		}
		else
			carry = 0;
	}
	HugeInt result;
	result.size = findSize(temp, tempSize);
	if (size > 0)
	{
		result.ptr = new int [result.size];
		assert(result.ptr != 0);
		copy(result.ptr, temp, result.size, tempSize);
	}
	else
		result.ptr = 0;
	//cout << "temp+ result = " << result << endl;
	
	return result;
}
HugeInt HugeInt::operator +=(const HugeInt &op2)
{
	*this = *this + op2;
	return *this;
}
HugeInt HugeInt::operator -(const HugeInt &op2) const
{
	if (op2.size == 0)
		return *this;
	else if (*this == op2 || *this < op2)
		return 0L;
	
	int temp[tempSize] = {0};
	int carry = 0, leftOp, rightOp;

	for (int i = size-1, j = op2.size-1, t = tempSize-1; i >= 0 || j >= 0; --i, --j, --t)
	{
		leftOp = (i >= 0)? ptr[i] : 0;
		rightOp = (j >= 0)? op2.ptr[j] : 0;

		//temp[t] = leftOp + rightOp + carry;

		if (leftOp-carry < rightOp)
		{
			temp[t] = (leftOp + 10) - rightOp - carry;
			carry = 1;
		}
		else
		{
			temp[t] = leftOp - rightOp - carry;
			carry = 0;
		}
	}
	HugeInt result;
	result.size = findSize(temp, tempSize);
	if (size > 0)
	{
		result.ptr = new int [result.size];
		assert(result.ptr != 0);
		copy(result.ptr, temp, result.size, tempSize);
	}
	else
		result.ptr = 0;
	//cout << "temp+ result = " << result << endl;
	
	return result;
}
HugeInt HugeInt::operator -=(const HugeInt &op2)
{
	*this =  *this - op2;
	return *this;
}
ostream &operator<<(ostream &output, HugeInt &num)
{
	if (num.size == 0)
		cout << 0;
	else
	{
		for (int i = 0; i < num.size; ++i)
			cout << num.ptr[i];
	}
	
	return output;
}

HugeInt HugeInt::operator *(const HugeInt &op2) const
{
	if (size == 0 || op2.size == 0)
		return 0;

	HugeInt tempInt, result;

	int temp[tempSize] = {0};

	int carry = 0;

	for (int i = op2.size-1, offset = 0; i >= 0; --i, ++offset)		
	{
		for (int j = size-1, h = 0; j >= 0 || carry != 0; --j, h++)
		{
			if (j < 0 && carry != 0)
			{
				temp[tempSize-1-h-offset] = carry;
				break;
			}
			temp[tempSize-1-h-offset] = op2.ptr[i]*ptr[j] + carry;
			if (temp[tempSize-1-h-offset] > 9)
			{
				carry = temp[tempSize-1-h-offset]/10;
				temp[tempSize-1-h-offset] %= 10;
			}
			else
 				carry = 0;
		}
		carry = 0;
		tempInt = HugeInt(temp, tempSize);
		//cout << "tempInt* = " << tempInt << endl;
		result = result + tempInt;
		//cout << "result* = " << result << endl;
		
		clear(temp, tempSize);
	}
	return result;
	
}
HugeInt HugeInt::operator *=(const HugeInt &op2)
{
	*this =  *this * op2;
	return *this;
}
int HugeInt::operator>(const HugeInt &op2) const
{
	if (size > op2.size)
		return 1;
	else if (size < op2.size)
		return 0;

	for (int i = 0; i < size; ++i)
	{
		if (ptr[i] > op2.ptr[i])
			return 1;
		if (ptr[i] < op2.ptr[i])
			return 0;
	}
	return 0;
}
int HugeInt::operator>=(const HugeInt &op2) const
{
	return (*this == op2 && *this > op2);

}
int HugeInt::operator<(const HugeInt &op2) const
{
	if (size < op2.size)
		return 1;
	else if (size > op2.size)
		return 0;

	for (int i = 0; i < size; ++i)
	{
		if (ptr[i] < op2.ptr[i])
			return 1;
		if (ptr[i] > op2.ptr[i])
			return 0;
	}
	return 0;

}
int HugeInt::operator<=(const HugeInt &op2) const
{
	return (*this == op2 && *this < op2);

}
int HugeInt::operator==(const HugeInt &op2) const
{
	if (size != op2.size)
		return 0;

	for (int i = 0; i < size; ++i)
		if (ptr[i] != op2.ptr[i])
			return 0;
	return 1;

}
int HugeInt::operator!=(const HugeInt &op2) const
{
	return !(*this == op2);
}

HugeInt HugeInt::operator /(const HugeInt &op2) const
{
	assert(op2 != 0L);

	if (op2 > *this)
		return 0L;
	else if (op2 == *this)
		return 1L;

	int digit = 0, k = 1;
	HugeInt result, medium, diff;

	while (digit < size)
	{
		medium = medium*10 + diff*10 + this->ptr[digit];	//enlarge medium devision
		//cout << "medium = " << medium << endl;
		++digit;
		if (medium < op2)
			if (result > 0L)
			{
				result = result*10;
				//cout << "result = " << result << endl;
				diff = 0L;
				continue;
			}
			else
				continue;
		while(op2*k < medium)
		{
			//cout << "op2*k = " << op2*k << endl;
			//cout << "medium = " << medium << endl;
			++k;
		}
		if (op2*k > medium || op2*k < medium)
			--k;
		//cout << "op2*k = " << op2*k << endl;
		diff = medium - op2*k;
		//cout << "diff = " << diff << endl;
		result = result*10 + k;
		//cout << "result = " << result << endl;

		medium = 0L;
		k = 1;
	}

	return result;
}
HugeInt HugeInt::operator /=(const HugeInt &op2)
{
	*this =  *this / op2;
	return *this;
}
HugeInt HugeInt::operator %(const HugeInt &op2) const
{
	assert(op2 != 0L);

	if (op2 > *this)
		return *this;
	else if (op2 == *this)
		return 0L;

	int digit = 0, k = 1;
	HugeInt result, medium, diff;

	while (digit < size)
	{
		medium = medium*10 + diff*10 + this->ptr[digit];	//enlarge medium devision
		++digit;
		if (medium < op2)
			if (result > 0L)
			{
				result = result*10;
				diff = 0L;
				continue;
			}
			else
				continue;
		while(op2*k < medium)
		{
			++k;
		}
		if (op2*k > medium || op2*k < medium)
			--k;
		diff = medium - op2*k;
		result = result*10 + k;

		medium = 0L;
		k = 1;
	}

	return diff;
}
HugeInt HugeInt::operator %=(const HugeInt &op2)
{
	*this =  *this % op2;
	return *this;
}
//utilites
int HugeInt::findSize(int *itsName, int itsSize) const	
{
	int i;

	for (i = 0; itsName[i] == 0 && i < itsSize; ++i)
	;

	return itsSize - i;
}
void HugeInt::copy(int* to, int* from, int toSize, int fromSize) const
{
	for (int i = 0; i < toSize; ++i)
		to[i] = from[fromSize-toSize+i];
}
void HugeInt::clear(int *name, int size) const
{
	for (int i = 0; i < size; ++i)
		name[i] = 0;
}
