/*
 * File: 1003.cpp
 * Project: A
 * File Created: Friday, 22nd February 2019 8:02:48 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 22nd February 2019 8:02:50 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Outer Heaven
 */
#include <bits/stdc++.h>
using namespace std;
const int maxv = 510;
const int INF = INT_MAX;
int G[maxv][maxv], weight[maxv];
int dist[maxv], num[maxv] = {0}, w[maxv] = {0}; //, path[maxv] = {0};
//num是路径数目，w是最大救援队数量
int v = 0, e = 0;
int c1, c2;
bool vis[maxv] = {0};
void Dijkstra(int c1)
{
    fill(dist, dist + maxv, INF);
    for (int i = 0; i < v; i++)
    {
        w[i] = weight[i];
        dist[i] = G[c1][i];
        if (G[c1][i] < INF)
        {
            w[i] = w[i] + w[c1];
        }
    }
    dist[c1] = 0;
    num[c1] = 1;
    vis[c1] == true;
    //选择一个顶点i,s到i最短
    for (int i = 0; i < v; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 0; j < v; j++)
        {
            if (vis[j] == false && dist[j] < MIN)
            {
                u = j;
                MIN = dist[j];
            }
        }
        //全部访问完毕
        if (u == -1)
            return;
        vis[u] = true;
        //已刚加入的顶点为中间点，对所有出边进行检测
        for (int j = 0; j < v; j++)
        {
            if (vis[j] == false && G[u][j] != INF)
            {
                if (dist[u] + G[u][j] < dist[j])
                {
                    dist[j] = dist[u] + G[u][j];
                    //           path[v] = u;
                    w[j] = w[u] + weight[j];
                    num[j] = num[u];//求最短路径条数
                }
                else if (dist[u] + G[u][j] == dist[j])
                {
                    num[j] += num[u];
                    if (w[u] + weight[j] > w[j])
                    {
                        w[j] = w[u] + weight[j];
                    }
                }
            }
        }
    }
}
int main()
{

    cin >> v >> e >> c1 >> c2;
    for (int i = 0; i < v; i++) //救援队数目
    {
        cin >> weight[i];
    }
    int x1, x2;
    fill(G[0], G[0] + maxv * maxv, INF);
    for (int i = 0; i < e; i++) //路
    {
        cin >> x1 >> x2;
        cin >> G[x1][x2];
        G[x2][x1] = G[x1][x2];
    }

    Dijkstra(c1);
    cout << num[c2] << " " << w[c2];
}