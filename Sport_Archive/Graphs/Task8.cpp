/*
��� ������������ ����������� ����� ������ ���������� ����������� ������� ����������, ������� ������ �� ���������� ���������� �� ������� �������� ����� ��������, ������� ����������� ��� ���������.

��� ���� � ������ ������ ���������� ��������� ������������ ����� �������, ����� ���� ����� ����� ����� ��������. ��� ���� ��� ����� ������� ������ ���������� ������ ���� ����� �� ������ ���������� R. ����� �������, ����� �������� �������� ���������� �� ������ ������ � ������ ������ �����, ����� ���������� ����� ���� �� ����� R.

�� �������� ����������� �������, � ����� �������� ������� ������������, ��� ������� ���������� ����������� �������� R, ��� ������� ���������� ������ ���� ���������� �� ������ ������ �� ��� ���������.
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