#include "hugeint.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
  HugeInt n1(680), n2(89), n3("95"), n4("6"), n5, n6;

	cout << "n1 = " << n1 << endl
		 << "n2 = " << n2 << endl
		 << "n3 = " << n3 << endl
		 << "n4 = " << n4 << endl
		 << "n5 = " << n5 << endl
		 << "n6 = " << n6 << endl;
	cout << endl;
		
	n5 = n3+n4;
	cout << "n5 = n3 + n4 = " << n3 << " + " << n4 << " = " << n5 << endl;
	cout << "n1 = " << n1 << endl
 		 << "n2 = " << n2 << endl
 		 << "n3 = " << n3 << endl
		 << "n1 = " << n4 << endl
		 << "n5 = " << n5 << endl
		 << "n6 = " << n6 << endl;
	cout << endl;
	
	n5 = n1-n2;
	cout << "n5 = n1 - n2 = " << n1 << " - " << n2 << " = " << n5 << endl;
	cout << "n1 = " << n1 << endl
 		 << "n2 = " << n2 << endl
 		 << "n3 = " << n3 << endl
		 << "n1 = " << n4 << endl
		 << "n5 = " << n5 << endl
		 << "n6 = " << n6 << endl;
	cout << endl;
	
	n5 = n1*n2;
	cout << "n5 = n1 * n2 = " << n1 << " * " << n2 << " = " << n5 << endl;
	cout << "n1 = " << n1 << endl
 		 << "n2 = " << n2 << endl
 		 << "n3 = " << n3 << endl
		 << "n1 = " << n4 << endl
		 << "n5 = " << n5 << endl
		 << "n6 = " << n6 << endl;
	cout << endl;

	n6 = n5/n2;
	cout << "n6 = n5 / n2 = " << n5 << " / " << n2 << " = " << n6 << endl;
	cout << "n1 = " << n1 << endl
 		 << "n2 = " << n2 << endl
 		 << "n3 = " << n3 << endl
		 << "n1 = " << n4 << endl
		 << "n5 = " << n5 << endl
		 << "n6 = " << n6 << endl;	
	cout << endl;

	n5 = n1%n2;
	cout << "n5 = n1 % n2 = " << n1 << " % " << n2 << " = " << n5 << endl;
	cout << "n1 = " << n1 << endl
 		 << "n2 = " << n2 << endl
 		 << "n3 = " << n3 << endl
		 << "n1 = " << n4 << endl
		 << "n5 = " << n5 << endl
		 << "n6 = " << n6 << endl;
	cout << endl;

	n1 = n2 = n4 = 65;
	cout << "n1 = n2 = n4" << endl;
	cout << "n1 = " << n1 << endl
 		 << "n2 = " << n2 << endl
 		 << "n3 = " << n3 << endl
		 << "n1 = " << n4 << endl
		 << "n5 = " << n5 << endl
		 << "n6 = " << n6 << endl;
	cout << endl;

	n1 = 9199;
	n2 = 99;

	n1 += n2;
	cout << "n1 += n2 = " << n1 << endl;
	cout << "n1 = " << n1 << endl
 		 << "n2 = " << n2 << endl
 		 << "n3 = " << n3 << endl
		 << "n1 = " << n4 << endl
		 << "n5 = " << n5 << endl
		 << "n6 = " << n6 << endl;
	cout << endl;

	n6 = 111;
	n1 = 99;
	n6 -= n1;
	cout << "n6 -= n1 = " << n6 << endl;
	cout << "n1 = " << n1 << endl
 		 << "n2 = " << n2 << endl
 		 << "n3 = " << n3 << endl
		 << "n1 = " << n4 << endl
		 << "n5 = " << n5 << endl
		 << "n6 = " << n6 << endl;
	cout << endl;

	n1 = 13;
	n2 = 5;

	n1 /= n2;
	cout << "n1 /= n2 = " << n1 << endl;
	cout << "n1 = " << n1 << endl
 		 << "n2 = " << n2 << endl
 		 << "n3 = " << n3 << endl
		 << "n1 = " << n4 << endl
		 << "n5 = " << n5 << endl
		 << "n6 = " << n6 << endl;
	cout << endl;

	n1 = 13;
	n2 = 5;

	n1 %= n2;
	cout << "n1 %= n2 = " << n1 << endl;
	cout << "n1 = " << n1 << endl
 		 << "n2 = " << n2 << endl
 		 << "n3 = " << n3 << endl
		 << "n1 = " << n4 << endl
		 << "n5 = " << n5 << endl
		 << "n6 = " << n6 << endl;
	cout << endl;



	return 0;
}
