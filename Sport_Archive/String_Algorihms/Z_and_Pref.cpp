#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string s;

void z_func(string s)
{
	vector<int> z(s.size(), 0);

	int l = 0, r = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if (i <= r)
			z[i] = min(z[i - l], r - i + 1);

		for (;i + z[i] < s.size() && s[z[i]] == s[i + z[i]];) 
			z[i]++;

		if (i + z[i] - 1 > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
	}

	for (int i = 0; i < z.size(); i++)
		cout << z[i] << " ";
	cout << endl;
}

void pref(string s)
{
	vector<int> kmp(s.size(), 0);

	for (int i = 1; i < s.size(); i++)
	{
		int j = kmp[i - 1];

		for (; j > 0 && s[i] != s[j];) 
			j = kmp[j - 1];

		if (s[i] == s[j]) j++;

		kmp[i] = j;
	}

	for (int i = 0; i < kmp.size(); i++)
		cout << kmp[i] << " ";
	cout << endl;

}

int main()
{
	cin >> s;

	z_func(s);
	pref(s);

}