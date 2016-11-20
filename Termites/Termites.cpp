#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int termites(vector<int> &input)
{
	int m = 0;
	vector<int> s(input.size() * 2);
	for (int i = 0; i < input.size(); i++)
	{
		m++;
		s[m] = input[i];
		while (m >= 3 && s[m - 2] <= s[m - 1] && s[m - 1] >= s[m])
		{
			s[m - 2] = s[m - 2] - s[m - 1] + s[m];
			m -= 2;
		}
	}
	int value = 0;
	int sign = 1;
	int i = 1;
	int j = m;
	while (i <= j)
	{
		if (s[i] >= s[j]) {
			value = value + sign * s[i];
			i++;
		}
		else {
			value = value + sign * s[j];
			j--;
		}
		sign = -sign;
	}
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	return value;
}

int main()
{
	int x = 0;
	//cin >> x;
	vector<int> input;
	/*for (int i = 0; i < x; i++)
	{
		int n;
		cin >> n;
		input[i] = n;
	}*/
	input.push_back(5);
	input.push_back(7);
	input.push_back(10);
	input.push_back(6);
	input.push_back(9);
	input.push_back(9);
	input.push_back(1);
	input.push_back(7);
	input.push_back(11);
	input.push_back(8);

	/*for (int i = 0; i < input.size(); i++)
	{
		cout << input[i] << " ";
	}*/

	cout << termites(input) << endl;
	cin >> x;
}