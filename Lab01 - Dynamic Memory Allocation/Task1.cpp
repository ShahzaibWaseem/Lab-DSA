#include <iostream>
using namespace std;

int main(void)
{
	int* salary = new int[20];
	int i;

	for (i = 0; i < 20; ++i)
	{
		cout << "Enter Salary: ";
		cin >> salary[i];
	}
	for (i = 0; i < 20; ++i)
		salary[i] = salary[i] + salary[i] / (i + 1);

	delete [] salary;
	return 0;
}