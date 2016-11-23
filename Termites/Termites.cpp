#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

void fuse(vector<long long>& input)
{
	long long m = 0;
	vector<long long> s(input.size() * 2);
	for (long long i = 0; i < input.size(); i++)
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
	for (long long i = 1; i <= m; i++)
	{
		input.push_back(s[i]);
	}
}

void worthless(vector<long long>& input, long long& value, int n)
{
	if (input.size() <= 0) return;
	for (long long i = input.size() - 1; i >= 0; i -= 2)
	{
		if (i >= 1 && input[i] >= input[i - 1])
		{
			value += pow(-1.0, double(n)) * (input[i - 1] - input[i]);
			input.erase(input.begin() + i - 1, input.begin() + i + 1);
		}
	}
}

int main()
{
	long long value = 0;
	long long x = 0;
	int n = 0;
	long long s = 0;
	cin >> x;
	vector<long long> v;
	vector<vector<long long> > vs;
	for (long long i = 0; i < x; i++)
	{
		long long n;
		cin >> n;
		s += n;
		if (n == 0)
		{
			vs.push_back(v);
			v.clear();
			continue;
		}
		v.push_back(n);
	}
	vs.push_back(v);

	for (long long i = 0; i < vs.size(); ++i)
	{
		fuse(vs[i]);
	}

	for (long long i = 0; i < vs.size(); ++i)
	{
		n += vs[i].size();
	}

	reverse(vs[0].begin(), vs[0].end());
	worthless(vs[0], value, n);
	worthless(vs[vs.size() - 1], value, n);
	reverse(vs[0].begin(), vs[0].end());

	vector<long long> last;

	for (long long i = 0; i < vs.size(); ++i)
	{
		for (long long j = 0; j < vs[i].size(); ++j)
		{
			last.push_back(vs[i][j]);
		}
	}

	sort(last.begin(), last.end());
	reverse(last.begin(), last.end());
	long long sign = 1;
	for (long long i = 0; i < last.size(); ++i)
	{
		value += sign * last[i];
		sign = -sign;
	}

	cout << (s + value) / 2 << " " << (s - value) / 2 << endl;
	cin >> x;
}
