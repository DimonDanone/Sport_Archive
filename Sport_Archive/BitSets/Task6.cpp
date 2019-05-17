/*
ѕринцесса Twilight пришла к Celestia в замок, где раньше жила Luna, чтобы исследовать ларец элементов гармонии.
ѕоследовательность положительных целых чисел bi называетс€ гармонической тогда и только тогда, когда наибольший общий делитель любых двух ее элементов равен 1. —огласно древней книге, ключ от ларца Ч это гармоническа€ последовательность bi, минимизирующа€ значение выражени€:
Sum(i = 1..n, abs(a_i - b_i))
¬ам дана последовательность ai. ѕомогите принцессе Twilight найти ключ от ларца.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	vector<int> prost = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53 };
	vector<int> mnog(59);

	for (int i = 2; i < 59; i++)
	{
		for (int j = 0; j < prost.size(); j++)
		{
			if (i % prost[j] == 0)
			{
				mnog[i] = mnog[i] | (1 << j);
			}
		}
	}

	int p_2 = pow(2, 16);
	
	vector<vector<int>> dp(n + 1, vector<int>(p_2, 1e9));
	vector<vector<int>> g(n + 1, vector<int>(p_2, 0));

	for (int i = 0; i < p_2; i++)
	{
		dp[0][i] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 58; j++)
		{
			int mask = (~mnog[j]) & ((1 << prost.size()) - 1);
			int c = mask;

			while (mask > 0)
			{
				if (dp[i - 1][mask] + abs(j - a[i]) < dp[i][mask | mnog[j]])
				{
					dp[i][mask | mnog[j]] = dp[i - 1][mask] + abs(j - a[i]);
					g[i][mask | mnog[j]] = j;
				}
				
				mask = (mask - 1) & c;
			}

			if (dp[i - 1][mask] + abs(j - a[i]) < dp[i][mask | mnog[j]])
			{
				dp[i][mask | mnog[j]] = dp[i - 1][mask] + abs(j - a[i]);
				g[i][mask | mnog[j]] = j;
			}
		}
	}

	int minim = 1e9;
	int mask = 0;

	for (int i = 0; i < p_2; i++)
	{
		if (dp[n][i] < minim)
		{
			minim = dp[n][i];
			mask = i;
		}
	}

	vector <int> ans;

	for (int i = n; i > 0; i--)
	{
		ans.push_back(g[i][mask]);
		mask = mask & (~mnog[g[i][mask]]);
	}

	for (int i = n - 1; i > -1; i--)
	{
		cout << ans[i] << " ";
	}
}
/* Fri Apr 05 2019 16:11:46 GMT+0300 (MSK) */
