/*
Вам дана последовательность из n целых чисел a1,?a2,?...,?an.
Определите действительное число x, такое, чтобы слабость последовательности a1?-?x,?a2?-?x,?...,?an?-?x была как можно меньше.
Слабость последовательности определяется как максимальное значение бедности по всем отрезкам (непрерывным подпоследовательностям) последовательности.
Бедность отрезка определяется как модуль суммы элементов отрезка.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using  namespace std;

double const eps = 1e-9;

double max_sum(vector<double> &v, double x)
{
    double res1 = 0, now = 0;

    for (int i = 0; i < v.size(); i++)
    {
        now += v[i] - x;
        res1 = max(res1, now);
        now = max(now, 0.0);
    }

    now = 0;
    x *= -1;
    double res2 = 0;

    for (int i = 0; i < v.size(); i++)
    {
        now += -v[i] - x;
        res2 = max(res2, now);
        now = max(now, 0.0);
    }

    return max(res1, res2);

}


int main()
{
    int n; cin >> n;

    vector<double> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    double l = -1e5 - 4, r = 1e5 + 9;

    for (int i = 0; i < 100; i++)
    {
        double m1 = (r + 2 * l) / 3;

        double m2 = (l + 2 * r) / 3;

        if (max_sum(v, m1) > max_sum(v, m2))
            l = m1;
        else
            r = m2;
    }

    cout.precision(6);
    cout << fixed << max_sum(v, l) << endl;
}


/* Wed Apr 17 2019 01:08:28 GMT+0300 (MSK) */
