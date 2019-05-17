/*
 ак-то группе из N студентов-палеонтологов на лабораторное зан€тие преподаватель принес N образцов с мегаспорами, в каждом образце было много мегаспор. ѕричем в каждом образце несколько мегаспор были особенно прекрасны, а именно в i-том образце было ровно ai прекрасных мегаспор. ¬от и среди студентов возник мегаспор: как же делить прекрасные мегаспоры. » в мегаспоре родилась мегаистина: нужно вз€ть такие несколько образцов, чтобы суммарное количество прекрасных мегаспор в них было кратно N Ц числу студентов на зан€тии Ц тогда их можно будет поделить на всех поровну.
ћаленька€ проблема: какие вз€ть образцы, до сих пор не €сно.
ѕомогите палеонтологам, найдите такие образцы (или один образец), чтобы суммарное количество прекрасных мегаспор нацело делилось на N.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <iterator>

using namespace std;

int main()
{
    int n; cin >> n;

    vector<pair<int, int>> v(n);
    vector<long long> summ(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        v[i] = make_pair(a, i);
    }

    sort(v.begin(), v.end());

    map<int, vector<int>> ost;

    summ[0] = v[0].first;
    ost[summ[0] % n].push_back(0);

    for (int i = 1; i < n; i++)
    {
        summ[i] = summ[i - 1] + v[i].first;

        ost[summ[i] % n].push_back(i);
    }

    int l = 0, r = -2;

    for (int i = 0; i < n; i++)
    {
        if (summ[i] >= n)
        {
            if (summ[i] % n == 0)
            {
                l = 0;
                r = i;
                break;
            }

            int pos = -1;

            for (int j = 0; j < ost[summ[i] % n].size(); j++)
            {
                if (ost[summ[i] % n][j] < i)
                {
                    pos = ost[summ[i] % n][j] ;
                    break;
                }
                else
                {
                    break;
                }
            }

            if (pos != -1)
            {
                l = pos + 1;
                r = i;
                break;
            }
        }
    }

    vector<int> ans;

    for (int i = l; i <= r; i++)
    {
        ans.push_back(v[i].second + 1);
    }

    cout << ans.size() << endl;

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

}