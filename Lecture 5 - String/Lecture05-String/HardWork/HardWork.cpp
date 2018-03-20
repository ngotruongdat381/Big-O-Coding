#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
using namespace std;

string normalize(string str)
{
	string res = "";

	for (int i = 0; i < str.length(); i++)
	{
		if (isalpha(str[i]))
		{
			res += tolower(str[i]);
		}
	}
	return res;
}

bool comp(string a, string b) { return a.length() > b.length(); }


int main()
{
	freopen("INPUT.INP", "rt", stdin);

	vector<string> str;
	
	for (int i = 0; i < 3; i++)
	{
		string s;
		getline(cin, s);
		str.push_back(normalize(s));
	}

	sort(str.begin(), str.end(), comp);
	int n;

	cin >> n;
	cin.ignore(1);

	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		s = normalize(s);
		
		for (int i = 0; i < 3; i++)
		{
			int pos = s.find(str[i]);

			if (pos == -1)
				break;
			
			s.replace(pos, str[i].length(), "0");
		}

		if (s == "000")
			cout << "ACC" << endl;
		else
			cout << "WA" << endl;
	}
	return 0;
}