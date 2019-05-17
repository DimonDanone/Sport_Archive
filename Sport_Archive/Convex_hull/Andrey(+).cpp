#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct pt
{
	long long x, y;

	pt(long long x = 0, long long y = 0) : x(x), y(y)
	{}

	pt operator +(pt b)
	{
		pt c;
		c.x = x + b.x;
		c.y = y + b.y;
		return c;
	}

	pt operator -(pt b)
	{
		pt c;
		c.x = x - b.x;
		c.y = y - b.y;
		return c;
	}
};

struct line
{
	long long a, b, c;

	line(long long a, long long b, long long c) : a(a), b(b), c(c)
	{}

	line(long long x1, long long y1, long long x2, long long y2) : a(y2 - y1), b(x1 - x2), c(y1*x2 - y2 * x1)
	{}

	line(pt a, pt b) : a(b.y - a.y), b(a.x - b.x), c(a.y*b.x - b.y*a.x)
	{}
};

long long vec(pt a, pt b)
{
	return a.x*b.y - a.y*b.x;
}


pt cur1;
pt cur2;

bool comp(pt a, pt b)
{
	if (a.x == b.x)
		return a.y < b.y;

	return a.x < b.x;
}

int main()
{
	long long n;
	cin >> n;

	vector<pt> v(n);

	for (long long i = 0; i < n; i++)
	{
		long long x, y; cin >> x >> y;
		v[i] = pt(x, y);
	}

	long long x_min = 1e9 + 9;
	long long x_max = -1e9 - 9;

	for (long long i = 0; i < n; i++)
	{
		if (v[i].x < x_min)
		{
			x_min = v[i].x;
			cur1 = v[i];
		}
		else if (v[i].x == x_min && v[i].y < cur1.y)
		{
			cur1 = v[i];
		}

		if (v[i].x > x_max)
		{
			x_max = v[i].x;
			cur2 = v[i];
		}
		else if (v[i].x == x_max && v[i].y > cur2.y)
		{
			cur2 = v[i];
		}
	}

	vector<pt> more;
	vector<pt> less;

	for (long long i = 0; i < n; i++)
	{
		long long check = vec(cur2 - cur1, v[i] - cur1);

		if (check > 0)
		{
			more.push_back(v[i]);
		}
		else if (check < 0)
		{
			less.push_back(v[i]);
		}
	}

	sort(more.begin(), more.end(), comp);
	vector<pt> res1;

	res1.push_back(cur1);


	if (!more.empty())
	{
		more.push_back(cur2);
		res1.push_back(more[0]);

		for (long long i = 1; i < more.size(); i++)
		{
			long long r = vec(res1[res1.size() - 1] - res1[res1.size() - 2], more[i] - res1[res1.size() - 1]);

			if (r < 0)
			{
				res1.push_back(more[i]);
			}
			else
			{
				while (res1.size() > 1 && vec(res1[res1.size() - 1] - res1[res1.size() - 2], more[i] - res1[res1.size() - 1]) >= 0)
				{
					res1.pop_back();
				}

				res1.push_back(more[i]);
			}
		}

		res1.pop_back();

	}

	sort(less.rbegin(), less.rend(), comp);

	vector<pt> res2;

	res2.push_back(cur2);

	if (!less.empty())
	{
		res2.push_back(less[0]);
		less.push_back(cur1);

		for (long long i = 1; i < less.size(); i++)
		{
			long long r = vec(res2[res2.size() - 1] - res2[res2.size() - 2], less[i] - res2[res2.size() - 1]);

			if (r < 0)
			{
				res2.push_back(less[i]);
			}
			else
			{
				while (res2.size() > 1 && vec(res2[res2.size() - 1] - res2[res2.size() - 2], less[i] - res2[res2.size() - 1]) >= 0)
				{
					res2.pop_back();
				}

				res2.push_back(less[i]);
			}
		}

		res2.pop_back();
	}

	if (cur1.x == cur2.x && cur1.y == cur2.y)
	{
		cout << 1 << endl;
		cout << cur1.x << " " << cur1.y;
	}
	else
	{
		cout << res1.size() + res2.size() << endl;

		for (long long i = 0; i < res1.size(); i++)
		{
			cout << res1[i].x << " " << res1[i].y << endl;
		}

		for (long long i = 0; i < res2.size(); i++)
		{
			cout << res2[i].x << " " << res2[i].y << endl;
		}
	}

}
