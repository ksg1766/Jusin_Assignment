#include <iostream>
using namespace std;

void main()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	char c[10][10];
	int count = 0;
	strcpy_s(c[count], 10, "temp");
	count++;

	for (int i = 0; i < count; i++)
		cout << c[i] << '\n';
}