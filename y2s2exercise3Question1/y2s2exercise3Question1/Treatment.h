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

	string get_time();
	void UpdateTime(int newTime);
	bool checkValidation(Treatment& t);


	bool operator==(Treatment t);
	bool operator>(Treatment t);
	bool operator<(Treatment t);
	bool operator>=(Treatment t);
	friend  istream& operator>>(istream& is, Treatment& t);
	friend ostream& operator<<(ostream& os, Treatment& t);
private:
	string physician;
	string patient;
	string date;
    string time;




};


 istream& operator>>(istream& is, Treatment& t)//input operator
{
	
	cout << "Enter physician name , a date in the following format: YYYY/MM/DD , a time in the following format: HH:MM ";
	is >> t.physician >> t.date >> t.time;
	bool ok = false;
	while (!ok)
	{
		if (t.checkValidation(t))// check if input ok
		{
			ok = true;
		}
		else
		{
			cout << "Enter physician name , a date in the following format: YYYY/MM/DD , a time in the following format: HH:MM ";
			is >> t.physician >> t.date >> t.time;
		}
	}
	t.patient = string("");
	return is;
}
ostream& operator<<(ostream& os, Treatment& t)// output operator for treatment
{
	os << "Treatment details: physician: " << t.physician << " patient: " << t.patient
		<< " date: " << t.date << "," << t.time << endl;
	return os;
}

Treatment::Treatment()
{
	physician = "";
	patient = "";
	date = "";
	time = "";
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


string Treatment::get_time()
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

bool Treatment::checkValidation(Treatment& t)// check if all fields are valid
{
	if (t.date.length() == 10)//check length
	{
		if ((t.date[4] == '/') && (t.date[7] == '/'))//check format -> yyyy/mm/dd
		{
			// check there only numbers and sleshes
			if (!(((t.date[0] >= 48) && (t.date[0] <= 57)) || ((t.date[1] >= 48) && (t.date[1] <= 57)) || ((t.date[2] >= 48) && (t.date[2] <= 57)) || ((t.date[3] >= 48) && (t.date[3] <= 57)) || ((t.date[5] >= 48) && (t.date[5] <= 57)) || ((t.date[6] >= 48) && (t.date[6] <= 57)) || ((t.date[8] >= 48) && (t.date[8] <= 57)) || ((t.date[9] >= 48) && (t.date[9] <= 57))))
			{
				cout << "Error: date input is not valid - enter only numbers\n start over ";
				return false;
			}
		}
		else
		{
			cout << "Error: date input is not valid - correct format is: yyyy/mm/dd\n start over ";
			return false;
		}
	}
	else
	{
		cout << "Error: date input is not valid\n start over";
		return false;
	}
	if (t.time.length() == 5)// check length and so on
	{
		if (t.time[2] == 58)
		{
			if (!(    ((t.time[0] >= 48) && (t.time[0] <= 57))    &&    ((t.time[1] >= 48) && (t.time[1] <= 57))     &&     ((t.time[3] >= 48) && (t.time[3] <= 57))    &&    ((t.time[4] >= 48) && (t.time[4] <= 57))    ))
			{
				cout << "Error: time input is not valid - enter only numbers\n start over ";
				return false;
			}
		}
		else
		{
			cout << "Error: time input is not valid - correct format is: hh:mm/n start over ";
			return false;
		}
	}
	else
	{
		cout << "Error: time input is not valid\n start over";
		return false;
	}
	return true;
}