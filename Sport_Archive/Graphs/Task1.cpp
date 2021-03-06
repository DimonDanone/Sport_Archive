/*
���, ��� ������� ��������� ���� �� ����������������, �������� ����� ������������� �������. ������������� ������� �� ���� ��������� ����� ����� N ��������. �� ����� ��� ������ �������������, �� ����� ����� �������� ����� ���� ������ ����� ������, ��������, � ������ ������������. ��� ���������� ��������� ����������� ����� K, ��� ������ �� ���� �������� ����� K-�������.

������������� �������� ���� ����� K-�������, ���� ��������� ��������� �������: ��� ����� ���� ��������� ������� ����� �������� �� ������ �� �������, ������� ������� �������� �� ����� K ���. ��������� ������ - ��� ������ �� ������������ ������ � �������� �����������. �������������, ��� ����� ������ ����� �������� ����� ��������, ��������, ��������� ��� ������� �������.
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
	int inf = 1e5;
	
	int n, m;
	cin >> n >> m;

	vector<vector<int>> d(n, vector<int>(n, inf));

	for (int i = 0; i < m; i++)
	{
		int p, q;
		cin >> p >> q;
		p--;
		q--;
		d[p][q] = 0;
		d[q][p] = min(d[q][p], 1);
	}
	
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}

	int res = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d[i][j] > res && d[i][j] != inf)
				res = d[i][j];
		}
	}
	

	cout << res;
}
