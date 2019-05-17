/*
В Парке юрского периода чрезвычайное положение: из вольера сбежал тираннозавр. Сейчас этот ящер находится где-то в лесу возле парка.
На случай побега тираннозавру был вживлен специальный маячок, а в лесу установлены антенны, которые могут оценить расстояние от себя до маячка и передавать их в центр управления Парком.
И вот поступили сигналы от трех таких антенн. Антенны имеют координаты (x1,y1), (x2,y2) и (x3,y3), координаты антенн попарно различны и, что важно, эти три антенны не находятся на одной прямой. Расстояния, которые передали антенны – r1, r2, r3 соответственно. Во время передачи данных мог произойти сбой, поэтому не гарантируется, что полученные расстояния корректны.
Ваша задача: определить предполагаемые координаты тираннозавра по полученным данным, если это возможно.
*/
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

const double pi = acos(-1);
const double eps = 1e-6;

struct pt
{
	double x, y;

	pt(double x = 0, double y = 0) : x(x), y(y)
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

struct circle
{
	double r;
	pt a;

	circle(double x, double y, double r1)
	{
		r = r1;
		a.x = x;
		a.y = y;
	}
};

double dist2(pt a)
{
	return a.x*a.x + a.y*a.y;
}

double sk(pt a, pt b)
{
	return a.x*b.x + a.y*b.y;
}

double vec(pt a, pt b)
{
	return a.x*b.y - a.y*b.x;
}


double ug(pt a, pt b)
{
	return acos(sk(a, b) / (sqrt(dist2(a)) * sqrt(dist2(b))));
}


pt turn(double a, pt A)
{
	pt res(A.x*cos(a) + sin(a)*A.y, A.y*cos(a) - A.x*sin(a));
	return res;
}

pt normalize(pt res, double to)
{
	double a = sqrt(dist2(res));

	pt ans(res.x * to / a, res.y * to / a);
	return ans;
}

vector<pt> check_circle(circle A, circle B)
{
	vector<pt> ans;

	if (fabs(A.a.x - B.a.x) < eps && fabs(A.a.y - B.a.y) < eps && fabs(A.r - B.r) < eps)
	{
	}
	else if ((A.r - B.r)*(A.r - B.r) <= dist2(A.a - B.a) && dist2(A.a - B.a) <= (A.r + B.r)*(A.r + B.r))
	{
		double a, b, c;
		a = A.r;
		b = B.r;
		c = sqrt(dist2(A.a - B.a));

		double alph = acos((a*a + c * c - b * b) / (2 * a*c));

		pt res = turn(alph, B.a - A.a);
		pt res1 = turn(-alph, B.a - A.a);

		res = normalize(res, A.r);
		res1 = normalize(res1, A.r);

		res = res + A.a;
		res1 = res1 + A.a;

		ans.push_back(res);
		ans.push_back(res1);
	}

	return ans;
}

int main()
{
	int x1, y1; cin >> x1 >> y1;
	int x2, y2; cin >> x2 >> y2;
	int x3, y3; cin >> x3 >> y3;

	int r1, r2, r3; cin >> r1 >> r2 >> r3;

	cout.precision(8);

	circle A(x1, y1, r1);
	circle B(x2, y2, r2);
	circle C(x3, y3, r3);

	vector<pt> res1 = check_circle(A, B);

	if (res1.size() != 0)
	{
		if (fabs(res1[0].x - res1[1].x) < eps && fabs(res1[0].y - res1[1].y) < eps)
			res1.pop_back();

		vector<pt> ans;

		for (int i = 0; i < res1.size(); i++)
		{
			if (fabs(dist2(C.a - res1[i]) - r3 * r3) < eps)
				ans.push_back(res1[i]);
		}

		if (ans.size() > 0)
		{
			cout << "YES" << endl;
			cout << fixed << ans[0].x << " " << ans[0].y;
		}
		else
			cout << "NO";
	}
	else
		cout << "NO";
}