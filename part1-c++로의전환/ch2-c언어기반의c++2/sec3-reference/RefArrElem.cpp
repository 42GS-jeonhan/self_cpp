#include <iostream>
using namespace std;

int main(void)
{
	// int &ref=20;
	// int &ref;
	// int &ref=NULL;
	// 참조자는 선언과 동시에 참조 대상이 지정되어야 함. 위 라인은 모두 오류

	int arr[3]={1,3,5};
	int &ref1=arr[0]; //배열 요소에도 참조 가능
	int &ref2=arr[1];
	int &ref3=arr[2];

	cout<<ref1<<endl;
	cout<<ref2<<endl;
	cout<<ref3<<endl;

	// 레퍼런스 배열도 가능한가?
	// int &refarr[3] = {ref1, ref2, ref3};
	// 안됨
	return 0;
}