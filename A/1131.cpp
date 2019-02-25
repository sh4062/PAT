/*
 * File: 1131.cpp
 * Project: A
 * File Created: Monday, 25th February 2019 8:10:57 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Monday, 25th February 2019 8:10:59 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> G{10000};
unordered_map<int, int> line;
int visited[10000] = {0};
int min_C, min_T;
vector<int> path, temp_path;
int transferCnt(vector<int> a)
{
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++)
    {
        if (line[a[i - 1] * 10000 + a[i]] != preLine)
            cnt++;
        preLine = line[a[i - 1] * 10000 + a[i]];
    }
    return cnt;
}
void dfs(int s, int d, int cnt)
{
    if (s == d && ((min_C > cnt) || (cnt == min_C && transferCnt(temp_path) < min_T))) //
    {
        min_C = cnt;
        path = temp_path;
        min_T = transferCnt(temp_path);
        return;
    }
    if (s == d)
    {
        return;
    }
    visited[s] = 1;

    for (int i = 0; i < G[s].size(); i++)
    {
        if (visited[G[s][i]] == 0)
        {
            temp_path.push_back(G[s][i]);
            dfs(G[s][i], d, cnt + 1);
            visited[G[s][i]] = 0;
            temp_path.pop_back();
        }
    }
}
int main()
{
    int a;
    cin >> a;

    for (int i = 1; i <= a; i++)
    {
        int b, pre, temp;
        cin >> b >> pre;
        for (int j = 1; j < b; j++)
        {
            scanf("%d", &temp);
            G[pre].push_back(temp);
            G[temp].push_back(pre);
            line[pre * 10000 + temp] = line[temp * 10000 + pre] = i;
            pre = temp;
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        fill(visited, visited + 10000, 0);
        int s, d;
        cin >> s >> d;
        min_C = 10000, min_T = 10000;
        temp_path.clear();
        temp_path.push_back(s);
        dfs(s, d, 0);
        cout << min_C << endl;
        int preLine = 0, preTransfer = s;
        //cout<<path.size()<<endl;
        for (int j = 1; j < path.size(); j++)
        {
            if (line[path[j-1]*10000+path[j]] != preLine) 
            {
                if (preLine != 0)
                    printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j - 1]);
                preLine = line[path[j-1]*10000+path[j]];
                preTransfer = path[j - 1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, d);
    }
}