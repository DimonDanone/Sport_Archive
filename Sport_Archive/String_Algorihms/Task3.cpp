/*
String s was writen many times in one line without spaces. You are given a substring of this string. Your need to determine the minimal possible length of the string s.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

string s;

vector<int> z_func(string s)
{
	vector<int> z(s.size(), 0);

	int l = 0, r = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if (i <= r)
			z[i] = min(z[i - l], r - i + 1);

		for (; i + z[i] < s.size() && s[z[i]] == s[i + z[i]];)
			z[i]++;

		if (i + z[i] - 1 > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
	}

	return z;
}

vector<int> pref(string s)
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

	return kmp;

}

int main()
{
	string s;

	cin >> s;

	vector<int> z = z_func(s);
	vector<int> kmp = pref(s);

	int max = 0;
	int pos = 0;

	for (int i = 1; i < s.size(); i++)
	{
		if (z[i] >= max)
		{
			max = z[i];
			pos = i;
		}
	}

	bool ok = 1;

	for (int i = pos; i < kmp.size(); i++)
	{
		if (kmp[i] == 0)
		{
			ok = 0;
			break;
		}
	}

	if (max == 0 || !ok)
		cout << s.size();
	else
		cout << pos;

}