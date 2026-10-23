#include <iostream>

int Adder (int num1=1, int num2=2) //매개변수가 전달되지 않으면 해당 값을 기본값으로 사용
{
	return num1+num2;
}

int main(void)
{
	std::cout<<Adder()<<std::endl;
	std::cout<<Adder(5)<<std::endl; //인자가 일부만 전달된 경우는 왼쪽 인자부터 처리, 나머지는 기본값
	std::cout<<Adder(3,5)<<std::endl;
}