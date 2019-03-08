/*
 * File: 1072.cpp
 * Project: A
 * File Created: Friday, 8th March 2019 4:03:46 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 8th March 2019 4:03:50 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
//日了狗啊 他的测试样例有问题 应该是3.2不是3.3
#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
vector<string> v;
int N, M, K, D;
int G[1012][1012] = {0};
int dis[1012] = {0};
int vis[1012] = {0};
int res;
double ming = 0, avgd = 0;
void dijkstra(int s)
{
    for (int i = 1; i <= 1011; i++)
    {
        vis[i] = 0;
        if (G[s][i] != INT_MAX)
        {
            dis[i] = G[s][i];
        }
        else
        {
            dis[i] = INT_MAX;
        }
    }
    for (int i = 0; i < 1011; i++)
    {
        int u = -1, minD = INT_MAX;
        for (int j = 1; j <= 1011; j++)
        {
            if (minD > dis[j] && vis[j] == 0)
            {
                u = j;
                minD = dis[j];
            }
        }
        if (u == -1)
            break;
        vis[u] = 1;
        for (int j = 1; j <= 1011; j++)
        {
            if (vis[j] == false && G[u][j] != INT_MAX && dis[j] > dis[u] + G[u][j])
            {
                dis[j] = dis[u] + G[u][j];
            }
        }
    }
}
int main()
{
    fill(G[0], G[0] + 1012 * 1012, INT_MAX);
    fill(dis, dis + 1012, INT_MAX);
    cin >> N >> M >> K >> D;
    string t1, t2;
    int dist;
    for (int i = 0; i < K; i++)
    {
        cin >> t1 >> t2 >> dist;
        int a = 0, b = 0;
        if (t1[0] == 'G')
        {
            t1 = t1.substr(1);
            a = stoi(t1) + 1000;
        }
        if (t2[0] == 'G')
        {
            t2 = t2.substr(1);
            b = stoi(t2) + 1000;
        }
        if (a == 0)
            a = stoi(t1);
        if (b == 0)
            b = stoi(t2);
        G[a][b] = dist;
        G[b][a] = dist;
    }
    //cout<<res<<endl;
    res = 0;
    for (int ii = 1001; ii <= 1000 + M; ii++)
    {
        //cout<<res<<endl;
        dijkstra(ii);
        //cout<<res<<endl;
        int flag = 1;
        int minn = INT_MAX;
        double sum = 0;
        for (int i = 1; i <= N; i++)
        {
            if (dis[i] > D)
            {
                //cout<<i<<dis[i]<<endl;
                flag = 0;
                break;
            }
            if (minn > dis[i])
                minn = dis[i];
            sum += dis[i];
        }
        if (flag)
        {
            if (res == 0)
            {
                
                res = ii;
                //cout<<sum<<" "<<res<<endl;
                ming = minn;
                avgd = sum / N;
            }
            else
            {
                if (ming < minn)
                {
                    //cout<<sum<<endl;
                    res = ii;
                    ming = minn;
                    avgd = sum / N;
                }
                else if (ming == minn && avgd > (sum) / N)
                {
                    res = ii;
                    avgd = sum / N;
                }
            }
        }   
    }
    if (avgd == 0)
    {
        cout << "No Solution";
    }
    else
    {
        cout << "G" << res - 1000 << endl;
        printf("%.1lf %.1lf", ming, avgd);
    }
}