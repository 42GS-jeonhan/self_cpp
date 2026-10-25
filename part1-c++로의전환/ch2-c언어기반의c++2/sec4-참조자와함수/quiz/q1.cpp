#include <iostream>
using namespace std;

void increase(int &ref)
{
	ref += 1;
}

void inverse(int &ref)
{
	ref = -ref;
}

int main(void)
{
	int num = 100;
	increase(num);
	cout<<num<<endl;
	inverse(num);
	cout<<num<<endl;
	return 0;
}