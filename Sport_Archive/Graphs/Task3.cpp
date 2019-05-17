/*
Дан ориентированный взвешенный граф. По его матрице смежности нужно для каждой пары вершин определить: существует кратчайший путь между ними или нет.

Кратчайший путь может не существовать по двум причинам: либо нет ни одного пути, либо есть путь сколь угодно маленького веса.
*/

#include iostream
#include vector

using namespace std;

long long min(long long a, long long b)
{
	if (a  b)
		return a;
	else
		return b;
}

long long max(long long a, long long b)
{
	if (a  b)
		return a;
	else
		return b;
}

struct edge
{
	long long from, to, w;
	edge() {}
	edge(long long from, long long to, long long w)  from(from), to(to), w(w) {}
};

int main()
{
	long long inf = 1e6;
	
	long long n;
	cin  n;

	vectorvectorlong long h(n, vectorlong long(n, inf));

	for (long long i = 0; i  n; i++)
		h[i][i] = 0;

	for (long long i = 0; i  n; i++)
		for (long long j = 0; j  n; j++)
		{
			long long a;
			cin  a;
			if (a != 0)
				h[i][j] = a;
		}

	
	for (long long k = 0; k  n; k++)
		for (long long i = 0; i  n; i++)
		{
			for (long long j = 0; j  n; j++)
			{
				if (h[i][k]  inf && h[k][j]  inf)
				{
					h[i][j] = min(h[i][j], h[i][k] + h[k][j]);
					h[i][j] = max(h[i][j], -inf);
				}
			}
		}

	for (long long i = 0; i  n; i++)
		for (long long j = 0; j  n; j++)
			for (long long k = 0; k  n; k++)
				if (h[i][k]  inf && h[k][k]  0 && h[k][j]  inf)
					h[i][j] = -inf;


	for (long long i = 0; i  n; i++)
	{
		for (long long j = 0; j  n; j++)
		{
			if (h[i][j] == -inf)
				cout  2   ;
			else if (h[i][j] != inf)
				cout  1   ;
			else
				cout  0   ;
		}
		cout  endl;
	}

}
