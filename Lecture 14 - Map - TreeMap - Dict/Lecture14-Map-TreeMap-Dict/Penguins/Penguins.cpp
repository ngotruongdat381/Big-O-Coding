#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	cin.ignore(1);

	map<string, int> m;
	map<string, int>::iterator it;
	string name;

	for (int i = 0; i < n; i++)
	{
		
		getline(cin, name);
		
		m[name]++;

		//it = m.find(name);

		//if (it == m.end())
		//	m[name] = 1;
		//else
		//	m[name]++;
	}

	pair<string, int> max(name, m[name]);

	for (it = m.begin(); it != m.end(); it++)
	{
		if (max.second < it->second)
			max = *it;
	}

	cout << max.first;

	return 0;
}