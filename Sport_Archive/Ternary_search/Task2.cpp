/*
У маленького пингвина Поло есть матрица n???m, состоящая из целых чисел. Пронумеруем строки матрицы от 1 до n сверху вниз, а столбцы от 1 до m слева направо. Обозначим через aij элемент матрицы, стоящий на пересечении i-ой строки и j-го столбца.
За один шаг пингвин может добавить к любому элементу матрицы или отнять от любого элемента матрицы число d. Найдите минимальное количество шагов, которое требуется для того, чтобы все элементы матрицы были равны между собой. Если описанное невозможно, сообщите об этом.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using  namespace std;

vector<int> v;
int d, ost;

int F(int x)
{
    int res = 0;

    for (int i = 0; i < v.size(); i++)
    {
        res += abs(v[i] - (d*x + ost)) / d;
    }


    return res;
}

int main()
{
    int n, m; cin >> n >> m >> d;

    v.resize(n*m);
    cin >> v[0];

    ost = v[0] % d;
    bool ok = true;

    for (int i = 1; i < v.size(); i++)
    {
        cin >> v[i];
        if (v[i] % d != ost)
            ok = false;
    }

    if (!ok)
    {
        cout << -1 << endl;
    }
    else
    {
        int l = 0, r = 1e5 + 5;

        for (int i = 0; i < 100; i++)
        {
            int m1 = (r + 2 * l) / 3;

            int m2 = (l + 2 * r) / 3;

            if (F(m1) > F(m2))
            {
                l = m1;
            }
            else
            {
                r = m2;
            }
        }

        cout << min({F(l), F(l + 1), F(l + 2), F(l + 3)}) << endl;

    }
}
/* Wed Apr 17 2019 01:19:49 GMT+0300 (MSK) */
