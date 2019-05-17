#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long n, z;
	cin >> n >> z;

	vector<long long> a(n);

	long long len = 500;

	vector<vector<long long>> b_min(n / len + 1);

	for (long long i = 0; i < n; i++)
	{
		cin >> a[i];
		b_min[i / len].push_back(a[i]);
	}

	vector<long long> p_b(n / len + 1, 0);

	for (long long i = 0; i < b_min.size(); i++)
	{
		sort(b_min[i].begin(), b_min[i].end());
	}

	for (long long _ = 0; _ < z; _++)
	{
		long long s;
		cin >> s;

		if (s == 1)
		{
			long long l, r, x; cin >> l >> r >> x; l--; r--;

			long long ans = 0;

			long long b_l = l / len, b_r = r / len;

			if (b_l == b_r)
			{
				for (long long i = l; i <= r; i++)
				{
					if (a[i] < x - p_b[b_l])
						ans++;
				}
			}
			else
			{

				for (long long i = l; i < (b_l + 1)*len; i++)
				{
					if (a[i] < x - p_b[b_l])
						ans++;
				}

				for (long long i = b_l + 1; i < b_r; i++)
				{
					ans += lower_bound(b_min[i].begin(), b_min[i].end(), x - p_b[i]) - b_min[i].begin();
				}

				for (long long i = b_r * len; i <= r; i++)
				{
					if (a[i] < x - p_b[b_r])
						ans++;
				}
			}

			cout << ans << endl;
		}
		else
		{
			long long l, r, x; cin >> l >> r >> x; l--; r--;

			long long b_l = l / len, b_r = r / len;

			if (b_l == b_r)
			{
				for (long long i = l; i <= r; i++)
				{
					a[i] += x;
				}
				
				for (int i = b_l * len; i < min(len + (b_l * len), n); i++)
				{
					b_min[b_l][i % len] = a[i];
				}

				sort(b_min[b_l].begin(), b_min[b_l].end());

			}
			else
			{

				for (long long i = l; i < (b_l + 1)*len; i++)
				{
					a[i] += x;
				}

				for (int i = b_l * len; i < min(len + (b_l * len), n); i++)
				{
					b_min[b_l][i % len] = a[i];
				}

				sort(b_min[b_l].begin(), b_min[b_l].end());
				/////////////////////////////////////////
				for (long long i = b_l + 1; i < b_r; i++)
				{
					p_b[i] += x;
				}
				//////////////////////////////////////////
				for (long long i = b_r * len; i <= r; i++)
				{
					a[i] += x;
				}

				for (int i = b_r * len; i < min(len + (b_r * len), n); i++)
				{
					b_min[b_r][i % len] = a[i];
				}

				sort(b_min[b_r].begin(), b_min[b_r].end());
			}
		}
	}

}