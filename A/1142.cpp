/*
 * File: 1142.cpp
 * Project: A
 * File Created: Saturday, 23rd February 2019 2:15:57 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Saturday, 23rd February 2019 2:15:58 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
int G[201][201] = {0};
set<int> s;
int main()
{
    int a, b;
    cin >> a >> b;
    while (b--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        G[v1][v2] = 1;
        G[v2][v1] = G[v1][v2];
    }
    int q = 0, t = 0;
    cin >> q;

    while (q--)
    {
        int flag = 1;
        cin >> t;
        vector<int> qs(t);
        for (int i = 0; i < t; i++)
        {
            cin >> qs[i];
            s.insert(qs[i]);
        }
        for (int i = 0; i < t - 1; i++)
        {
            for (int j = i + 1; j < t; j++)
            {
                if (G[qs[i]][qs[j]] == 0)
                {
                    flag = 0;
                }
            }
        }
        if (flag)
        {
            int ff = 1;
            for (int j = 1; j <= a; j++)
            {
                if (s.find(j) == s.end())
                {
                    
                    int cnt = 0;
                    for (auto i : s)
                    {
                        if (G[j][i] != 0)
                        {
                            cnt++;
                        }
                        //cout<<cnt;
                    }
                    if (cnt == s.size())
                    {
                        cout << "Not Maximal\n";
                        s.clear();
                        ff = 0;
                        break;
                    }
                }
            }

            if (ff == 1)
            {
                cout << "Yes\n";
                s.clear();
            }
        }
        else
        {
            cout << "Not a Clique\n";
            s.clear();
        }
    }
}