/*
���������� ����� ���������� ������� �� ������������� �����������. �� ����� ��������� �� ������ ���������� ���������� �����, ������� �����, ��� ����� �������������� ������������� ������� ����������� (����� �� ��������� �� ������� � ������), � ���� ����� ����������� ��������������������� ��� �������, ����� ������� �� ����� ��������� ���������. �� ����������� ������ ���������� ������������� � �������� ����� ���������� ����������, �������, ��� �������� �� ��������� ������������ ����������� ������ ���� � �� ���� ���� �� �� ������ ��������� ��� �������� .

������ ��������� ����� ����� ���� ���������� ���������, �������� ��� �� ����������� �������� K ����� (�� ���� ��������� ����� ��������� �� ����� K ���������).
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
