#pragma once
#include <fstream>
#include<iostream>
using namespace std;


enum MONTHS
{	JANUARY=1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER, 
	NOVEMBER,
	DECEMBER};
class Date
{
	int day;
	int month;
	int yar;
	int daysInMonth;
	
	int NumbDaysInMonth();

public:
	Date()
	{
		day = 0;
		month=0;
		yar = 0;
		daysInMonth = 0;
	}

	Date(int day, int month, int yar)
	{
		this->day = day;
		this->month = month;
		this->yar = yar;
		daysInMonth = NumbDaysInMonth();
		
	}

	int GetDay();
	int GetMonth();
	int GetYar();
	int GetDaysInMonth();

	void SetDay(int day);
	void SetMonth(int month);
	void SetYar(int yar);


	void Print() const;

	friend bool operator!=(const Date& p1, const Date& p2);
	friend bool operator==(const Date& p1, const Date& p2);
	friend bool operator>(const Date& p1, const Date& p2);
	friend bool operator<(const Date& p1, const Date& p2);

	Date operator +=(int numb);
	Date operator -=(int numb);

	Date  operator()(int numbDays);
	Date  operator()(int numbDays, int numbMonths);
	Date  operator()(int numbDays, int numbMonths, int numbYears);




	friend ofstream& operator<<(ofstream& fout, const Date& p1);
	friend ifstream& operator>>(ifstream& fin, Date& p1);
};

	Date operator++(Date& p1);

	Date operator--(Date& p1);

