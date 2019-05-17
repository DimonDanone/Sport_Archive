/*
Дана матрица A размера n на n, заполненная нулями и единицами. Дан вектор b, размера n, заполненный нулями и единицами. Решите систему Ax?=?b, если все вычисления проходят по модулю 2.
*/

#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 5000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	vector<bitset<maxn>> v(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a; cin >> a;
			v[i][j] = a;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		v[i][n] = a;
	}


	for (int i = 0; i < n; i++)
	{
		int maxi = 0;

		for (int j = i; j < n; j++)
		{
			if (v[j][i] > maxi)
			{
				maxi = 1;
				swap(v[i], v[j]);
				break;
			}
		}


		if (maxi == 0)
		{
			cout << -1;
			return 0;
		}

		for (int j = 0; j < n; j++)
		{
			if (i != j && v[j][i])
			{
				v[j] = v[j] ^ v[i];
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << v[i][n] << " ";
}