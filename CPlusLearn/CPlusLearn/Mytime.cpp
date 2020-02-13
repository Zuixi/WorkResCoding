#include "pch.h"
#include "Mytime.h"
#include <iostream>


MyTime::MyTime()
{
}

MyTime::MyTime(int h, int m, int s)
{
	hours = h;
	minutes = m;
	seconds = s;
}


MyTime::~MyTime()
{
}

void MyTime::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}


void MyTime::AddHr(int h)
{
	hours += h;
}

void MyTime::Reset(int h, int m, int s)
{
	hours = h;
	minutes = m;
	seconds = s;
}

MyTime MyTime::Sum(const MyTime & t) const
{
	MyTime sum;
	sum.seconds = seconds + t.seconds;
	sum.minutes = minutes + t.minutes + sum.seconds / 60;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	sum.seconds %= 60;
	return sum;

}

void MyTime::show() const {
	std::cout << hours << "hours £º" << minutes << "minutes : " << seconds << "seconds." << std::endl;
}

MyTime operator*(double m, const MyTime& t)
{
	MyTime result;
	long totalminutes = m * t.hours * 3600 + t.minutes * m * 60 + t.seconds * m;
	result.hours = totalminutes / 3600;
	result.minutes = (totalminutes - result.hours * 3600) / 60;
	result.seconds = totalminutes % 60;
	return result;
}
