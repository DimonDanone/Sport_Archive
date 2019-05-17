/*
Миша и Гриша — веселые ребята, поэтому они любят кататься на новом метро. В метро есть n станций, соединенных n?-?1 перегонами так, что каждый перегон соединяет две станции, и от каждой станции до любой другой можно добраться по перегонам.
Ребята решили повеселиться и затеяли кое-что. А именно, в какой-нибудь день утром Миша проезжает кратчайшим путем от станции s до станции f, и на каждой из станций, мимо которых он проехал (включая s и f), он рисует баллончиком корявую надпись «Здесь был Миша». После чего вечером того же дня, Гриша едет со станции t до станции f кратчайшим путем и считает количество станций, на которых обнаружит надпись Миши. После этого ночью этого же дня работники метро смывают все эти надписи, потому что метро должно быть чистым.
Ребята уже выбрали на несколько дней вперед по три станции a, b и c, одна из которых должна стать станцией s, другая — станцией f, а третья — станцией t в каждый из дней. Им стало интересно, как нужно выбрать из этих трех станций s, f, t так, чтобы число, которое насчитает Гриша, было максимально возможным. Они просят вас помочь им.
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

int t = 1;

int maxl = 20;


void dfs(int pos, int pr = 0)
{
    rast[pos] = rast[pr] + 1;

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
    int n, q;
    cin >> n >> q;

    v_time.resize(n);
    g.resize(n);
    par.resize(n, vector<int>(maxl, -1));
    rast.resize(n);

    for (int i = 1; i < n; i++)
    {
        int a; cin >> a; a--;

        g[i].push_back(a);
        g[a].push_back(i);
    }

    rast[0] = -1;
    dfs(0);

    for (int i = 0; i < q; i++)
    {
        int a, b, c; cin >> a >> b >> c; a--; b--; c--;

        vector<int> per = {a, b, c};

        int ans = 0;

        ans = max(ans, 1 + (lent(a, b) + lent(a, c) - lent(b, c))/2);
        ans = max(ans, 1 + (lent(b, c) + lent(a, b) - lent(a, c))/2);
        ans = max(ans, 1 + (lent(b, c) + lent(a, c) - lent(a, b))/2);

        cout << ans << endl;
    }
}
/* Sun Apr 14 2019 15:09:05 GMT+0300 (MSK) */
