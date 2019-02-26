/*
 * File: 1126.cpp
 * Project: A
 * File Created: Tuesday, 26th February 2019 11:50:55 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 26th February 2019 11:50:58 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> G;
int visited[501] = {0};
int cnt = 0;
void dfs(int s)
{
    visited[s] = 1;
    cnt++;
    for (int i = 0; i < G[s].size(); i++)
    {
        if (visited[G[s][i]] == 0)
        {

            dfs(G[s][i]);
        }
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    G.resize(v + 1);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cnt = 0;
    dfs(1);
    //cout << cnt;
    if (cnt != v)
    {
        for (int i = 1; i < v; i++)
        {
            cout << G[i].size() << " ";
        }
        cout << G[v].size() << endl;
        cout << "Non-Eulerian\n";
        return 0;
    }
    int coun = 0;
    for (int i = 1; i <= v; i++)
    {
        if ((G[i].size()) % 2 == 0)
        {
            coun++;
        }
    }
    if (coun == v)
    {
        for (int i = 1; i < v; i++)
        {
            cout << G[i].size() << " ";
        }
        cout << G[v].size() << endl;
        cout << "Eulerian\n";
    }
    else if (coun == v - 2)
    {
        for (int i = 1; i < v; i++)
        {
            cout << G[i].size() << " ";
        }
        cout << G[v].size() << endl;
        cout << "Semi-Eulerian\n";
    }
    else
    {
        for (int i = 1; i < v; i++)
        {
            cout << G[i].size() << " ";
        }
        cout << G[v].size() << endl;
        cout << "Non-Eulerian\n";
        return 0;
    }
}