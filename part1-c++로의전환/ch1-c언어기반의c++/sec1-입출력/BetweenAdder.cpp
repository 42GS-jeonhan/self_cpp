#include <iostream>

int main(void)
{
	int val1, val2;
	int result = 0;
	std::cout<<"두 개의 숫자 입력: ";
	std::cin>>val1>>val2; //cin 하나에서 연속적인 데이터 입력 가능, 입력과 입력 사이는 공백(스페이스, 줄바꿈, 탭)으로 구분

	if(val1<val2)
	{
		for(int i=val1+1; i<val2; i++) // for 초기화 내에서 변수 선언 가능
			result += i;
	}
	else
	{
		for(int i=val2+1;i<val1;i++)
			result += i;
	}
	std::cout<<"두 수 사이의 정수 합: "<<result<<std::endl;
	return 0;
}