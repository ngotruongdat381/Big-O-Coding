#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
using namespace std;


int main()
{
	freopen("INPUT.INP", "rt", stdin);

	string s, t, ans;
	bool accepted = false;

	getline(cin, s);
	getline(cin, t);
	ans = s;

	for (int i = 0; i < s.length(); i++)
	{
		ans[i] = (char)((s[i] + t[i]) / 2);
		
		if ((s[i] < t[i] - 1))
		{
			accepted = true;
		}
		else if (s[i] < t[i] && i < s.length() - 1)		
		{
			accepted = true;
			i++;
			ans[i] = s[i] + 1;
		}
	}

	if (accepted)
		cout << ans;
	else
		cout << "No such string";

	
	return 0;
}