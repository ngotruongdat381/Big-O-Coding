#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <string>
using namespace std;

#define MAX 200005
#define INF 1e17

string normalized(string s)
{
	string res = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i]))
		{
			res += tolower(s[i]);
		}
	}
	return res;
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	set<string> s;

	string str;
	while (cin >> str)
	{
		string tmp = "";
		for (int i = 0; i < str.length(); i++)
		{
			if (isalpha(str[i]))
			{
				tmp += tolower(str[i]);
			}
			else if (!isalpha(str[i]) && tmp != "")
			{
				s.insert(tmp);
				tmp = "";
			}
		}

		if (tmp != "")
			s.insert(tmp);
	}

	std::set<string>::iterator it;
	for (it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << endl;

	}
	return 0;
}