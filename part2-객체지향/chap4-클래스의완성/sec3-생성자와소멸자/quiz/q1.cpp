#include <iostream>

class Point
{
	private:
		int xpos, ypos;
	public:
		Point(int x, int y):xpos(x),ypos(y){}
		// void Init(int x, int y)
		// {
		// 	xpos = x;
		// 	ypos = y;
		// }
		void ShowPointInfo() const
		{
			std::cout<<"["<<xpos<<", "<<ypos<<"]"<<std::endl;
		}
};

class Circle
{
	private:
		Point center;
		int radius;
	public:
		Circle(int x, int y, int r):center(x,y),radius(r){}
		// void Init(int x, int y, int r)
		// {
		// 	center.Init(x,y);
		// 	radius = r;
		// }
		void ShowCircleInfo(void)
		{
			std::cout<<"radius: "<<radius<<std::endl;
			center.ShowPointInfo();
		}
};

class Ring
{
	private:
		Circle inner;
		Circle outer;
	public:
		Ring(int i_x, int i_y, int i_r, int o_x, int o_y, int o_r)
		:inner(i_x, i_y, i_r), outer(o_x,o_y,o_r){}
		// void Init(int i_x, int i_y, int i_r, int o_x, int o_y, int o_r)
		// {
		// 	inner.Init(i_x, i_y, i_r);
		// 	outer.Init(o_x, o_y, o_r);
		// }
		void ShowRingInfo(void)
		{
			std::cout<<"Inner Circle Info..."<<std::endl;
			inner.ShowCircleInfo();
			std::cout<<"Outer Circle Info..."<<std::endl;
			outer.ShowCircleInfo();
		}
};

int main()
{
	// Ring ring;
	// ring.Init(1,1,4,2,2,9);
	Ring ring(1,1,4,2,2,9);
	ring.ShowRingInfo();
	return 0;
}