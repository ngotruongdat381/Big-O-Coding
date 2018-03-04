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

	int total = 0;
	int button;
	istringstream is(input);
	while (is >> button) {
		total += button;
	}

	if ((n > 1 && total == n - 1) || (n == 1 && total == 1))
		cout << "YES";
	else
		cout << "NO";

}