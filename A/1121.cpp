/*
 * File: 1121.cpp
 * Project: A
 * File Created: Tuesday, 26th February 2019 1:48:20 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 26th February 2019 1:49:35 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> G(100000);
int visited[501] = {0};
int cnt = 0;

int main()
{
    std::ios::sync_with_stdio(false);
std::cin.tie(0);

    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    map<int, int> qq;
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        qq[t] = 0;
    }
    for (auto i : qq)
    {
        for (int j = 0; j < G[i.first].size(); j++)
        {
            if (qq.find(G[i.first][j]) != qq.end())
            {
                qq[i.first] = 1;
            }
        }
    }
    vector<int> res;
    for (auto i : qq)
    {
        if (i.second == 0)
        {
            res.push_back(i.first);
        }
    }
    cout<<res.size()<<endl;
    if(res.size()>0)
    cout<<setfill('0')<<setw(5)<<res[0];
    for (int j = 1; j < res.size(); j++)
    {
        ;
        cout<<" ";
        cout<<setfill('0')<<setw(5)<<res[j];
    }
}