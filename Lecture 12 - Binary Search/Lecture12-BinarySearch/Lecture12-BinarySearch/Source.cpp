#include <vector>
#include <iostream>

using namespace std;

int binarySearch(vector<int> a, int left, int right, int x)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (x == a[mid])
			return mid;
		else if (x < a[mid])
			right = mid - 1;
		else if (x > a[mid])
			left = mid + 1;
	}
	return -1;
}

int binarySearch_Recursive(vector<int> a, int left, int right, int x)
{
	if (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return binarySearch_Recursive(a, left, mid - 1, x);
		return binarySearch_Recursive(a, mid + 1, right, x);
	}

	return -1;
}


int main()
{
	freopen("INPUT.INP", "rt", stdin);
	vector<int> a;
	int n, x, value;

	cin >> n >> x;

	for (int i = 0; i < n; i++)
	{
		cin >> value;
		a.push_back(value);
	}
	int result = binarySearch(a, 0, n - 1, x);
	cout << result;
	return 0;
}