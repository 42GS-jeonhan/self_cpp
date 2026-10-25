#include <iostream>
#include <stdlib.h>
using namespace std;

class Simple
{
public:
	Simple()
	{
		cout<<"I'm simple constructor!"<<endl;
	}
};

int main(void)
{
	cout<<"case 1: ";
	Simple *sp1=new Simple; // new를 사용해야 클래스 생성 시 생성자가 실행됨.

	cout<<"case 2: ";
	Simple *sp2=(Simple*)malloc(sizeof(Simple)*1);

	cout<<endl<<"end of main"<<endl;
	delete sp1;
	free(sp2);
	return 0;
}