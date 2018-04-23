#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

struct Info
{
	string password;
	bool loggedIn = false;
};


int main()
{
	freopen("INPUT.INP", "rt", stdin);
	
	int n;
	cin >> n;
	cin.ignore(1);

	map<string, Info> m;
	map<string, Info>::iterator it;


	for (int i = 0; i < n; i++)
	{
		string operation, uname;
		cin >> operation >> uname;

		if (operation == "register")
		{
			Info info;
			cin >> info.password;

			it = m.find(uname);
			if (it == m.end())
			{
				m[uname] = info;
				cout << "success: new user added" << endl;
			}
			else
			{
				cout << "fail: user already exists" << endl;
			}
			
		}
		
		if (operation == "login")
		{
			Info info;
			cin >> info.password;

			it = m.find(uname);
			if (it == m.end())
			{
				cout << "fail: no such user" << endl;
			}
			else
			{
				if (it->second.password != info.password)
				{
					cout << "fail: incorrect password" << endl;
				}
				else if (it->second.loggedIn)
				{
					cout << "fail: already logged in" << endl;
				}
				else
				{
					cout << "success: user logged in" << endl;
					it->second.loggedIn = true;
				}
			}
		}
		
		if (operation == "logout")
		{
			it = m.find(uname);
			if (it == m.end())
			{
				cout << "fail: no such user" << endl;
			}
			else
			{
				if (!it->second.loggedIn)
				{
					cout << "fail: already logged out" << endl;
				}
				else
				{
					cout << "success: user logged out" << endl;
					it->second.loggedIn = false;
				}
			}
		}
	}

	return 0;
}