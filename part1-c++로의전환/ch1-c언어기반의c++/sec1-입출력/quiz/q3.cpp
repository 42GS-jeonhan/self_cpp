#include <iostream>

int main(void)
{
	int num;
	std::cout<<"출력할 구구단 단수: ";
	std::cin>>num;
	for(int i=1;i<=9;i++)
		std::cout<<num<<"×"<<i<<"="<<num*i<<std::endl;
	return 0;
}