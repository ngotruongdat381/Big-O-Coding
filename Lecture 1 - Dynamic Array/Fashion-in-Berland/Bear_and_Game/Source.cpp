#include<vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void main()
{
	int n;
	string input;

	cin >> n;
	cin.ignore();
	getline(cin, input);

	int interesting_minute;
	istringstream is(input);
	int previous_interesting_minute = 0;

	while (is >> interesting_minute) {
		if (interesting_minute - previous_interesting_minute > 15)
		{
			cout << previous_interesting_minute + 15;
			return;
		}
		previous_interesting_minute = interesting_minute;
	}

	cout << "90";

	//vector<int> a;
	//int n;
	//a.push_back(0);
	//cin >> n;
	//for (int i = 0; i < n; i++)
	//{
	//	int minute;
	//	cin >> minute;
	//	a.push_back(minute);
	//}
	//a.push_back(90);

	//for (int i = 0; i < a.size() - 1; i++)
	//{
	//	if (a[i + 1] - a[i] > 15)
	//	{
	//		cout << a[i] + 15;
	//		return;
	//	}
	//}
	//cout << 90;
	//return;
}