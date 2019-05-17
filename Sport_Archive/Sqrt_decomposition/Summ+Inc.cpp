#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;

	vector<unsigned long long> a(n);

	for (long long i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	long long len = 500;

	vector<unsigned long long> p_b(n / len + 1, 0);
	vector<unsigned long long> b(n / len + 1, 0);

	for (long long i = 0; i < n; i++)
	{
		b[i / len] += a[i];
	}

	for (long long _ = 0; _ < k; _++)
	{
		long long s;
		cin >> s;

		if (s == 1)
		{
			long long l, r; cin >> l >> r; l--; r--;

			unsigned long long sum = 0;

			long long b_l = l / len, b_r = r / len;

			if (b_l == b_r)
			{
				for (long long i = l; i <= r; i++)
					sum += a[i] + p_b[i / len];
			}
			else
			{

				for (long long i = l; i < (b_l + 1)*len; i++)
					sum += a[i] + p_b[i / len];

				for (long long i = b_l + 1; i < b_r; i++)
					sum += b[i] + p_b[i] * len;

				for (long long i = b_r * len; i <= r; i++)
					sum += a[i] + p_b[i / len];
			}

			cout << sum << endl;
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
					b[i / len] += x;
				}
			}
			else
			{

				for (long long i = l; i < (b_l + 1)*len; i++)
				{
					a[i] += x;
					b[i / len] += x;
				}

				for (long long i = b_l + 1; i < b_r; i++)
				{
					p_b[i] += x;
				}

				for (long long i = b_r * len; i <= r; i++)
				{
					a[i] += x;
					b[i / len] += x;
				}
			}
		}
	}
}