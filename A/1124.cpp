/*
 * File: 1124.cpp
 * Project: A
 * File Created: Sunday, 24th February 2019 9:47:34 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 26th February 2019 11:49:11 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, s;
    cin >> m >> n >> s;
    int count = 0;
    vector<string> v(m + 1);
    unordered_set<string> se;
    vector<int> res;
    for (int i = 1; i <= m; i++)
    {
        cin >> v[i];
    }
    for (int i = s; i <= m; )
    {
        if (se.find(v[i]) == se.end())
        {

            se.insert(v[i]);
            res.push_back(i);
            i += n;
        }
        else
        {
                i++;
        }
    }
    if (se.size() == 0)
    {
        cout << "Keep going...";
    }
    else
    {
        for (auto i : res)
        {
            cout << v[i] << endl;
        }
    }
}