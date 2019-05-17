/*
A и B готовятся к олимпиадам про программированию.
Университет, в котором учатся A и B, представляет собой множество аудиторий, соединенных между собой переходами. Всего в университете n аудиторий, соединённых n?-?1 переходом таким образом, что из любой аудитории можно дойти до любой по переходам. Аудитории пронумерованы от 1 до n.
Каждый день А и B пишут контесты в некоторых аудиториях своего университета, и после каждого контеста они собираются вместе в одной аудитории и обсуждают задачи. A и B хотят, чтобы расстояния от аудитории, где они будут обсуждать задачи, до аудиторий, где они пишут контесты, были равны. Расстоянием между двумя аудиториями является количество ребер на кратчайшем пути между ними.
Так как каждый день они пишут контесты в новых аудиториях, то они попросили вас помочь им найти количество возможных аудиторий для обсуждения задач на каждый из ближайших m дней.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using  namespace std;

vector<vector<int>> g;
vector<pair<int, int>> v_time;
vector<vector<int>> par;
vector<int> rast;
vector<int> dp;

int t = 1;

int maxl = 20;


void dfs(int pos, int pr = 0)
{
    rast[pos] = rast[pr] + 1;

    dp[pos] = 1;
    v_time[pos].first = t++;
    par[pos][0] = pr;

    for (int i = 1; i < maxl; i++)
    {
        par[pos][i] = par[par[pos][i - 1]][i - 1];
    }

    for (int i = 0; i < g[pos].size(); i++)
    {
        int to = g[pos][i];

        if (to != pr)
        {
            dfs(to, pos);
            dp[pos] += dp[to];
        }
    }

    v_time[pos].second = t++;
}

bool upper(int x, int y)
{
    return v_time[x].first <= v_time[y].first && v_time[y].second <= v_time[x].second;
}

int lca(int x, int y)
{
    if (upper(x, y)) return x;
    if (upper(y, x)) return y;

    for (int i = maxl - 1; i >= 0; i--)
    {
        if (!upper(par[x][i], y))
            x = par[x][i];
    }

    return par[x][0];
}

int lent(int a, int b)
{
    return rast[a] - rast[lca(a, b)] + rast[b] - rast[lca(a, b)];
}

int main()
{
    int n;
    cin >> n;

    v_time.resize(n);
    g.resize(n);
    par.resize(n, vector<int>(maxl, -1));
    rast.resize(n);
    dp.resize(n);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b; a--; b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    rast[0] = -1;
    dfs(0);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--; b--;

        if (a == b)
        {
            cout << n << endl;
            continue;
        }

        int mid = lca(a, b);

        if ((lent(a, mid) + lent(b, mid)) % 2 == 0)
        {
            int to = (lent(a, mid) + lent(b, mid)) / 2;

            int now;

            if (lent(a, mid) >= lent(b, mid))
            {
                now = a;
            }
            else
            {
                now = b;
            }

            while (to > 0)
            {
                int step = 0;

                while((1 << step) < to)
                {
                    step++;
                    if (1 << step == to)
                        break;
                    else if (1 << step > to)
                    {
                        step--;
                        break;
                    }
                }

                now = par[now][step];
                to -= 1 << step;
            }

            int ans = 0;

            if (now == lca(a, b))
            {
                ans += dp[0] - dp[now];
            }

            int to1 = (lent(a, mid) + lent(b, mid)) / 2;
            to1--;

            int now1;

            if (lent(a, mid) >= lent(b, mid))
            {
                now1 = a;
            }
            else
            {
                now1 = b;
            }

            while (to1 > 0)
            {
                int step = 0;

                while((1 << step) < to1)
                {
                    step++;
                    if (1 << step == to1)
                        break;
                    else if (1 << step > to1)
                    {
                        step--;
                        break;
                    }
                }

                now1 = par[now1][step];
                to1 -= 1 << step;
            }

            ans += dp[now] - dp[now1];

            if (now != lca(a, b))
            {
                cout << ans << endl;
            }
            else
            {
                to1 = (lent(a, mid) + lent(b, mid)) / 2;
                to1--;

                if (lent(a, mid) < lent(b, mid))
                {
                    now1 = a;
                }
                else
                {
                    now1 = b;
                }

                while (to1 > 0)
                {
                    int step = 0;

                    while ((1 << step) < to1) {
                        step++;
                        if (1 << step == to1)
                            break;
                        else if (1 << step > to1) {
                            step--;
                            break;
                        }
                    }

                    now1 = par[now1][step];
                    to1 -= 1 << step;
                }

                ans -= dp[now1];

                cout <<  ans << endl;
            }


        }
        else
        {
            cout << 0 << endl;
        }
    }

}

/* Sun Apr 14 2019 17:41:29 GMT+0300 (MSK) */
