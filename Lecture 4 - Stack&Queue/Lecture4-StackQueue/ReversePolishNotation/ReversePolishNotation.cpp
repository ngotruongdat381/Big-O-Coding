#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include<string>
using namespace std;


int main()
{
	freopen("INPUT.INP", "rt", stdin);

	int n;
	cin >> n;
	cin.ignore(1);
	string expression;
	stack<char> opt;

	for (int i = 0; i < n; i++)
	{
		getline(cin, expression);

		for (int k = 0; k < expression.length(); k++)
		{
			if (isalpha(expression[k]))
			{
				cout << expression[k];
			}
			else if (!isdigit(expression[i]))
			{
				opt.push(expression[k]);
			}
			
			if (opt.top() == ')')
			{
				opt.pop();

				while (true)
				{
					if (opt.top() == '(')
					{
						opt.pop();
						break;
					}
					cout << opt.top();
					opt.pop();
				}
			}
		}
		cout << endl;
	}

	return 0;
}