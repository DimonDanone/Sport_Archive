#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> z(n, 0);

	for (int i = 0; i < n; i++)
		cin >> z[i];

	vector<int> res(n, 0);

	for (int i = 1; i < n; i++)
	{
		if (!z[i])
			continue;
		else
		{
			int a = z[i];

			for (int j = i + a - 1; j >= i && res[j] == 0; j--)
			{
				res[j] = a--;
			}
		}
	}

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";

}