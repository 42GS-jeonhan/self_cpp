#include <cmath> // 기존 c 라이브러리를 사용하고 싶을 때는 헤더명에 c를 붙이고 .h 생략
#include <cstdio>
#include <cstring>
// using namespace std;

int main(void)
{
	char str1[]="Result";
	char str2[30];

	std::strcpy(str2, str1); // c++ 라이브러리와 마찬가지로 기본 라이브러리 함수들은 네임스페이스 std내부에 있음.
	std::printf("%s: %f \n", str1, std::sin(0.14));
	std::printf("%s: %f \n", str2, std::abs(-1.25)); // abs의 경우 c에서는 int형에 사용하는 함수지만 c++에서는 오버로딩으로 타 자료형에 대해서 오버로딩 구현되어있음.
	return 0;
}