/*
К очередному Чемпионату Урала было решено подготовить кружки с символикой чемпионата не только для участников, но и для всех желающих.
Имея привычку делать важные дела в самый последний момент, дизайнер закончил работу над макетом за два дня до начала регистрации участников. Ещё день уйдёт у завода-изготовителя на то, чтобы изготовить кружки и нанести на них изображение. На то, чтобы довезти кружки от завода-изготовителя до места проведения соревнования, остаётся всего 24 часа.
Заказ на десять миллионов экземпляров кружек (а именно столько заказали организаторы), конечно же, за один рейс не увезти. Однако, за первый рейс хочется привезти максимальное количество кружек.
Для перевозки был заказан один большегрузный автомобиль. Но есть один нюанс: на некоторых дорогах установлено ограничение на вес автомобиля. Поэтому если автомобиль нагрузить кружками под завязку, то, возможно, не удастся воспользоваться самым коротким маршрутом, а придётся ехать в объезд. Может случиться даже так, что из-за этого грузовик не успеет доехать до места проведения соревнования вовремя, а этого допустить никак нельзя.
Итак, сколько же кружек можно погрузить в автомобиль, чтобы успеть привезти этот ценный груз вовремя, и не нарушая правил дорожного движения?
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <set>

using  namespace std;

vector<vector<int>> g;
vector<vector<int>> w;
vector<vector<int>> t;
int n, m;

int mass = 3000000;
int inf = 1e9;

bool check(int x)
{
    vector<int> t_now(n, inf);
    vector<bool> used(n, false);

    set<int> q;
    q.insert(0);
    t_now[0] = 0;

    while (!q.empty())
    {
        int now = *q.begin();
        q.erase(q.begin());

        for (int i = 0; i < g[now].size(); i++)
        {
            int to = g[now][i];
            int we = (w[now][i] - mass) / 100;

            if (we >= x)
            {
                if (t_now[now] + t[now][i] <= 1440 && t_now[now] + t[now][i] < t_now[to])
                {
                    q.erase(to);
                    t_now[to] = t_now[now] + t[now][i];
                    q.insert(to);
                }
            }
        }
    }

    bool ok = true;
    if (t_now[n - 1] > 1440)
        ok = false;

    return ok;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    g.resize(n);
    w.resize(n);
    t.resize(n);

    for (int i = 0; i < m; i++)
    {
        int f, to, time, mi; cin >> f >> to >> time >> mi;
        f--; to--;
        g[f].push_back(to);
        g[to].push_back(f);

        t[f].push_back(time);
        t[to].push_back(time);

        w[f].push_back(mi);
        w[to].push_back(mi);
    }

    int l = 0, r = 1e7;

    while (r - l > 1)
    {
        int mid = (l + r)/2;
        //cout << mid << " " << check(mid) << endl;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    if (check(r))
        cout << r << endl;
    else
        cout << l << endl;

}
/*
4 4
1 2 1400 3123123
1 3 30 3000100
2 3 50 3000300
2 4 100 3000400
 */
