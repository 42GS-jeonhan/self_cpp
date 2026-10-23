#include <iostream>

void swap(int *v1, int *v2)
{
	int tmp;
	tmp = *v1;
	*v1 = *v2;
	*v2 = tmp;
}

void swap(char *v1, char *v2)
{
	char tmp;
	tmp = *v1;
	*v1 = *v2;
	*v2 = tmp;
}

void swap(double *v1, double *v2)
{
	double tmp;
	tmp = *v1;
	*v1 = *v2;
	*v2 = tmp;
}

int main()
{
	int num1=20, num2=30;
	swap(&num1, &num2);
	std::cout<<num1<<' '<<num2<<std::endl;

	char ch1='A', ch2='Z';
	swap(&ch1, &ch2);
	std::cout<<ch1<<' '<<ch2<<std::endl;

	double dbl1=1.111, dbl2=5.555;
	swap(&dbl1, &dbl2);
	std::cout<<dbl1<<' '<<dbl2<<std::endl;
	return 0;
}
