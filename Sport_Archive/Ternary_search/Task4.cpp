/*
В галактике находится n планет, на каждой из которых обитают множество различных живых существ. И каждое из них может оказаться в беде! Космические спасатели прекрасно знают об этом и всегда готовы помочь каждому, кому эта помощь действительно понадобится. Стоит только позвать.
Сейчас космические спасатели планируют построить самую большую в истории галактики спасательную базу, однако месторасположение будущей базы пока еще не определено. Поскольку помощь иногда требуется абсолютно неотложно, спасатели стремятся найти такую точку в галактике, из которой можно было бы добраться до самой удаленной планеты за наименьшее возможное время. Другими словами, необходимо найти такую точку в пространстве, чтобы расстояние от нее до самой удаленной от нее планеты было наименьшим из всех возможных точек в пространстве. К сожалению, они не в силах решить такую задачу.
Поскольку планеты достаточно удалены друг от друга, их можно считать точками в евклидовом трехмерном пространстве. 
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using  namespace std;

double min_x = -1e4 - 3, min_y = -1e4 - 3, min_z = -1e4 - 3, max_x = 1e4 + 3, max_y = 1e4 + 3, max_z = 1e4 + 3;

double const eps = 1e-7;

vector<double> ans(3);

vector<vector<double>> planets;

double F(double x, double y, double z)
{
    double max_rast = -1;

    for (int i = 0; i < planets.size(); i++)
    {
        double r = sqrt((x - planets[i][0])*(x - planets[i][0]) + (y - planets[i][1])*(y - planets[i][1]) + (z - planets[i][2])*(z - planets[i][2]));
        if (r > max_rast)
        {
            max_rast = r;
        }
    }

    return  max_rast;
}

double Z(double x, double y)
{
    double l = min_z, r = max_z;

    while (r - l > eps)
    {
        double m1 = (r + 2 * l) / 3;

        double m2 = (l + 2 * r) / 3;

        if (F(x, y, m1) > F(x, y, m2))
            l = m1;
        else
            r = m2;
    }

    ans[2] = l;

    return  F(x, y, l);

}

double Y(double x)
{
    double l = min_y, r = max_y;

    while (r - l > eps)
    {
        double m1 = (r + 2 * l) / 3;

        double m2 = (l + 2 * r) / 3;

        if (Z(x, m1) > Z(x, m2))
            l = m1;
        else
            r = m2;
    }

    ans[1] = l;

    return  Z(x, l);
}

int main()
{
    int n; cin >> n;

    planets.resize(n, vector<double>(3));

    cout.precision(6);

    for (int i = 0; i < n; i++)
    {
        cin >> planets[i][0] >> planets[i][1] >> planets[i][2];
    }

    if (n == 1)
    {
        cout << fixed << planets[0][0] << " " << planets[0][1] << " " << planets[0][2];
    }
    else
    {
        double l = min_x, r = max_x;

        while (r - l > eps) {
            double m1 = (r + 2 * l) / 3;

            double m2 = (l + 2 * r) / 3;

            if (Y(m1) > Y(m2))
                l = m1;
            else
                r = m2;
        }

        ans[0] = l;

        cout << fixed << ans[0];
        cout << " ";
        cout << fixed << ans[1];
        cout << " ";
        cout << fixed << ans[2];
    }

}

/* Mon Apr 15 2019 20:40:25 GMT+0300 (MSK) */
