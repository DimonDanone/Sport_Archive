/*
������� ���� ����� ����� ����������� My Little Pony. � ��� ����� ��� �� ������, ���� ��� ������, ����� � ������� ����!
��� ��� ������� ����� ���� ����������� � ����� ��������� ���������� ����, �� ���� ��� ������ �������� ��� ���� ������������� ������� ������ ������������. � ������� ���� ������� ���� ��������� ������ ������� My Little Pony � ���� �� �����. ������ �� ��������, ��� � ���� ��� ���� ��� �������� ��������� ��� ���������� �������, � �������� ���������� ������� ������ ���������� ����������� ��� ����� ������� �������. ��������, ���� � ����� �� ����� ���� Twilight Sparkle (���������� �������) � Spike (�����), ����� ��� ����� �� ���� ��� Princess Celestia (��������� ��������). ����� ��������� ���, ��� ����� ������� ������� ����� �������: ���� ��� ������������� �������, ���� ���������� ������� � Nightmare Moon (������ ����).
��� �������� ����������� ��� ������� ������ ������� �� 1 �� n. ����� ������� ����� ����������� ����� �������� ����� {a1, ..., ak} � {b1, ..., bt} � ��������, ��� ���� � ���� ��� ���� ������� � �������� a1, ..., ak, �� �� ����� ����� ������� � �������� b1, ..., bt.
�������� �����, ����� ������� ��� �� �������� � ��������� ����, ������ ������ ��� ������� �������, ������� ��� �������. ��� ������ �� ������� ���������� ����� �������, ������� ������������ ��� ������� �����, �� ���� �������. �����������, �������� �� ����� �������� ������ �������.
����� ������� ����� � ����� ����� �������?
*/
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	const int maxn = 1000;
	int n, m; cin >> n >> m;

	vector<pair<bitset<maxn>, bitset<maxn>>> v(m);

	for (int i = 0; i < m; i++)
	{
		cin >> v[i].first;
		cin >> v[i].second;
	}

	bitset<maxn> now;
	cin >> now;

	int k = 0;
	bool t = false;

	for (int i = k; i < m; i++)
	{
		t = false;
		for (int j = k; j < m; j++)
		{
			if ((now & v[j].first) == v[j].first)
			{
				t = true;
				now |= v[j].second;
				swap(v[j], v[k]);
				k++;
			}
		}
		if (!t)
			break;
	}

	for (int i = n - 1; i > -1; i--)
		cout << now[i];
	cin >> n;
}