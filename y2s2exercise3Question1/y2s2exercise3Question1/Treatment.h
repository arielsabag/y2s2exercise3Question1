#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <functional>

using namespace std;

class Treatment
{
public:
	Treatment();
	~Treatment();

	string get_physician();
	void UpdatePhysicianName(string newName);

	string get_patient();
	void set_patient(string newName);

	string get_date();
	void UpdateDate(string newDate);

	int get_time();
	void UpdateTime(int newTime);



	bool operator==(Treatment t);
	bool operator>(Treatment t);
	bool operator<(Treatment t);
	bool operator>=(Treatment t);
	friend istream& operator>>(istream& is, Treatment& t);
	friend ostream& operator<<(ostream& os, Treatment& t);

private:
	string physician;
	string patient;
	string date;

	int time;

};


istream& operator>>(istream& is, Treatment& t)
{
	cout << "Enter physician year-month-day hour";
	is >> t.physician >> t.date >> t.time;
	t.patient = string("");
	return is;
}
ostream& operator<<(ostream& os, Treatment& t)
{
	os << "Treatment details: physician: " << t.physician << " patient: " << t.patient
		<< " date: " << t.date << "," << t.time << endl;
	return os;
}

Treatment::Treatment()
{
	physician = nullptr;
	patient = nullptr;
	date = nullptr;
	time = 0;
}

Treatment::~Treatment()
{
}

string Treatment::get_physician() // return PhysicianName
{
	return this->physician;
}

void Treatment::UpdatePhysicianName(string newName)
{
	this->physician = newName;
}



string Treatment::get_patient() // return PatientName
{
	return this->patient;
}

void Treatment::set_patient(string newName)
{
	this->patient = newName;
}


string Treatment::get_date()
{
	return this->date;;
}

void Treatment::UpdateDate(string newDate) // updates date
{
	this->date = newDate;
}


int Treatment::get_time()
{
	return this->time;
}
void Treatment::UpdateTime(int newTime) // updates time
{
	this->time = newTime;
}

bool Treatment::operator==(Treatment t) // compere between 2 treatments
{
	if (this->get_physician() == t.get_physician())
	{
		if (this->get_date() == t.get_date())
		{
			if (this->get_time() == t.get_time())
			{
				return true;
			}
		}
	}
	return false;
}

bool Treatment::operator>(Treatment t)
{
	if (this->date > t.date)
	{
		return true;
	}
	else if (this->date < t.date)
	{
		return false;
	}
	else
	{
		if (this->time > t.time)
		{
			return true;
		}
		else if ((this->time) < (t.time))
		{
			return false;
		}
	}
}
bool Treatment::operator<(Treatment t)
{
	if (((*this) > t) || ((*this) == t))
	{
		return false;
	}
	return true;
}

bool Treatment::operator>=(Treatment t)
{
	if (((*this) < t))
	{
		return false;
	}
	return true;
}
