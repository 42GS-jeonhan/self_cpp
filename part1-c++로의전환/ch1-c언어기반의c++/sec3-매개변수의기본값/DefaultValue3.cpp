#include <iostream>

int BoxVolume(int length, int width=1, int height=1); //일부 인자에만 기본값을 설정하는 경우 기본값이 있는 인자를 오른쪽에 선언해야 함. 전달받은 인자가 왼쪽부터 채워지기 때문

int main(void)
{
	std::cout<<"[3,3,3] : "<<BoxVolume(3,3,3)<<std::endl;
	std::cout<<"[5,5,D] : "<<BoxVolume(5,5)<<std::endl;
	std::cout<<"[7,D,D] : "<<BoxVolume(7)<<std::endl;
	// std::cout<<"[D,D,D] : "<<BoxVolume()<<std::endl; //오류 발생
	return 0;
}

int BoxVolume(int length, int width, int height)
{
	return length * width * height;
}
