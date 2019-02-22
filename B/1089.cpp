/*
 * File: 1089.cpp
 * Project: B
 * File Created: Thursday, 21st February 2019 8:05:58 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Thursday, 21st February 2019 8:06:01 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Outer Heaven
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin >> a;
    vector<int> v(a + 1);
    vector<int> v2(a + 1, 0);
    for (int i = 1; i <= a; i++)
    {
        cin >> v[i];
    }
    int res1 = 0, res2 = 0;
    for (int i = 1; i <= a; i++)
    {
        for (int j = i + 1; j <= a; j++)
        {
            int lie = 0, lie_w = 0;
            for (int k = 1; k <= a; k++)
            {
                //有人lie了
                if ((v[k] < 0 && (-v[k] != i && -v[k] != j)) || (v[k] > 0 && (v[k] == i || v[k] == j)))
                {
                    if (k != i && k != j)
                        lie++;
                    else
                        lie_w++;
                }
            }
            if (lie == 1 && lie_w == 1)
            {
                res1 = i;
                res2 = j;
                break;
            }
        }
        if (res1)
            break;
    }
    if (res1)
    {
        cout << res1 << ' ' << res2;
    }
    else
    {
        cout << "No Solution";
    }
}
