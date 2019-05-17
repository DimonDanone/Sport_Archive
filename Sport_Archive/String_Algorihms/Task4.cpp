/*
Дана строка. Сколько различных подстрок, не считая пустой, она содержит?
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

vector<unsigned long long> pw, pw1;
vector<long long> h, h1;
long long a, mod, a1, mod1;
string s;

long long hes(long long i, long long j)
{
	if (i == 0)
		return h[j];

	return ((h[j] - ((h[i - 1] * pw[j - i + 1]) % mod)) % mod + mod) % mod;
}

long long hes1(long long i, long long j)
{
	if (i == 0)
		return h1[j];

	return ((h1[j] - (h1[i - 1] * pw1[j - i + 1]) % mod1) % mod1 + mod1) % mod1;
}


int main()
{
	cin >> s;

	mod = 1e9 + 7;
	a = 27;
	a1 = 111;
	mod1 = 1e9 + 9;

	h1.resize(s.size(), 0);
	pw1.resize(s.size(), 0);
	h.resize(s.size(), 0);
	pw.resize(s.size(), 0);

	pw1[0] = 1;
	h1[0] = (s[0] - 'a' + 1) % mod1;
	pw[0] = 1;
	h[0] = (s[0] - 'a' + 1) % mod;

	for (long long i = 1; i < s.size(); i++)
	{
		pw[i] = (pw[i - 1] * a) % mod;
		h[i] = ((h[i - 1] * a) % mod + (s[i] - 'a' + 1)) % mod;

		pw1[i] = (pw1[i - 1] * a1) % mod1;
		h1[i] = ((h1[i - 1] * a1) % mod1 + (s[i] - 'a' + 1)) % mod1;
	}

	set<pair<long long, long long>> res;

	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i; j < s.size(); j++)
		{
			//cout << hes(i, j) << " " << hes1(i, j) << endl;
			res.insert(make_pair(hes(i, j), hes1(i, j)));
		}
	}

	cout << res.size();
}