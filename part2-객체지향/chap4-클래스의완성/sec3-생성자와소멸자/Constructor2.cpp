#include <iostream>
using namespace std;

class SimpleClass
{
	private:
		int num1;
		int num2;
	public:
		SimpleClass(int n1=0, int n2=0)
		{
			num1=n1;
			num2=n2;
		}
		void showData() const
		{
			cout<<num1<<" "<<num2<<endl;
		}
};

int main(void)
{
	SimpleClass sc1(); //객체 생성이 이 문법이 허용되지 않는 이유. 함수원형 선언으로 우선 처리됨. 함수원형 선언을 파일 상단이 아니라 어디서든 가능해졌기 때문에 생기는 문제?
	SimpleClass mysc=sc1();
	mysc.showData();
	return 0;
}

SimpleClass sc1()
{
	SimpleClass sc(20, 30);
	return sc;
}
