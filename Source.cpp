#include <iostream>
using namespace std;
class base
{
	int a;
public :
	base()
	{
		cout << " base default constructor called" << endl;
		a = 0;
	}
	base(int h)
	{
		cout << "base parametrized constructor called" << endl;
		a = h;
	}
	void setbase(int k)
	{
		a = k;
	 }
	int getbase()
	{
		return a;
	}

};
class  date: virtual public base
{
private:
	int  day;
	int month;
	int year;

public:
	date()
	{
		cout << "date class default constructor called"<<endl;
		day = 0;
		month = 0;
		year = 0;

	}
	date(int d, int m, int y)
	{
		cout << "date class parmeerized constructor called" << endl;
		day = d;
		month = m;
		year = y;
	}
	void setdate(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}
	int getday()
	{
		return day;
	}
	int getmonth()
	{
		return month;
	}
	int getyear()
	{
		return year;
	}
};
class time: virtual public base
{
private:
	int h;
	int m;
	int s;
public:
	time()
	{
		cout << "time class default constructor called";
		cout << endl;
		h = 0;
		s = 0;
		m = 0;

	}
	time(int hours, int min, int second)
	{
		cout << " time class parameterized constructor called" << endl;
		h = hours;
		m = min;
		s = second;
	}
	void settime(int hours, int month, int second)
	{
		h = hours;
		m = month;
		s = second;

	}
	int gethour()
	{
		return h;
	}
	int getminute()
	{
		return m;
	}
	int getsecond()
	{
		return s;
	}
};
class datetime :public time, public date
{
	using base::setbase;
public:
	datetime():base()
	{
		cout << " date time default is called" << endl;

	}
	datetime(int a, int b, int c, int d, int e, int f):time(a,b,c),date(d,e,f),base(a)
	{
		cout << " date time parmetrized constructor called" << endl;
	}
	void displaydate()
	{
		cout << " date is ";
		cout << getsecond() << ":" << getminute() << ":" << gethour();

	}
	

};
int main()
{
	datetime f(6,8,9,8,7,6);
	


	f.displaydate();
	f.getmonth();
	f.setdate(30,7,9);
}