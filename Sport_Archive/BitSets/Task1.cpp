/*
Дано n предметов, каждый из которых характеризуется весом wi. Необходимо узнать, можно ли выбрать некоторый набор этих предметов так, чтобы суммарный вес этого набора был равен заданному числу W (вес рюкзака).

Ваша задача состоит в том, чтобы написать программу, решающую задачу о рюкзаке.
*/

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	const int maxn = 5 * 1e5 + 1;
	int n; cin >> n;

	int w;
	cin >> w;

	bitset<maxn> d;
	d[0] = 1;

	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		d |= d << a;
	}

	if (d[w])
		cout << "yes";
	else
		cout << "no";
}