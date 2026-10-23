#include <iostream>

void MyFunc(void)
{
	std::cout<<"MyFunc(void) called"<<std::endl;
}

void MyFunc(char c)
{
	(void)c;
	std::cout<<"Myfunc(char c) called"<<std::endl;
}

void MyFunc(int a, int b)
{
	(void)a;
	(void)b;
	std::cout<<"Myfunc(int a, int b) called"<<std::endl;
}

//함수명이 같을 때 매개변수가 다르면 오버로딩

int main(void)
{
	MyFunc();
	MyFunc('A');
	MyFunc(12,13);
	return 0;
}