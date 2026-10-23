#include <iostream>

int main(void)
{
	int val1;
	std::cout<<"첫 번째 숫자 입력: ";
	std::cin>>val1; // 입력을 받을때는 >> 연산자 사용, 입력도 출력과 마찬가지로 포맷 지정 없이 가능. 대상 변수의 자료형에 맞게 파싱

	int val2;
	std::cout<<"두 번째 숫자 입력: ";
	std::cin>>val2;

	int result = val1 + val2;
	std::cout<<"덧셈 결과: "<<result<<std::endl;
	return 0;
}