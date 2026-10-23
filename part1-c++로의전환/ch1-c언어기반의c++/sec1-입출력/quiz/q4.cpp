#include <iostream>

int main()
{
	int num = 0;
	while (1)
	{
		std::cout<<"판매금액을 만원 단위로 입력(-1 to end): ";
		std::cin>>num;
		if (num == -1)
			break;
		std::cout<<"이번 달 급여: "<<50+(int)(num*0.12)<<"만원"<<std::endl;
	}
	std::cout<<"프로그램을 종료합니다."<<std::endl;
	return 0;
}