/*
Ѕайтек учитс€ кататьс€ на льду. ќн новичок, и поэтому он передвигаетс€ следующим образом: сначала отталкиваетс€ от сугроба на север, восток, юг или запад Ч и катитс€ до тех пор, пока не повстречает очередной сугроб. Ѕайтек заметил, что таким образом он не сможет добратьс€ от некоторых сугробов до некоторых других, какой бы ни была последовательность его движений. “еперь он хочет соорудить несколько дополнительных сугробов так, чтобы он мог добратьс€ от любого сугроба до любого другого. Ѕайтек попросил ¬ас найти наименьшее количество сугробов, которые ему потребуетс€ соорудить.

ћы предполагаем, что Ѕайтек может сооружать сугробы только в точках с целочисленными координатами.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> p, r;

struct edge
{
	int fr, to, w;
	edge() {}
	edge(int fr, int to, int w) : fr(fr), to(to), w(w) {}
};

void build(int n)
{
	p.resize(n);
	r.resize(n);
	for (int i = 0; i < n; i++)
	{

		p[i] = i;
		r[i] = 1;
	}
}

int color(int i)
{
	if (i == p[i])
		return i;
	return p[i] = color(p[i]);
}

void unite(int i, int j)
{
	i = color(i);
	j = color(j);
	if (i == j)
		return;

	if (r[i] < r[j])
		swap(i, j);
	p[j] = i;
	r[i] += r[j];
}

int main()
{
	int n, m;
	cin >> n;

	vector<bool> check(n);
	vector<pair<int, int>> g(n);

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		g[i].first = x;
		g[i].second = y;
	}

	build(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (g[i].first == g[j].first|| g[i].second == g[j].second)
			{
				unite(i, j);
			}
		}

	set<int> res;

	for (int i = 0; i < n; i++)
	{
		res.insert(p[i]);
	}

	cout << res.size() - 1;

}
/* Wed Jan 30 2019 13:51:29 GMT+0300 (MSK) */
