#include iostream
#include vector
#include cmath
#include algorithm

using namespace std;

struct pt
{
	long long x, y;

	pt(long long x = 0, long long y = 0)  x(x), y(y)
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

	line(long long a, long long b, long long c)  a(a), b(b), c(c)
	{}

	line(long long x1, long long y1, long long x2, long long y2)  a(y2 - y1), b(x1 - x2), c(y1x2 - y2  x1)
	{}

	line(pt a, pt b)  a(b.y - a.y), b(a.x - b.x), c(a.yb.x - b.ya.x)
	{}
};

long long vec(pt a, pt b)
{
	return a.xb.y - a.yb.x;
}

long long dist2(pt a)
{
	return  a.xa.x + a.ya.y;
}


pt cur(1e9, 1e9);

bool comp(pt a, pt b)
{
	pt a1 = a - cur;
	pt b1 = b - cur;

	long long v = vec(a1, b1);

	if (v == 0)
		return dist2(a1)  dist2(b1);
	else
		return v  0;
}

int main()
{
	long long n;
	cin  n;

	vectorpt v(n);

	for (long long i = 0; i n; i++)
	{
		long long x, y; cin  x  y;
		v[i] = pt(x, y);
	}

	for (int i = 0; i v.size(); i++)
	{
		if (v[i].y == cur.y && v[i].x  cur.x)
		{
			cur = v[i];
		}
		else if (v[i].y  cur.y)
		{
			cur = v[i];
		}

	}

	sort(v.begin(), v.end(), comp);

	vectorpt res;

	res.push_back(cur);
	res.push_back(v[1]);

	for (long long i = 2; i v.size(); i++) {
		long long r = vec(res[res.size() - 1] - res[res.size() - 2], v[i] - res[res.size() - 1]);

		if (r  0)
		{
			res.push_back(v[i]);
		}
		else
		{
			while (res.size()  1 && vec(res[res.size() - 1] - res[res.size() - 2], v[i] - res[res.size() - 1]) = 0)
			{
				res.pop_back();
			}

			res.push_back(v[i]);
		}
	}

	if (res[res.size() - 1].x == res[0].x && res[res.size() - 1].y == res[0].y)
	{

		cout  1  endl;
		cout  res[0].x     res[0].y  endl;
	}
	else
	{
		cout  res.size()  endl;

		for (int i = 0; i res.size(); i++)
			cout  res[i].x     res[i].y  endl;
	}
}
