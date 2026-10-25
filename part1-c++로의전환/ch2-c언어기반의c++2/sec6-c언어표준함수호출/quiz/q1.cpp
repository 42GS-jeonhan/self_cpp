#include <iostream>
#include <cstring>

int main(void)
{
	char str1[100] = "Hello";
	char str2[100] = " World";
	char str3[100] = "";

	std::cout<<"str1 = "<<str1<<", len = "<<std::strlen(str1)<<std::endl;
	std::cout<<"str2 = "<<str2<<", len = "<<std::strlen(str2)<<std::endl;
	std::cout<<"str3 = "<<str3<<", len = "<<std::strlen(str3)<<std::endl;
	std::strcat(str1, str2);
	std::strcpy(str3, str1);
	std::cout<<"str1 = "<<str1<<", len = "<<std::strlen(str1)<<std::endl;
	std::cout<<"str2 = "<<str2<<", len = "<<std::strlen(str2)<<std::endl;
	std::cout<<"str3 = "<<str3<<", len = "<<std::strlen(str3)<<std::endl;
	std::cout<<std::strcmp(str3, str1)<<std::endl;
	std::cout<<std::strcmp(str3, str2)<<std::endl;
	return 0;
}