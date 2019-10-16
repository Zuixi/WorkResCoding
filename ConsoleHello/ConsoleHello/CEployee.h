#pragma once


#include"pch.h"
#include<string>
#include<string.h>
#include<cmath>

// 职员类，作为基类
class Employee
{
public:
	Employee();
	~Employee();
	Employee(const char* name)
	{
		strcpy(m_name, name);
	}
private:
	char m_name[30];
};

Employee::Employee()
{
}

Employee::~Employee()
{
}
// 时薪员工
class CWage:public Employee
{
private:
	float m_wage;
	float m_hours;

public:
	CWage();
	CWage(const char* name) :Employee(name)
	{
		m_wage = 250.0;
		m_hours = 40.0;
	}

	void SetSage(float wage)
	{
		m_wage = wage;
	}
	void SetHours(float hours)
	{
		m_hours = hours;
	}
	float ComputePay()
	{
		return m_wage * m_hours;
	}

};

// 销售员也是一种时薪员工
class CSales :public CWage
{
private:
	float m_comm;
	float m_sale;

public:
	CSales(const char* name) :CWage(name)
	{
		m_comm = m_sale = 0.0;
	}

	void SetCommission(float comm)
	{
		m_comm = comm;
	}

	void SetSales(float sales)
	{
		m_sale = sales;
	}

	float ComputePay()
	{
		return CWage::ComputePay() + m_comm * m_sale;
	}
};


// 经理也是一种职员
class CManger :public Employee
{
private:
	float m_salary;

public:
	CManger(const char* name) :Employee(name) {
		m_salary = 1500.0;
	}

	void SetSalary(float salary)
	{
		m_salary = salary;
	}
	float ComputePay()
	{
		return m_salary;
	}
};
