#include <iostream>

namespace Hybrid
{
	void hybFunc(void)
	{
		std::cout<<"So simple function!"<<std::endl;
		std::cout<<"In namespace Hybrid!"<<std::endl;
	}
}

int main(void)
{
	using Hybrid::hybFunc; //현재 스코프 내에서 호출되는 hybFunc는 Hybrid::hybFunc임을 지정함
	hybFunc();
	return 0;
}