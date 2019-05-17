/*
���������� ������ ������ ���������, ������� ����� �� ����. ��� ����� ��� ���������
�����������������, � �������, ���� ����� �� ������, ����� ���������� ���� �� �����������
����� ��������. ����� ������������ ������, ����������� � ����� ���������, ��� ���������
����������������, ��������� ���������� �������� ���� ����� �������� ���� �� ����� ������
��������� ��� ������. ��� ������� �������� ��������������� ����� �������� ���������� ������
���������� � ����� ����������� �������, � �� ���������� � ���� �������� �������� ���������
����������. � ��� ������� �������.
����, �� ���� N �����. ��� ��� ��� ��������� ������ ���� ������ ����������������
����������, �� � ������ ������ ���� ���������� Xi
, Yi
. ���������� ����� ��������� �
���������� ����������� ���������, ������� ����� �������, ��� �� � ����� ���� �����
���������� �� ���������.
������ ���������� ������ ����� ������� ����������. ��� ����� ��� �������������� M ��������,
������ �� ������� ������ ���: �������� ����� ��������� ������ ��� �� ������� �������, ��������
���������� �������������:
� ���������, ��-�� ������������ ���������� ������� ���������� ������ �� ������ ���������
�� ��������� ���������, ����� ��������� ���������� ��������. ������� ��� ������ ��� ������ ��.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

const int NMAX = 200000;
long long n, sz;
vector<int> tree[4 * NMAX];

void build(vector<pair<int, int>> &cor)
{

	sz = 1;

		while (sz < n)
	{
		sz *= 2;
	}

	for (int i = 0; i < n; i++)
		tree[i + sz] = {cor[i].second};

	for (int i = sz - 1; i > 0; i--)
	{
		tree[i].resize(tree[2 * i].size() + tree[2 * i + 1].size());
		merge(tree[2 * i].begin(), tree[2 * i].end(), tree[2 * i + 1].begin(), tree[2 * i + 1].end(), tree[i].begin());
	}
}

int get(int l, int r, int x)
{ 
	int res = 0;

	for (l += sz, r += sz; l <= r; l /= 2, r /= 2)
	{
		if (l & 1)
		{
			res += upper_bound(tree[l].begin(), tree[l].end(), x) - tree[l].begin();
			l++;
		}
		if (!(r & 1))
		{
			res += upper_bound(tree[r].begin(), tree[r].end(), x) - tree[r].begin();
			r--;
		}

		//cout << res << "!!" << endl;
	}
	return res;
}


int main()
{
	freopen("stars.in", "r", stdin);
	freopen("stars.out", "w", stdout);
	cin >> n;

	int m;
	cin >> m;

	vector<pair<int, int>> v(n),cor(n);
	vector<int> xof(n);

	for (int i = 0; i < n; i++)
	{
		cin >> cor[i].first >> cor[i].second;
	}

	v = cor;
	sort(cor.begin(), cor.end());

	for (int i = 0; i < n; i++)
	{
		v[i].first = lower_bound(cor.begin(), cor.end(), v[i]) - cor.begin();
	}
	sort(v.begin(), v.end());
	build(v);

	for (int i = 0; i < m; i++)
	{
		int xmin, xmax, ymin, ymax;

		cin >> xmin >> xmax >> ymin >> ymax;

		xmin = lower_bound(cor.begin(), cor.end(), make_pair(xmin, -1000000001))- cor.begin();
		xmax = lower_bound(cor.begin(), cor.end(), make_pair(xmax, 1000000001)) - cor.begin() - 1;

		if (xmin > xmax)
			cout << 0 << endl;
		else
		//cout << xmin << " " << xmax << endl;
		cout << get(xmin, xmax, ymax) - get(xmin, xmax, ymin - 1) << endl;


	}

	//for (int i = 0; i < n; i++)
		//cout << cor[i].first << " " << cor[i].second << endl;

}
/* Sun Jan 27 2019 22:24:49 GMT+0300 (MSK) */
