#include<iostream.h>


//struct Point  struct缺省条件下所有数据成员是public，相反class缺省条件下数据成员private
class Point
{
public:
	int x;
	int y;
	void output(){
		cout<<x<<endl<<y<<endl;
	};
};

void main()
{
	Point pt;
	pt.x=5;
	pt.y=5;
//	cout<<pt.x<<endl<<pt.y<<endl;
	pt.output();
}