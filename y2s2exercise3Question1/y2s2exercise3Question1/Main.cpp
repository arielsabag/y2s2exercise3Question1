/*exercise3Question1
The program implement B tree that have treatments as its nodes
Data structure 2
exercise3Question1
205829500 Ariel sabag
09/01/2019
*/
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <functional>
#include "BTree.h"
#include "Treatment.h"
#include "BNode.h"

using namespace std;
bool checkDate(string t);
bool checkName(string name);

//=============================================================
void main()
{ 
	static bool ok = false;
	char ch;
	BTree<Treatment> bt;
	vector<string> physicians;
	Treatment tr,tr2;
	string str, str2;
	vector<Treatment> keys;
	Treatment *p;
	
	
	do
	{
		cout << "\nChoose one of the following" << endl;
		cout << "1: add a new Physician" << endl;
		cout << "2: add an open date and time for a physician" << endl;
		cout << "3: add a new Appointment " << endl;
		cout << "4: print patient calendar " << endl;
		cout << "5: print physician calendar " << endl;
		cout << "6: print date reminders" << endl;
		cout << "7: exit:" << endl;
		cin >> ch;

		switch (ch)
		{
		case '1':
			cout << "Enter physician name ";
			cin >> str;
			while (!ok)
			{
					if (checkName(str))//check if only letters
					{
						ok = true;
						break;
					}
					else
					{
						cout << "not valid name\n";
						cout << "Enter physician name ";
						cin >> str;
						break;
					}
			}
			physicians.push_back(str);//add
			break;
		case '2':
				cin >> tr;
			if (std::find(physicians.begin(), physicians.end(), tr.get_physician()) == physicians.end())//check if exist
				cout << "ERROR" << endl;
			else
				bt.insert(tr);//add
			break;
		case '3':
			cin >> tr; //fix a new treatment. read treatment details.
			p = bt.search(tr);
			if (p == NULL)
				cout << "ERROR" << endl;
			else
			{
				cout << "Enter patient name ";
				cin >> str;
				while (!ok)
				{
						if (checkName(str))
						{
							ok = true;
						}
						else
						{
							cout << "not valid name\n";
							cout << "Enter patient name ";
							cin >> str;
							break;
						}
				}
				if (p->get_patient() != "")//check if any patient already took this apointment 
					cout << "USED" << endl;
				else
				{
					p->set_patient(str);
					cout << "treatement for " << str << " fixed at " << p->get_date() << " time " << p->get_time() << endl;
				}
			}
			break;
		case '4':cout << "Enter patient name ";
			cin >> str;
			bt.printAllKeys([str](Treatment a) {return (a.get_patient() == str); });
			break;
		case '5':cout << "Enter physician name ";
			cin >> str;
			if (!checkName(str))
			{
				cout << "not valid name\n";
			}
			bt.printAllKeys([str](Treatment a) {return (a.get_physician() == str && a.get_patient() != ""); });
			break;
		case '6':cout << "Enter date ";
			cin >> str;
			if (checkDate(str))
			{
				bt.printAllKeys([str](Treatment a) {return (a.get_date() == str && a.get_patient() != ""); });
			}
			break;
		case '7':cout << "bye "; break;
		default: cout << "error "; ch = 0;  break;
		}//switch
	} while (ch != '7');


}

bool checkDate(string t)
{
	if (t.length() == 10)
	{
		if ((t[4] == '/') && (t[7] == '/'))
		{
			if (!(((t[0] >= 48) && (t[0] <= 57)) || ((t[1] >= 48) && (t[1] <= 57)) || ((t[2] >= 48) && (t[2] <= 57)) || ((t[3] >= 48) && (t[3] <= 57)) || ((t[5] >= 48) && (t[5] <= 57)) || ((t[6] >= 48) && (t[6] <= 57)) || ((t[8] >= 48) && (t[8] <= 57)) || ((t[9] >= 48) && (t[9] <= 57))))
			{
				cout << "Error: date input is not valid - enter only numbers\n start over\n ";
				return false;
			}
		}
		else
		{
			cout << "Error: date input is not valid - correct format is: yyyy/mm/dd\n start over\n ";
			return false;
		}
	}
	else
	{
		cout << "Error: date input is not valid\n start over\n";
		return false;
	}
}

bool checkName(string name)
{
	bool ok;
	for (int i = 0; i < name.length(); i++)//check if only letters
	{
		if (!(((name[i] >= 65) && (name[i] <= 90)) || ((name[i] >= 97)&(name[i] <= 122)) || ((name[i] == 32))))
		{
			return false;
		}
	}
	return true;
}