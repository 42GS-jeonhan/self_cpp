#include <iostream>

namespace BestComImpl
{
	void SimpleFunc(void);
}

//이름이 같은 공간이 두번 선언되면 같은 공간으로 간주
namespace BestComImpl
{
	void PrettyFunc(void);
}

namespace ProgComImpl
{
	void SimpleFunc(void);
}

int main(void)
{
	BestComImpl::SimpleFunc();
	return 0;
}

void BestComImpl::SimpleFunc(void)
{
	std::cout<<"BestComd이 정의한 함수"<<std::endl;
	PrettyFunc(); //같은 네임스페이스의 함수는 네임스페이스 지정 없이 호출 가능
	ProgComImpl::SimpleFunc();
}

void BestComImpl::PrettyFunc(void)
{
	std::cout<<"So Pretty!"<<std::endl;
}

void ProgComImpl::SimpleFunc(void)
{
	std::cout<<"ProgCom이 정의한 함수"<<std::endl;
}