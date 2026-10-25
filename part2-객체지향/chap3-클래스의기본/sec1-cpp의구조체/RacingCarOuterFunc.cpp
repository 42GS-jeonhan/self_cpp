#include <iostream>
using namespace std;

namespace CAR_CONST
{
	enum
	{
		ID_LEN		=20,
		MAX_SPD		=200,
		FUEL_STEP	=2,
		ACC_STEP	=10,
		BRK_STEP	=10
	};
}

struct Car
{
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
	
	void ShowCarState();	//상태정보 출력
	void Accel();			//엑셀, 속도 증가
	void Break();			//브레이크, 속도 감소
}; // 함수 선언과 정의를 분리할 수 있음. 이를 통해 구조체 내부에 어떤 함수가 정의되는지 한눈에 파악할 수 있음
//함수 정의를 구조체 내부에 하면 인라인 처리하게 됨. 구조체 외부에서 정의하고 인라인 처리를 원하면 inline 키워드 사용 필요

void Car::ShowCarState()
{
	cout<<"소유자 ID: "<<gamerID<<endl;
	cout<<"연료량: "<<fuelGauge<<"%"<<endl;
	cout<<"현재속도: "<<curSpeed<<"km/h"<<endl<<endl;
}

void Car::Accel()
{
	if(fuelGauge<=0)
		return;
	else
		fuelGauge-=CAR_CONST::FUEL_STEP;
	
	if(curSpeed+CAR_CONST::ACC_STEP>=CAR_CONST::MAX_SPD)
	{
		curSpeed=CAR_CONST::MAX_SPD;
		return ;
	}
	curSpeed+=CAR_CONST::ACC_STEP;
}

void Car::Break()
{
	if(curSpeed<CAR_CONST::BRK_STEP)
	{
		curSpeed=0;
		return;
	}
	curSpeed-=CAR_CONST::BRK_STEP;
}

int main(void)
{
	Car run99={"run99", 100, 0};
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	Car sped77={"sped77", 100, 0};
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();
	return 0;
}