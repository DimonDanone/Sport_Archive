/*
Дана строка s длины не более 5·104.
Также дан набор строк s1,?...,?sk суммарная длина которых не превышает 10^5.
Для каждой строки si, 1???i???k требуется вычислить сколько раз она встречается в качестве подстроки в строке s.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <iterator>

using namespace std;

vector<long long> pw;
long long a, mod;

long long hes(long long i, long long j, vector<long long> & hs)
{
    if (i == 0)
        return hs[j];

    return ((hs[j] - ((hs[i - 1] * pw[j - i + 1]) % mod)) % mod + mod) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    vector<long long> h(s.size(), 0);

    mod = 1e9 + 13;
    a = 31;

    pw.resize(1e5 + 3, 0);

    pw[0] = 1;
    h[0] = (s[0] - 'a' + 1) % mod;

    for (long long i = 1; i < s.size(); i++)
    {
        pw[i] = (pw[i - 1] * a) % mod;
        h[i] = ((h[i - 1] * a) % mod + (s[i] - 'a' + 1)) % mod;
    }

    for (long long i = s.size(); i < 1e5 + 3; i++)
    {
        pw[i] = (pw[i - 1] * a) % mod;
    }

    int m; cin >> m;

    vector<map<long long, int>> count_hes(1e5 + 3);
    vector<bool> used_len(1e5 + 3, false);

    for (int _ = 0; _ < m; _++)
    {
        string now; cin >> now;

        long long now_h = (now[0] - 'a' + 1) % mod, pr = (now[0] - 'a' + 1) % mod;

        for (int i = 1; i < now.size(); i++)
        {
            now_h = ((pr * a) % mod + (now[i] - 'a' + 1)) % mod;
            pr = now_h;
        }

        if (!used_len[now.size()])
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (i + now.size() - 1 < s.size())
                    count_hes[now.size()][hes(i, i + now.size() - 1, h)]++;
            }

            used_len[now.size()] = true;
        }

        cout << count_hes[now.size()][now_h] << endl;
    }
}
