#include <iostream>

using namespace std;

bool IsPositive(int num)
{
	if(num < 0)
		return false;
	else
		return true;
}

int main(void)
{
	bool isPos; //자료형으로 bool 사용
	int num;
	cout<<"Input number: ";
	cin>>num;

	isPos=IsPositive(num);
	if(isPos)
		cout<<"Positive"<<endl;
	else
		cout<<"Negative"<<endl;
	return 0;
}