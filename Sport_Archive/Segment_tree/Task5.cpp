/*
ƒан массив натуральных чисел a размера n. ƒано m запросов вида l,?r,?x. Ќа каждый запрос выведите максимальный элемент на отрезке [l,?r], который не превышает x, либо ?-?1, если такого элемента не существует.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

const int NMAX = 200000;
int n, sz;
vector<int> tree[4 * NMAX];

void built(vector<int> &a)
{
	sz = 1;
	while (sz < n)
	{
		sz *= 2;
	}

	for (int i = 0; i < n; i++)
		tree[i + sz] = {a[i]};


	for (int i = sz - 1; i > 0; i--)
	{
		tree[i].resize(tree[2*i].size() + tree[2*i+1].size());
		merge(tree[2*i].begin(), tree[2*i].end(), tree[2*i + 1].begin(), tree[2* i + 1].end(), tree[i].begin());
	}
}

int res_max(int l, int r, int x)
{
	int res = -1;

	for (l += sz, r += sz; l <= r; l /= 2, r /= 2)
	{
		if (l & 1)
		{
			int k = upper_bound(tree[l].begin(), tree[l].end(), x) - tree[l].begin() - 1;
			//cout << k << endl;
			if (k <= tree[l].size())
			{
				res = max(res, tree[l][k]);
			}
			l++;
		}
		if (!(r & 1))
		{
			int k = upper_bound(tree[r].begin(), tree[r].end(), x) - tree[r].begin() - 1;
			//cout << k << endl;
			if (k <= tree[r].size())
			{
				res = max(res, tree[r][k]);
			}
			r--;
		}
	}
	return res;
}


int main()
{
	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int m;
	cin >> m;

	built(a);

	for (int i = 0; i < m; i++)  
	{
		int l, r, x;
		cin >> l >> r >> x;

		cout << res_max(--l, --r, x) << endl;
	}

}