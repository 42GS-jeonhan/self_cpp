#include <iostream>

inline int SQUARE(int x)
{
	return x*x;
}

/*
매크로 함수와의 차이점?
매크로 함수는 전처리기에서, 키워드 inline을 이용한 함수는 컴파일러에서 인라인화 처리됨.
이로 인해 inline 키워드 함수는 컴파일러 단에서 성능 저해가 있다고 판단되는 경우 키워드를 무시하는 경우도 있고, 반대로 컴파일러가 임의로 일반 함수를 inline화 하는 경우도 있음.
*/

int main(void)
{
	std::cout<<SQUARE(5)<<std::endl;
	std::cout<<SQUARE(12)<<std::endl;
	return 0;
}