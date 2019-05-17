/*
ѕрофессору ‘орду необходимо попасть на международную конференцию. ќн хочет потратить на дорогу наименьшее количество денег, поэтому решил, что будет путешествовать исключительно ночными авиарейсами (чтобы не тратитьс€ на ночевку в отел€х), а днем будет осматривать достопримечательности тех городов, через которые он будет проезжать транзитом. ќн внимательно изучил расписание авиаперелетов и составил набор подход€щих авиарейсов, вы€снив, что перелеты на выбранных направлени€х совершаютс€ каждую ночь и за одну ночь он не сможет совершить два перелета .

“еперь профессор хочет найти путь наименьшей стоимости, учитыва€ что до конференции осталось K ночей (то есть профессор может совершить не более K перелетов).
*/
#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

struct edge
{
	int from, to, w;
	edge() {}
	edge(int from, int to, int w) : from(from), to(to), w(w) {}
};

int main()
{
	int inf = 1e9;

	int n, m, k, s, f;
	cin >> n >> m >> k >> s >> f;
	s--;
	f--;

	vector<edge> g(m);
	vector<int> d1(n);
	vector<int> d2(n);

	for (int i = 0; i < m; i++)
	{
		int si, fi, w;
		cin >> si >> fi >> w;
		si--;
		fi--;
		g[i] = edge(si, fi, w);
	}

	for (int i = 0; i < n; i++)
	{
		d1[i] = inf;
		d2[i] = inf;
	}

	d1[s] = 0;
	d2[s] = 0;

	for (int i = 0; i < k; i++)
	{
	
		for (int j = 0; j < m; j++)
		{
			int from = g[j].from;;
			int to = g[j].to;
			int w = g[j].w;

			if (d2[to] > d1[from] + w && d1[from] != inf)
			{
				d2[to] = d1[from] + w;
			}
		}
		d1 = d2;
	}

	if (d1[f] != inf)
		cout << d1[f];
	else
		cout << -1;
}
