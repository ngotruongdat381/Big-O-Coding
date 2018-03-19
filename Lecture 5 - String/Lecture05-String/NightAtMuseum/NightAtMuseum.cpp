#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
using namespace std;


int main()
{
	freopen("INPUT.INP", "rt", stdin);

	string str;

	getline(cin, str);
	
	int c = 97;		// 'a'
	int sum = 0;

	for (int i = 0; i < str.length(); i++)
	{
		sum += min(26 - abs(str[i] - c), abs(str[i] - c));
		c = str[i];
	}

	
	cout << sum << endl;
	return 0;
}