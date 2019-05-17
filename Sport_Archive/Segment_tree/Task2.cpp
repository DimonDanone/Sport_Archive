/*
��� ������ �� n ���������. ���������� ��� �������� ����� 0. ��������� �������� �� ������� ���� �����:

- ��������� �� ���� ��������� �� ������� �� l �� r ����� x.

- ������� �������� i-���� ��������.

������� ������
������ ������ �������� ����� �������� ��� ����� ����� n (1???n???105) � m (1???m???105).

� ��������� m ������� ���������� �������� ��������.

������ ������� ���� �������� � ����: 1 l r x (1???l???r???n, ?-?109???x???109).

������ ������� ���� �������� � ����: 2 i (1???i???n).

�������� ������
��� ������� ������� ������� ���� ��������� ������� ���� ������, ���������� �������� ���������� ��������.
*/

#include <vector>
#include <iostream>

using namespace std;

int sz, n;
const int NMAX = 100000;
long long tree[4 * NMAX];

void build(vector<long long> a)
{
	sz = 1;

	while (sz < n)
	{
		sz *= 2;
	}

	for (int i = 0; i < n; i++)
	{
		tree[i + sz] = a[i];
	}

	for (int i = sz - 1; i > 0; i--)
	{
		tree[i] = tree[2 * i] + tree[2 * i + 1];
	}
}

long long get(int ind)
{
	long long sum = 0;

	for (int i = ind + sz; i > 1; i /= 2)
		sum += tree[i];

	return sum;
}

void upd(int l, int r, long long x)
{
	long long res = 0;

	for (l += sz, r += sz; l <= r; l /= 2, r /= 2)
	{
		if (l & 1)
			tree[l++] += x;
		if (!(r & 1))
			tree[r--] += x;
	}
}


int main()
{
	int m;

	cin >> n >> m;

	vector<long long> a(n);

	build(a);

	for (int i = 0; i < m; i++)
	{
		long long a;

		cin >> a;

		if (a == 1)
		{
			int l, r, x;
			cin >> l >> r >> x;
			upd(--l, --r, x);
		}
		else
		{
			int p;
			cin >> p;
			cout << get(--p) << endl;
		}
	}
}