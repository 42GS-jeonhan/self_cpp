#include <iostream>
using namespace std;

int Adder(const int &num1, const int &num2)
{
	return num1+num2;
}

int main()
{
	const int n1 = 2;
	const int n2 = 7;
	cout<<Adder(3,4)<<endl;
	cout<<Adder(n1,n2)<<endl;
	cout<<Adder(n1,100)<<endl;
	return 0;
}