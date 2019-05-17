/*
�� ����� ����� N ������� � �������� �� 1 �� N � ������� ����������� (����� � ������� N � ����� � ������� 1 ����� �����). ��� ������ � ���� �� ��������� ��������. ������ ����� �������� ��������� ���������� �����, ������ ��� ������. ����� � ������ ������ ���� ����� ������� ������. ��������� ����� m ���������� ����� ������, �� �������� ������ ������. ���� ����� ������ ������� ��������� ��������:

��������� m �������, ������� ����� ����� �� ��� �� �����;
��������� ������� �������������� ����� ���� �������;
��������� ���������� ����� �� ������ ����� ������������ ������� �����;
���������� ����� ���������� ����� ����������� ����� ����� ������.

��������, ��� �� ����� ���� ����� ������ ������ K ���. � ����� ��������, �� ����� ������� �������� ������ �� ������ �� �����. ��������� ���������� ����� ����� ���� ������� � ����� ����.
*/

#include <vector>
#include <iostream>

using namespace std;

int sz, n;
const int NMAX = 1000000;
long long tree[4 * NMAX];

void build(vector<long long> &a)
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

void upd(int ind, long long val)
{
	for (tree[ind += sz] = val; ind > 1; ind /= 2)
	{
		tree[ind / 2] = tree[ind] + tree[ind ^ 1];
	}
}

long long get(int l, int r)
{

	long long res = 0;

	for (l += sz, r += sz; l <= r; l /= 2, r /= 2)
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
	int k;

	cin >> n >> k;

	vector<long long> a(n);

	for (long long i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}

	build(a);
	for (int i = 0; i < k; i++)
	{
		long long sum = 0;

		int p;

		cin >> p;

		long long x = tree[p + sz - 1];

		if (p + x > n)
		{
			sum += get(p, n - 1) + get(0, x - (n - p + 1));
		}
		else
			sum += get(p, p + x - 1);
		upd(--p, sum / x);
	}

	cout << tree[1];
}
