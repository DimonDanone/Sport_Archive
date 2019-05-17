#include <cmath>
#include "iostream"
#include "vector"
#include "string"

using  namespace std;

long long a, i = 0;
string s;

long long readInt()
{
    long long x = 0;
    bool ok = true;

    while (i < s.size() && s[i] >= '0' && s[i] <= '9')
    {
        ok = false;
        x = x*10 + (s[i] - '0');
        i++;

        if (s[i] == '^')
        {
            i++;
            x = pow(x, readInt());
        }
    }

    if (ok)
    {
        i++;
        x = a;

        if (s[i] == '^')
        {
            i++;
            x = pow(x, readInt());
        }

    }

    return x;
}

long long readMn()
{
    long long ans = 1;

    ans *= readInt();

    while(i < s.size() && s[i] == '*')
    {
        i++;
        ans *= readInt();
    }

    return ans;
}

long long read()
{
    long long ans = 0;

    if (s[i] == '-')
    {
        i++;
        ans -= readMn();
    }
    else
    {
        ans += readMn();
    }

    while(i < s.size() && (s[i] == '+' || s[i] == '-'))
    {
        if (s[i] == '+')
        {
            i++;
            ans += readMn();
        }
        else
        {
            i++;
            ans -= readMn();
        }
    }

    return ans;
}

int main()
{
    cin >> s;
    cin >> a;

    cout << read();
}