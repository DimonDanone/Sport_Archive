#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<long long> pw;
vector<long long> h;
long long a, mod;
string s;

long long hes(long long i, long long j)
{
	if (i == 0)
		return h[j];

	return ((h[j] - ((h[i - 1] * pw[j - i + 1]) % mod)) % mod + mod) % mod;
}


int main()
{
	cin >> s;

	mod = 1e9 + 9;
	a = 27;
	h.resize(s.size(), 0);
	pw.resize(s.size(), 0);

	pw[0] = 1;
	h[0] = (s[0] - 'a' + 1) % mod;

	for (long long i = 1; i < s.size(); i++)
	{
		pw[i] = (pw[i - 1] * a) % mod;
		h[i] = ((h[i - 1] * a) % mod + (s[i] - 'a' + 1)) % mod;
	}

	string s1;
	cin >> s1;

	vector<long long> res;
	long long check = 0;

	for (long long i = 0; i < s1.size(); i++)
	{
		check = (check + (pw[s1.size() - 1 - i] * (s1[i] - 'a' + 1)) % mod) % mod;
	}

	for (long long i = 0; i <= s.size() - s1.size(); i++)
	{
		if (hes(i, i + s1.size() - 1) == check)
			res.push_back(i);
	}

	cout << res.size() << endl;

	for (long long i = 0; i < res.size(); i++)
		cout << res[i] << " ";


	cin >> s;
}