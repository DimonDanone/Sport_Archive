#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using  namespace std;

vector<vector<int>> g;
vector<pair<int, int>> v_time;
vector<vector<int>> par;

int t = 1;

int maxl = 20;


void dfs(int pos, int pr = 0)
{
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

    for (int i = maxl; i >= 0; i--)
    {
        if (!upper(par[x][i], y))
            x = par[x][i];
    }

    return par[x][0];
}

int main()
{
    int n, m;
    cin >> n >> m;

    v_time.resize(n);
    g.resize(n);
    par.resize(n, vector<int>(maxl, -1));

    for (int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b; a--; b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0);

    for (int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y; x--; y--;
        cout << lca(x, y) + 1 << endl;
    }
}