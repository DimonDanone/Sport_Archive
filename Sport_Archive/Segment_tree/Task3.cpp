/*
Всем известно, что в армии без строевой подготовки и порядка дело не обходится и за этим там строго следят. Однажды утром сержант построил всех своих подчиненных в K рядов по N человек в каждом, но оказалось, что солдаты выстроились не по росту, и поэтому сержант решил их наказать. Солдаты должны были выстроиться по росту в каждом отдельном ряде так, что слева должны были стоять самые низкие, а справа самые высокие. Ну а поскольку в армии виноваты всегда слабые (низкие), то наказание было следующим: каждый солдат должен был отжаться столько раз, сколько солдат стоит от него слева выше его ростом.

Оказалось, что все солдаты были разного роста, и многим пришлось отжиматься достаточно много раз. Сержанту стало интересно: сколько же раз в общей сложности пришлось отжаться солдатам?

Помогите ему решить эту задачу!
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