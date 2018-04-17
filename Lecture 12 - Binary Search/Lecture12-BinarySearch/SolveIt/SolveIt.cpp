#include<iostream> 
#include <list> 
#include <stack> 
#include <vector>
#include <algorithm>
#include <math.h>   
#include <iomanip>
using namespace std;


#define MAX 100005
double a[MAX];

vector<int> v;
int p, q, r, s, t, u;

double equation(double x)
{
	double f = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;

	return f;
}

int binarySearch(double a[], int left, int right)
{
	double direction;

	if (equation(1) >= equation(0))
	{
		direction = 1;
	}
	else
	{
		direction = -1;
	}

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		double res = equation(a[mid]);
		if (res < 0.0005 && equation(a[mid]) > -0.0005)
				return mid;
		else if (res*direction > 0)
			right = mid - 1;
		else if (res*direction < 0)
			left = mid + 1;
	}
	return -1;
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);

	for (int i = 0; i <= 100000; i++)
	{
		a[i] = i*0.00001;
	}

	while (cin >> p)
	{
		cin >> q >> r >> s >> t >> u;

		int result = binarySearch(a, 0, 100000);

		if (result == -1)
			cout << "No solution" << endl;
		else
		{
			std::cout << std::fixed;
			std::cout << std::setprecision(4);
			int tmp = result*0.1;

			cout << double(tmp)*0.0001 << endl;
		}
	}
	return 0;
}