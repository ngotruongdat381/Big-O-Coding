#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
using namespace std;

#define maxn 200
int a[maxn];

bool checkPangram(string &str)
{
	vector<bool> mark(26, false);

	int index;

	for (int i = 0; i<str.length(); i++)
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			index = str[i] - 'A';

		else if ('a' <= str[i] && str[i] <= 'z')
			index = str[i] - 'a';

		mark[index] = true;
	}

	for (int i = 0; i <= 25; i++)
	if (mark[i] == false)
		return (false);

	return (true);

}

int main()
{
	freopen("INPUT.INP", "rt", stdin);

	int n;
	string s;

	cin >> n;

	//if (n < 26)
	//{
	//	cout << "NO";
	//	return 0;
	//}

	//cin.ignore(1);
	//getline(cin, s);

	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i]))
		{
			s[i] = tolower(s[i]);
			a[s[i]]++;
		}
	}


	for (int i = 'a'; i <= 'z'; i++)
	{
		if (a[i] == 0)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}