/*
ƒл€ исследовани€ поверхности ћарса ученым необходимо разработать систему оповещени€, котора€ смогла бы передавать информацию по цепному принципу между городами, которые планируетс€ там построить.

ѕри этом в каждом городе необходимо построить радиостанцию таким образом, чтобы была св€зь между всеми городами. ѕри этом все такие станции должны передавать сигнал друг другу на равном рассто€нии R. “аким образом, будет возможна передачи информации из одного города в другой только тогда, когда рассто€ние между ними не более R.

ѕо заданным координатам городов, в цел€х экономии энергии радиостанций, ¬ам следует определить минимальное значение R, при котором информаци€ сможет быть доставлена из любого города во все остальные.
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#define mp make_pair

using namespace std;

double minimal(double a, double b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	int inf = 1e9;
	int n;
	cin >> n;

	vector<pair<double, double>> cor(n);

	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin >> x >> y;
		cor[i].first = x;
		cor[i].second = y;
	}

	vector<double> min(n, inf);
	min[0] = 0;

	vector<double> min1 = min;

	set<pair<double, int>> q;
	
	q.insert(mp(0, 0));

	while (!q.empty())
	{
		int v = q.begin() -> second;
		q.erase(q.begin());
		min[v] = -inf;
		for (int i = 0; i < n; i++)
		{
			if (i != v)
			{
				pair<double, double> to = cor[i];
				double ww = sqrt((cor[v].first - to.first)*(cor[v].first - to.first) + (cor[v].second - to.second)*(cor[v].second - to.second));
				if (ww < min[i])
				{
					q.erase(mp(min[i], i));
					min[i] = ww; min1[i] = minimal(min1[i], min[i]);
					q.insert(mp(min[i], i));
				}
			}
		}
	}

	double res = min1[0];

	for (int i = 1; i < n; i++)
	{
		if (min1[i] > res)
			res = min1[i];
	}

	res = round(res * 100) / 100;	
	
	cout.precision(2);
	cout << fixed << res;
}