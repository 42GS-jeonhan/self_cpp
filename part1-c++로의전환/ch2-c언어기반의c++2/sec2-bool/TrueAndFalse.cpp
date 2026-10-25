#include <iostream>

using namespace std;

int main(void)
{
	int num=10;
	int i=0;

	cout<<"true: "<<true<<endl; //1로 출력
	cout<<"false: "<<false<<endl; //0으로 출력

	while (true) // 판별식에 사용
	{
		cout<<i++<<' ';
		if(i > num)
			break;
	}
	cout<<endl;

	cout<<"sizeof 1: "<<sizeof(1)<<endl;
	cout<<"sizeof 0: "<<sizeof(0)<<endl; //int 4바이트
	cout<<"sizeof true: "<<sizeof(true)<<endl;
	cout<<"sizeof false: "<<sizeof(false)<<endl;//bool 1바이트
}