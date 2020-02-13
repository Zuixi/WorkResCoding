#pragma once

class MyTime
{
private:
	int hours;
	int minutes;
	int seconds;

public:
	MyTime();
	MyTime(int h, int m, int s);
	~MyTime();
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0, int s = 0);
	MyTime Sum(const MyTime& t) const;
	void show() const;

	friend MyTime operator*(double m, const MyTime& t);
};

