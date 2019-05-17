/*
���� ��������, ��� � ����� ��� �������� ���������� � ������� ���� �� ��������� � �� ���� ��� ������ ������. ������� ����� ������� �������� ���� ����� ����������� � K ����� �� N ������� � ������, �� ���������, ��� ������� ����������� �� �� �����, � ������� ������� ����� �� ��������. ������� ������ ���� ����������� �� ����� � ������ ��������� ���� ���, ��� ����� ������ ���� ������ ����� ������, � ������ ����� �������. �� � ��������� � ����� �������� ������ ������ (������), �� ��������� ���� ���������: ������ ������ ������ ��� �������� ������� ���, ������� ������ ����� �� ���� ����� ���� ��� ������.

���������, ��� ��� ������� ���� ������� �����, � ������ �������� ���������� ���������� ����� ���. �������� ����� ���������: ������� �� ��� � ����� ��������� �������� �������� ��������?

�������� ��� ������ ��� ������!
*/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

int sz, n;
const int NMAX = 10000;
vector<long long> tree(4 * NMAX);

void build()
{
	sz = 1;

	while (sz < n)
	{
		sz *= 2;
	}

	for (int i = 0; i < n; i++)
	{
		tree[i + sz] = 0;
	}

	for (int i = sz - 1; i > 0; i--)
	{
		tree[i] = tree[2 * i] + tree[2 * i + 1];
	}
}

void upd(int ind, long long val)
{
	for (tree[ind] = val; ind > 1; ind /= 2)
	{
		tree[ind / 2] = tree[ind] + tree[ind ^ 1];
	}
}

long long get_sum(int pos)
{
	long long res = 0;

	int l = pos;
	int r = n + sz;

	for (; l <= r; l /= 2, r /= 2)
	{
		if (l & 1)
			res += tree[l++];
		if (!(r & 1))
			res += tree[r--];
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int k;

	cin >> n >> k;

	long long sum = 0;

	for (int i = 0; i < k; i++)
	{
		build();
		for (int j = 0; j < n; j++)
		{
			long long a;
			cin >> a;
			a--;
			long long p = a + sz;
			upd(p, tree[p] + 1);
			sum += get_sum(p + 1);
		}
	}

	cout << sum;
}