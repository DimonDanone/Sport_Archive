/*
Усатый-Полосатый XIII решил отомстить Ананси за освобождение бабочек, разрушив дом Ананси — его паутину. Паутина состоит из N узлов, некоторые из которых соединены нитями. Будем говорить, что два узла принадлежат одному кусочку, если от одного узла до другого можно добраться по нитям паутины. Усатый-Полосатый уже решил, какие нити и в каком порядке он будет рвать, и теперь хочет узнать, на сколько кусочков будет распадаться паутина после каждого из его действий.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> p, r;
int ans;
vector<int> res;
bool k = false;

struct edge
{
	int fr, to;
	edge() {}
	edge(int fr, int to) : fr(fr), to(to){}
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
	{
		if (k)
			res.push_back(ans);
		return;
	}

	
	if (k)
	{
		res.push_back(ans);
	}
		ans--;

	if (r[i] < r[j])
		swap(i, j);
	p[j] = i;
	r[i] += r[j];
}

int main()
{
	int n, m;
	cin >> n >> m;

	build(n);
	
	vector<bool> check(m, true);
	vector<edge> edges(m);

	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b; 
		a--;
		b--;
		edges[i] = edge(a, b);
	}
	
	int q;
	cin >> q;

	vector<int> used(q);
	
	for (int i = 0; i < q; i++)
	{
		int a;
		cin >> a;
		a--;
		check[a] = false;
		used[i] = a;
	}
	
	ans = n;

	for (int i = 0; i < m; i++)
	{
		if (check[i])
		{
			unite(edges[i].fr, edges[i].to);
		}
	}

	k = true;

	for (int i = q - 1; i > -1; i--)
	{
		unite(edges[used[i]].fr, edges[used[i]].to);
	}

	for (int i = q - 1; i > -1; i--)
		cout << res[i] << " ";

}