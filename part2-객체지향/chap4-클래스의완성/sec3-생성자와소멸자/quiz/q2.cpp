#include <iostream>
#include <cstring>

namespace COMP_POS
{
	enum POSITION
	{
		CLERK,
		SENIOR,
		ASSIST,
		MANAGER
	};
}

class NameCard
{
	
	private:
		char *name;
		char *company;
		char *phone_num;
		COMP_POS::POSITION position;
	public:
		NameCard(const char *n, const char *c, const char *p, COMP_POS::POSITION pos)
		{
			name = new char[std::strlen(n) + 1];
			std::strcpy(name, n);
			company = new char[std::strlen(c) + 1];
			std::strcpy(company, c);
			phone_num = new char[std::strlen(p) + 1];
			std::strcpy(phone_num, p);
			position = pos;
		}
		~NameCard()
		{
			delete []name;
			delete []company;
			delete []phone_num;
		}
		void ShowNameCardInfo()
		{
			std::cout<<"이름: "<<name<<std::endl;
			std::cout<<"회사: "<<company<<std::endl;
			std::cout<<"전화번호: "<<phone_num<<std::endl;
			std::cout<<"직급: ";
			if(position==COMP_POS::CLERK)
				std::cout<<"사원";
			if(position==COMP_POS::SENIOR)
				std::cout<<"주임";
			if(position==COMP_POS::ASSIST)
				std::cout<<"대리";
			if(position==COMP_POS::MANAGER)
				std::cout<<"과장";
			std::cout<<std::endl<<std::endl;
		}
};

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}
