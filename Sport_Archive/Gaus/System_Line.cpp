#include <iostream>
#include <vector>
#include <algorithm>

#define matrix vector<vector<double>>

using namespace std;

void dec(vector<double> &v1, vector<double> &v2, double a)
{
	for (int i = 0; i < v1.size(); i++)
		v2[i] -= a*v1[i];
}

int main()
{
	int n;
	cin >> n;
	matrix v(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			double a; cin >> a;
			v[i].push_back(a);
		}
	}

	int k = 0;

	for (int i = 0; i < n; i++)
	{
		double max = -1e9, pos = 0;

		for (int j = i; j < n; j++)
		{
			if (v[j][i] > max && v[j][i] != 0)
			{
				max = v[j][i];
				pos = j;
			}
		}

		if (max == 0)
		{
			continue;
		}

		swap(v[k], v[pos]);
		double z = v[k][i];

		for (int l = 0; l < n + 1; l++)
		{
			v[k][l] /= z;
		}

		for (int j = 0; j < n; j++)
		{
			if (j != k)
			{
				dec(v[k], v[j], v[j][i]);
			}
		}

		k++;
	}

	vector<double> res(n);

	for (int i = 0; i < n; i++)
	{
		int pos = -1;
		for (int j = i; j < n; j++)
		{
			if (v[i][j] > 0)
			{
				pos = j;
				break;
			}
		}

		if (pos != -1)
		{
			res[pos] = v[i][n];
		}
	}

	for (int i = 0; i < res.size(); i++)
	{
		if (res[i] > 0)
			res[i] += 0.5;
		else
			res[i] -= 0.5;
		cout << (int)res[i] << " ";
	}
}