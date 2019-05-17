/*
� ������� ����� ������������� ������� ����� ��� ������� ������������ ���� � ����. ���������� �� ��� �� ���������������� ���� ������� L ������. ������������ �����, ���� ����� � �� ���������� ������ ����.
������ �� ��������� �������. ������ ������� �� ��������� ����� � ������ ���������� �� ������������� ��������� ����. ���� � ���������� ��������� �������� ����� � ����������. �� ����� ������� ����� ����������� ���� ��������� ����� � ��������� �����, ����� ���� ���������� X ������ (������ ������� ����� �������� �� �� � ���������). ��������������, ���� ��������� ���� � ���������� X ? 1 ����� � ������, �� �� ��������� ����� � ��������� ����� ����, � ���� � ���������� X ������ � ������, �� ���� ��������� ���, � ���� ������� ����.
��������� ������������ ���� ������������ ����� �����, ���� ������� ������� ��������� ����� ������� �� X ������ �� �����, ��� ������ ���������, ���� ��� ����������� ����������, ����������� ������� �� �����.
������ ���������� X ���� ����������. ����� ����� X, ���� ������ ��������� ����� �������� � ��������� ���������� � �����������, ������ ��������� ������ ����������. ��� �������� ��������: � ���� ��������� �������� ������ �� ����� ��������. ������ ��� ���� �������� �� ��� ����� ������ ��� ����� ��� ��������, �� ���� ��� ��� ����� ������.
��� ������ �������������.
����� ��������� ��������� ���������� � ������ �� ������� ��������� �������� � �������� ���������� �� ����������� ������� � ���, ���� �������� ������.
������� �� ���, ����� ���� �� ���� ������ ���� ��������!

����� ����, ��� �� ������� �����, �� ����������� ��� � ����������� ������� � ���������� ������ ���������.
*/
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <iterator>

using namespace std;

int l;

void go(int start, int pos)
{
    int ans = -1;

    for (int i = start; i < pos; i++)
    {
        cout << "? " << i << endl;

        string s1, s2, s3; cin >> s1 >> s2 >> s3;

        if (s1[0] == 'V')
        {
            ans = i;
            break;
        }
    }

    if (ans == -1)
        ans = pos;

    cout << "! " << ans << endl;

}

int main()
{
    cin >> l;

    int ans = 0;

    int r = 5*10000; //5*10000

    if (l <= r)
    {
        go(1, l);
    }
    else
    {
        int start = 1, ch = 5*10000 - 1, pos = 5*10000 - 1, k = 1;

        while(pos <= l)
        {
            cout << "? " << pos << endl;
            string s1, s2, s3; cin >> s1 >> s2 >> s3;

            if (s1[0] == 'V')
            {
                go(start, pos);
                break;
            }

            int c = pos;

            pos += (ch - k);
            k++;

            start = c + 1;

            if (pos >= l)
            {
                go(start, l);
            }
        }
    }
}