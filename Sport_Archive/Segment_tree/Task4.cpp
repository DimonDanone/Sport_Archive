/*
ѕо кругу сто€т N человек с номерами от 1 до N в пор€дке возрастани€ (игрок с номером N и игрок с номером 1 сто€т р€дом). ќни играют в игру по следующим правилам.  аждый игрок получает стартовое количество очков, равное его номеру. ƒалее в каждом раунде игры судь€ вращает волчок. ќбозначим через m количество очков игрока, на которого указал волчок. Ётот игрок должен сделать следующие действи€:

ќтсчитать m человек, которые сто€т вслед за ним по кругу;
¬ычислить среднее арифметическое очков этих игроков;
ќкруглить полученное число до целого путем отбрасывани€ дробной части;
ѕолученное число становитс€ новым количеством очков этого игрока.

»звестно, что за врем€ игры судь€ вращал волчок K раз. ј также известно, на каких игроков указывал волчок на каждом из ходов. “ребуетс€ определить сумму очков всех игроков в конце игры.
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
