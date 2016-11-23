#include <iostream>
#include <vector>
#include <algorithm>

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

void worthless(vector<int>& input, int& value, int n)
{
	for (int i = input.size() - 1; i >= 0; i -= 2)
	{
		if (i >= 1 && input[i] >= input[i - 1])
		{
			value += pow(-1, n) * (input[i - 1] - input[i]);
			input.erase(input.begin() + i - 1, input.begin() + i + 1);
		}
	}
}

int main()
{
	int value = 0;
	int x = 0;
	int n = 0;
	cin >> x;
	vector<int> v;
	vector<vector<int>> vs;
	for (int i = 0; i < x; i++)
	{
		int n;
		cin >> n;
		if (n == 0 && i != 0)
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
		n += vs[i].size();
	}
	
	//vector<int> temp;
	//temp.push_back(4);
	//temp.push_back(3);
	//temp.push_back(7);
	////temp.push_back(6);
	//reverse(temp.begin(), temp.end());

	//worthless(temp, value, n);
	//for (int i = 0; i < temp.size(); ++i)
	//{
	//	cout << temp[i];
	//}

	/*worthless(vs[0], value, n);
	worthless(vs[vs.size() - 1], value, n);*/


	//for (int i = 0; i < vs.size(); ++i)
	//{
	//	for (int j = 0; j < vs[i].size(); ++j)
	//	{
	//		cout << vs[i][j];
	//	}
	//	cout << " ";
	//}

	cin >> x;
}
