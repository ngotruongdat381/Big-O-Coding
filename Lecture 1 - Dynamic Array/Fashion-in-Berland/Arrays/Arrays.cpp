#include<vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void main()
{
	vector<int> A, B;

	int nA, nB, k, m;
	cin >> nA;
	cin >> nB;
	cin >> k;
	cin >> m;

	for (int i = 0; i < nA; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}

	for (int i = 0; i < nB; i++)
	{
		int b;
		cin >> b;
		B.push_back(b);
	}

	//compare the biggest number from k numbers of A and the smallest number from m numbers of B
	if (A[k - 1] < B[nB - m])
		cout << "YES";
	else
		cout << "NO";

}