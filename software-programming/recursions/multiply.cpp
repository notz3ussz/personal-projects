#include <iostream>
using namespace std;

long multiply(long a, long b)
{
	switch(b)
	{
		case 0:
			return 0;
		case 1:
			return a;
		default:
			return a + multiply(a, b - 1);
	}
	
}

int main()
{
	long a, b;
	
	cout << "Enter two numbers: ";
	cin >> a >> b;
	
	cout << "Product of a * b = " << multiply(a, b) << endl;
	
	return 0;
}