#include <iostream>

int Adder (int num1=1, int num2=2); //함수 원형 선언을 따로 하는 경우 원형 선언부에 기본값 설정이 위치해야함.

int main(void)
{
	std::cout<<Adder()<<std::endl;
	std::cout<<Adder(5)<<std::endl;
	std::cout<<Adder(3,5)<<std::endl;
}

int Adder (int num1, int num2)
{
	return num1+num2;
}