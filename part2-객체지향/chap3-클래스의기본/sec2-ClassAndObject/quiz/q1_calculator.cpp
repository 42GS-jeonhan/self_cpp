#include <iostream>
using namespace std;

class Calculator
{
	private:
		int add_cnt;
		int min_cnt;
		int mul_cnt;
		int div_cnt;
	public:
		void Init(void)
		{
			add_cnt = 0;
			min_cnt = 0;
			mul_cnt = 0;
			div_cnt = 0;
		}
		void ShowOpCount()
		{
			cout<<"덧셈: "<<add_cnt<<" 뺄셈: "<<min_cnt<<" 곱셈: "<<mul_cnt<<" 나눗셈: "<<div_cnt<<endl;
		}
		double Add(double a, double b)
		{
			add_cnt++;
			return a+b;
		}
		double Min(double a, double b)
		{
			min_cnt++;
			return a-b;
		}
		double Mul(double a, double b)
		{
			mul_cnt++;
			return a*b;
		}
		double Div(double a, double b)
		{
			div_cnt++;
			return a/b;
		}
};

int main()
{
	Calculator cal;
	cal.Init();
	cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
	cout<<"3.5 / 1.7 = "<<cal.Div(3.5, 1.7)<<endl;
	cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
	cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl;
	cal.ShowOpCount();
	return 0;
}