/*
 * File: 1154.cpp
 * Project: A
 * File Created: Thursday, 21st February 2019 3:39:24 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Thursday, 21st February 2019 3:39:29 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Outer Heaven
 */
#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int x, y;
} edges[10001];
int color[10001];
int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> edges[i].x >> edges[i].y;
    }
    int a = 0;
    cin >> a;

    for (int i = 0; i < a; i++)
    {
        int flag = 0;
        unordered_set<int> s;

        int c = 0;
        for (int j = 0; j < N; j++)
        {
            cin >> color[j];
            s.insert(color[j]);
        }
        for (int j = 0; j < M; j++)
        {
            if (color[edges[j].x] == color[edges[j].y])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << "No\n";
        else
        {
            cout << s.size() << "-coloring\n";
        }
    }
}
