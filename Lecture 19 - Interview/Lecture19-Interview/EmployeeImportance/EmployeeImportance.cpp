#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;


class Employee {
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};

int get(Employee* ems[], int id) {

	int sum = ems[id]->importance;

	vector<int> subs = ems[id]->subordinates;
	if (subs.size() == 0)
		return sum;

	for (int i = 0; i < subs.size(); i++)
	{
		sum += get(ems, subs[i]);
	}
	return sum;
}


int getImportance(vector<Employee*> employees, int id) {
	Employee* ems[2000];

	for (int i = 0; i < employees.size(); i++)
	{
		ems[employees[i]->id] = employees[i];

	}

	int sum = get(ems, id);
	return sum;
}



int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int n;
	vector<int> list;
	while (cin >> n)
	{
		list.push_back(n);
	}

	repeatedNumber2(list);

	return 0;
}