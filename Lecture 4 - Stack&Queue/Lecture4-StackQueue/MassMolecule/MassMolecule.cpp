#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include<string>
using namespace std;


int mass(char c)
{
	if (c == 'H')
		return 1;
	if (c == 'C')
		return 12;
	if (c == 'O')
		return 16;
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);

	string formula; formula
	stack<string> st;

	getline(cin, formula);


	for (int k = 0; k < formula.length(); k++)
	{
		if (isalpha(formula[k]))
		{
			st.push(to_string(mass(formula[k])));
		}
		else if (formula[k] == '(')
			st.push(string() + formula[k]);
			
		else if(formula[k] == ')')
		{
			int sum = 0;

			while (true)
			{
				sum += stoi(st.top());
				st.pop();

				if (st.top() == "(")
				{
					st.pop();
					break;
				}
			}
			st.push(to_string(sum));
		}
		else if(isdigit(formula[k]))
		{
			if (st.top() != ")")
			{
				int tmp = stoi(st.top()) * stoi(string() + formula[k]);
				st.pop();
				st.push(to_string(tmp));
			}
		}
	}

	int ans = 0;
	while (!st.empty())
	{
		ans += stoi(st.top());
		st.pop();
	}

	cout << ans << endl;
	return 0;
}