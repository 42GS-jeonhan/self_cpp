#include <iostream> // 표준 라이브러리의 헤더는 확장자 생략. iostream.h로 확장자까지 작성하게 되면 과거의 라이브러리(?)를 의미하게 됨

int main(void)
{
	int num = 20;
	std::cout<<"Hello World!"<<std::endl;
	std::cout<<"Hello "<<"World!"<<std::endl;
	std::cout<<num<<' '<<'A'; // endl이 개행을 포함함을 확인할 수 있음.
	std::cout<<' '<<3.14<<std::endl;
	return 0;
}
