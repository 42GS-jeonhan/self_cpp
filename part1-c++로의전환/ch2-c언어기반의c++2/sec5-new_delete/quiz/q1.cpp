#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
	Point *ret = new Point;
	ret->xpos = p1.xpos+p2.xpos;
	ret->ypos = p1.ypos+p2.ypos;
	return *ret;
}

int main()
{
	Point *p1 = new Point;
	p1->xpos = 1;
	p1->ypos = 10;
	// Point &p1_ref = *p1;

	Point *p2 = new Point;
	p2->xpos = 2;
	p2->ypos = 20;
	// Point &p2_ref = *p2;

	// Point &ret = PntAdder(p1_ref, p2_ref);
	Point &ret = PntAdder(*p1, *p2);
	cout<<ret.xpos<<' '<<ret.ypos<<endl;

	delete p1;
	delete p2;
	delete &ret;
	return 0;
}