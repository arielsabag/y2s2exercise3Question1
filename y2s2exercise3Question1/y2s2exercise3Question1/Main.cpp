#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <functional>
#include "BTree.h"
#include "Treatment.h"
#include "BNode.h"

using namespace std;

//=============================================================
void main()
{ 

	char ch;
	BTree<Treatment> bt;
	vector<string> physicians;
	Treatment tr, tr2;
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
			physicians.push_back(str);
			break;
		case '2':cin >> tr;
			if (std::find(physicians.begin(), physicians.end(), tr.get_physician()) == physicians.end())
				cout << "ERROR" << endl;
			else
				bt.insert(tr);
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

				if (p->get_patient() != "")
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
			bt.printAllKeys([str](Treatment a) {return (a.get_physician() == str && a.get_patient() != ""); });
			break;
		case '6':cout << "Enter date ";
			cin >> str;
			bt.printAllKeys([str](Treatment a) {return (a.get_date() == str && a.get_patient() != ""); });
			break;
		case '7':cout << "bye "; break;
		default: cout << "error ";  break;
		}//switch
	} while (ch != '7');

}