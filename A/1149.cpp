/*
 * File: 1149.cpp
 * Project: A
 * File Created: Friday, 22nd February 2019 4:08:44 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 22nd February 2019 4:17:17 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    map<int, vector<int>> m;
    int t1, t2;
    while (a--)
    {
        cin >> t1 >> t2;
        m[t1].push_back(t2);
        m[t2].push_back(t1);
    }
    
    while (b--)
    {
        int flag = 0;
        int c;
        cin >> c;
        vector<int> tmp;
        int mp[100000] = {0};
        int temp;
        int l = c;
        while (c--)
        {

            cin >> temp;
            tmp.push_back(temp);
            mp[temp] = 1;
        }
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < m[tmp[i]].size(); j++)
            {
                if (mp[m[tmp[i]][j]]==1)
                {
                    flag = 1;
                }
            }
        }
        tmp.clear();
        if (flag == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}