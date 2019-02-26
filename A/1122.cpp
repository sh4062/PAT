/*
 * File: 1122.cpp
 * Project: A
 * File Created: Tuesday, 26th February 2019 1:48:25 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 26th February 2019 1:49:38 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2001;
int edge[maxn][maxn]; //使用邻接矩阵存边的信息

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int N, M, K;
    cin >> N >> M;
    int i, j, z;
    int ver1, ver2;
    set<int> vertex;
    for (i = 0; i < M; i++)
    {
        cin >> ver1 >> ver2;
        edge[ver1][ver2] = 1; //有边
        edge[ver2][ver1] = 1; //有边
    }

    cin >> K;
    int verNum;
    int query[maxn];
    for (i = 0; i < K; i++)
    {
        cin >> verNum;
        memset(query, 0, sizeof(query)); //重置为0
        vertex.clear();
        for (j = 0; j < verNum; j++)
        {
            cin >> query[j];
            vertex.insert(query[j]);
        }
        if (verNum != (N + 1) || query[0] != query[N] || vertex.size() != N)
        { //是否 simple || 如果起点和终点不同，不是cycle ||如果不涉及到所有的节点
            cout << "NO\n";
        }
        else
        { //这个时候才进入判断
            for (z = 0; z < verNum - 1; z++)
            {
                //cout <<  query[z]<<" ";
                if (edge[query[z]][query[z + 1]] != 1)
                {
                    cout << "NO\n";
                    break;
                }
            }
            if (z == verNum - 1)
            {
                cout << "YES\n";
            }
        }
    }
}
