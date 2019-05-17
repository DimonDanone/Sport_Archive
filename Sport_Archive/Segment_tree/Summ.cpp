/*
Дан массив из n элементов. Изначально все элементы равны 0. Требуется отвечать на запросы двух типов:

- Вывести сумму элементов на позициях от l до r включительно.

- Присвоить i-тому элементу значение x.

Входные данные
Первая строка входного файла содержит два целых числа n (1???n???105) и m (1???m???105).

В следующих m строках содержатся описания запросов.

Запрос первого типа задается в виде: 1 l r (1???l???r???n).

Запрос второго типа задается в виде: 2 i x (1???i???n, ?-?109???x???109).

Выходные данные
Для каждого запроса первого типа требуется вывести одну строку, содержащую сумму чисел на требуемом отрезке.
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

void upd(int ind, long long val)
{
	for (tree[ind += sz] = val; ind > 1; ind /= 2)
	{
		tree[ind / 2] = tree[ind] + tree[ind ^ 1];
	}
}

void get(int l, int r)
{
	long long res = 0;

	for (l += sz, r += sz; l <= r; l /= 2, r /= 2)
	{
		if (l & 1)
			res += tree[l++];
		if (~r & 1)
			res += tree[r--];
	}
	cout << res << endl;
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
			get(b, c);
		else
			upd(b, c);
	}
}