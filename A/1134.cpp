/*
 * File: 1134.cpp
 * Project: A
 * File Created: Sunday, 24th February 2019 3:47:23 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Sunday, 24th February 2019 3:47:49 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, set<int>> G;
vector<vector<int>> edges(10001);
set<int> s;
int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < b; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        // edges[i].insert(v1);
        // edges[i].insert(v2);
        edges[v1].push_back(i);
        edges[v2].push_back(i);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        vector<int> qs;
        int flag = 1;
        vector<int> hash(b, 0);
        for (int i = 0; i < t; i++)
        {
            int tt = 0;
            cin >> tt;
            qs.push_back(tt);
            for (int ii = 0; ii < edges[tt].size(); ii++)
            {
                
                    hash[edges[tt][ii]] = 1;
                
            }
        }
        for (int i = 0; i < b; i++)
        {
            if (hash[i] != 1)
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
}