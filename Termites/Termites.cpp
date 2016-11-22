#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

void fuse(vector<int>& input)
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
	input.clear();
	for (int i = 1; i <= m; i++)
	{
		input.push_back(s[i]);
	}
	cout << endl;
}

int main()
{
	int x = 0;
	cin >> x;
	vector<int> v;
	vector<vector<int> > vs;
	for (int i = 0; i < x; i++)
	{
		int n;
		cin >> n;
		if(n == 0 && i != 0)
		{
			vs.push_back(v);
			v.clear();
			continue;
		}
		v.push_back(n);
	}
	vs.push_back(v);

	for (int i = 0; i < vs.size(); ++i)
	{
		fuse(vs[i]);
	}

	for (int i = 0; i < vs.size(); ++i)
	{
		for (int j = 0; j < vs[i].size(); ++j)
		{
			cout << vs[i][j] << " ";
		}
		cout << 0 << " ";
	}

	cin >> x;
}
