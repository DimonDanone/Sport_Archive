#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	int inf = 1e9;

	int n;
	cin >> n;

	vector<vector<int>> d(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> d[i][j];
			if (d[i][j] == 0)
				d[i][j] = inf;
		}
	}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (d[i][j] != inf && d[j][i] != inf)
				res = 1;
		}

	cout << res;
}
