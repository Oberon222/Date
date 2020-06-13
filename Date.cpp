#include "Date.h"
#include <fstream>
#include<iostream>
using namespace std;

int Date::GetDay()
{
	return this->day;
}

int Date::GetMonth()
{
	return this->month;
}

int Date::GetYar()
{
	return this->yar;
}

int Date::GetDaysInMonth()
{
	return daysInMonth;
}

void Date::SetDay(int day)
{
	if (day >= 0) this->day = day;
}

void Date::SetMonth(int month)
{
	if (month >= 0 && month<=12) this->day = day;

}

void Date::SetYar(int yar)
{
	if (yar >= 0) this->yar = yar;
}



int Date::NumbDaysInMonth()
{
	if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12) {
		return daysInMonth = 31;
	}
	else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) {
		return daysInMonth = 30;
	}

	else if (this->yar % 4 == 0 && this->month == 2) {
		 return daysInMonth = 29;
	}
	else
		return daysInMonth = 28;
}

void Date::Print() const
{
	cout << "Day: " << this->day;
	cout << " Month: " << this->month;
	cout << " Yar: " << this->yar << endl;
}

Date Date::operator+=(int numbDays)
{
	int resDays = this->day + numbDays;

	if (resDays < daysInMonth) {
		this->day = resDays;
	}

	else if (resDays > daysInMonth && this->month < 12) {
			this->day = resDays - daysInMonth;
			this->month++;
		
		
	}
	else if (resDays > daysInMonth && this->month == 12) {
			this->day = resDays - daysInMonth;
			this->month = 1;
			this->yar++;
	}
	return *this;
}

Date Date::operator-=(int numbDays)
{
	int resDays = this->day - numbDays;
	if (resDays > 0) {
		this->day = resDays;
	}
	else if (resDays <= 0 && this->month > 1) {
		this->day = daysInMonth + resDays; // + бо resDays може бути в≥д'Їмним;
		this->month--;
		
	}
	else if (resDays <= 0 && this->month == 1) {
		this->day = daysInMonth + resDays;
		this->month = 12;
		this->yar--;
	}
	return *this;
}

Date Date::operator()(int numbDays) // додаЇ певну к≥льк≥сть дн≥в
{
	int resDays = this->day + numbDays;

	if (resDays < daysInMonth) {
		this->day = resDays;
	}

	else if (resDays > daysInMonth && this->month < 12) {
		this->day = resDays - daysInMonth;
		this->month++;
	}

	else if (resDays > daysInMonth && this->month == 12) {
		this->day = resDays - daysInMonth;
		this->month = 1;
		this->yar++;
	}
	return *this;
}

Date Date::operator()(int numbDays, int numbMonths) // додаЇ певну к≥льк≥сть дн≥в та м≥с€ц≥в
{
	int resDays = this->day + numbDays;
	int resMonths = this->month + numbMonths;

	if (resDays < daysInMonth && resMonths <= 12) {
		this->day = resDays;
		this->month = resMonths;

	}

	else if (resDays > daysInMonth && resMonths < 12) {
		this->day = resDays - daysInMonth;
		this->month++;
	}

	else if (resDays > daysInMonth && resMonths == 12) {
		this->day = resDays - daysInMonth;
		this->month = 1;
		this->yar++;
	}

	return *this;
}

Date Date::operator()(int numbDays, int numbMonths, int numbYears) // додаЇ певну к≥льк≥сть дн≥в, м≥с€ц≥в та рок≥в
{
	int resDays = this->day + numbDays;
	int resMonths = this->month + numbMonths;
	int resYears = this->yar + numbYears;

	if (resDays < daysInMonth && resMonths < 12) {
		this->day = resDays;
		this->month = resMonths;
		this->yar = resYears;
	}

	else if (resDays > daysInMonth && resMonths < 12) {
		this->day = resDays - daysInMonth;
		this->month++;
		this->yar = resYears;
	}
	else if (resDays > daysInMonth && resMonths == 12) {
		this->day = resDays - daysInMonth;
		this->month=1;
		this->yar++;
	}
	return Date();
}

bool operator!=(const Date& p1, const Date& p2)
{
	return (p1.yar != p2.yar || p1.month != p2.month || p1.day != p2.day);
}

bool operator==(const Date& p1, const Date& p2)
{
	return (p1.yar == p2.yar && p1.month == p2.month && p1.day == p2.day);
}

bool operator>(const Date& p1, const Date& p2)
{
	return (p1.yar > p2.yar || p1.month > p2.month || p1.day > p2.day);
}

bool operator<(const Date& p1, const Date& p2)
{
	return (p1.yar < p2.yar || p1.month < p2.month || p1.day < p2.day);
}

//ofstream& operator<<(ofstream& fout, const Date& p1)
//{
//	ofstream fout;
//	fout.open("Date.txt");
//	bool isOpen = fout.is_open();
//	if (!isOpen) {
//		cout << "Error" << endl;
//	}
//
//	fout << p1.day << endl;
//	fout << p1.month << endl;
//	fout << p1.yar << endl;
//
//	return fout;
//}

//ofstream& operator>>(ifstream& fin, Date& p1)
//{
//	ifstream fin;
//	fin.open("Date.txt");
//	if (!fin.is_open()) {
//		cout << "Error" << endl;
//	}
//
//	fin >> p1.day;
//	fin >> p1.month;
//	fin >> p1.yar;
//	return fin;
//}

Date operator++(Date& p1)
{
	if (p1.GetDay() < p1.GetDaysInMonth()) {
		p1.GetDay() + 1;
	}
	else if (p1.GetDay() == p1.GetDaysInMonth() && p1.GetMonth()<12) {
		p1.SetDay(1);
		p1.GetMonth() + 1;
	}
	else if (p1.GetDay() == p1.GetDaysInMonth() && p1.GetMonth() == 12) {
		p1.SetDay(1);
		p1.SetMonth(1);
		p1.GetYar() + 1;
	}

	return p1;
}

Date operator--(Date& p1)
{
	if (p1.GetDay() > 1) {
		p1.GetDay()-1;
	}
	else if (p1.GetDay() == 1 && p1.GetMonth() > 1) {
		p1.GetMonth() - 1;
		p1.SetDay(p1.GetDaysInMonth());
	}

	else if (p1.GetDay() == 1 && p1.GetMonth() == 1) {
		p1.GetYar() - 1;
		p1.SetMonth(p1.GetMonth()-1);
		p1.SetDay(p1.GetDaysInMonth());
	}
	return Date();
}
