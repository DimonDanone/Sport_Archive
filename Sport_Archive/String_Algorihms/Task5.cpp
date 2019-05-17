/*
Даны K строк из маленьких латинских букв. Требуется найти их наибольшую общую подстроку.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iterator>

using namespace std;

vector<long long> pw;
vector<vector<long long>> heshs;
long long a, mod;

long long hes(long long i, long long j, vector<long long> &h)
{
	if (i == 0)
		return h[j];

	return ((h[j] - ((h[i - 1] * pw[j - i + 1]) % mod)) % mod + mod) % mod;
}

bool comp(string s1, string s2)
{
	if (s1.size() == s2.size())
		return s1 < s2;

	return s1.size() < s2.size();
}

int main()
{
	freopen("substr3.in", "r", stdin);
	freopen("substr3.out", "w", stdout);
	
	int k; cin >> k;
	vector<string> strs(k);

	mod = 1e9 + 9;
	a = 27;
	heshs.resize(k);
	pw.resize(10005, 0);

	for (int i = 0; i < k; i++)
	{
		cin >> strs[i];
	}

	sort(strs.begin(), strs.end(), comp);

	for (int i = 0; i < k; i++)
	{	
		pw[0] = 1;
		heshs[i].resize(strs[i].size(), 0);
		heshs[i][0] = (strs[i][0] - 'a' + 1) % mod;

		for (long long j = 1; j < strs[i].size(); j++)
		{
			pw[j] = (pw[j - 1] * a) % mod;
			heshs[i][j] = ((heshs[i][j - 1] * a) % mod + (strs[i][j] - 'a' + 1)) % mod;
		}
	}

	int l = 0, r = strs[0].size();
	
	string itog = "";

	while (r - l >= 0)
	{
		int mid = (l + r) / 2;
		
		vector<set<long long>> res(k);
		map<long long, pair<int, int>> m;

		for (int l1 = 0; l1 < k; l1++)
		{
			for (int i = 0; i <= strs[l1].size() - mid; i++)
			{
				int r1 = mid - 1;
				if (mid == 0)
					r1++;

				if (i + r1 < strs[l1].size())
				{
					res[l1].insert(hes(i, i + r1, heshs[l1]));
					if (l1 == 0)
						m[hes(i, i + r1, heshs[l1])] = make_pair(i, i + r1);
				}
			}
		}


		for (int i = 1; i < k; i++)
		{
			set<long long> c;
			set_intersection(res[0].begin(), res[0].end(), res[i].begin(), res[i].end(), inserter(c, c.begin()));
			res[0] = c;
		}

		if (res[0].size() != 0)
		{
			l = mid + 1;
			if (mid > itog.size())
				itog = strs[0].substr(m[*--res[0].end()].first, m[*--res[0].end()].second - m[*--res[0].end()].first + 1);
		}
		else
		{
			r = mid - 1;
		}
	}

	cout << itog;
}

/* Mon Mar 25 2019 21:16:46 GMT+0300 (MSK) */
