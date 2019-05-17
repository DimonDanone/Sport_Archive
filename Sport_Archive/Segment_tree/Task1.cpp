/*
Дан массив из n элементов. Изначально все элементы равны 0. Требуется отвечать на запросы двух типов:

- Вывести разницу между максимальным и минимальным элементом на отрезке от l до r включительно.

- Присвоить i-тому элементу значение x.

Входные данные
Первая строка входного файла содержит два целых числа n (1???n???105) и m (1???m???105).

В следующих m строках содержатся описания запросов.

Запрос первого типа задается в виде: 1 l r (1???l???r???n).

Запрос второго типа задается в виде: 2 i x (1???i???n, ?-?109???x???109).

Выходные данные
Для каждого запроса первого типа требуется вывести одну строку, содержащую разницу между максимальным и минимальным элементом на заданном отрезке.
*/

#include <vector>
#include <iostream>

using namespace std;

int sz, n;
const int NMAX = 100000;
long long tree1[4 * NMAX];
long long tree2[4 * NMAX];

long long min(long long a, long long b)
{
	if (a < b)
		return a;
	else
		return b;
}

long long max(long long a, long long b)
{
	if (a >= b)
		return a;
	else
		return b;
}

void build(vector<long long> a)
{
	sz = 1;

	while (sz < n)
	{
		sz *= 2;
	}

	for (int i = 0; i < n; i++)
	{
		tree1[i + sz] = a[i];
		tree2[i + sz] = a[i];
	}

	for (int i = sz - 1; i > 0; i--)
	{
		tree1[i] = min(tree1[2 * i], tree1[2 * i + 1]);
		tree2[i] = max(tree2[2 * i], tree2[2 * i + 1]);
	}
}

void upd(int ind, long long val)
{
	ind += sz;
	for (tree1[ind] = val, tree2[ind] = val; ind > 1; ind /= 2)
	{
		tree1[ind / 2] = min(tree1[ind], tree1[ind ^ 1]);
		tree2[ind / 2] = max(tree2[ind], tree2[ind ^ 1]);
	}
}

long long get(int l, int r)
{
	long long res_min = tree1[l += sz], res_max = tree1[r += sz];

	for (; l <= r; l /= 2, r /= 2)
	{
		if (l & 1)
		{
			if (tree1[l] < res_min)
				res_min = tree1[l];
			if (tree2[l] > res_max)
				res_max = tree2[l];
			l++;
		}
		if (~r & 1)
		{
			if (tree1[r] < res_min)
				res_min = tree1[r];
			if (tree2[r] > res_max)
				res_max = tree2[r];
			r--;
		}
	}
	
	return res_max - res_min;
}

int main()
{
	int m;

	cin >> n >> m;

	vector<long long> a(n);

	build(a);

	for (int i = 0; i < m; i++)
	{
		long long a, b, c;

		cin >> a >> b >> c;

		if (a == 1)
			cout << get(b, c) << endl;
		else
			upd(b, c);
	}

}