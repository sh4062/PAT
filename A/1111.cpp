/*
 * File: 1111.cpp
 * Project: A
 * File Created: Wednesday, 27th February 2019 5:37:38 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 27th February 2019 5:37:42 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
//dfs超时啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
#include <bits/stdc++.h>
using namespace std;
int G[505][505] = {0};
int GT[505][505] = {0};
int vis[505] = {0};
int vis2[505] = {0};
int mind = INT_MAX, mint = INT_MAX, dd = INT_MAX, tt = INT_MAX;
int tmp_dd = 0, tmp_tt = 0;
vector<int> path1;
vector<int> path2;
vector<int> resd;
vector<int> rest;
int res_size1, res_size2;
void dfs(int s, int d)
{
    if (s == d)
    {
        if (mind == tmp_dd &&tt>tmp_tt)
        {
            //cout<<tmp_tt<<endl;
            resd = path1;
            resd.push_back(d);
            res_size1 = resd.size();
            tt = tmp_tt;
        }
        if (mint == tmp_tt && res_size2 - 1 > path2.size() )
        {
            rest = path2;
            rest.push_back(d);
            res_size2 = rest.size();
        }
        if (mint > tmp_tt)
        {
            mint = tmp_tt;
            rest = path2;
            rest.push_back(d);
            res_size2 = rest.size();
        }
        if (mind > tmp_dd)
        {
            mind = tmp_dd;
            resd = path1;
            resd.push_back(d);
            res_size1 = resd.size();
            tt=tmp_tt;
            //cout<<tmp_tt<<endl;
        }

        return;
    }
    vis[s] = 1;
    for (int i = 0; i < 505; i++)
    {
        if (G[s][i] != 0 && vis[i] == 0)
        {
            tmp_tt += GT[s][i];
            tmp_dd += G[s][i];
            vis[i] = 1;
            path1.push_back(i);
            path2.push_back(i);
            dfs(i, d);
            path1.pop_back();
            path2.pop_back();
            vis[i] = 0;
            tmp_dd -= G[s][i];
            tmp_tt -= GT[s][i];
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(G, 0, sizeof(G));
    memset(GT, 0, sizeof(GT));
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2, one, len, tim;
        cin >> v1 >> v2 >> one >> len >> tim;
        if (len == 1)
        {
            G[v1][v2] = len;
            GT[v1][v2] = tim;
        }
        else
        {
            G[v1][v2] = len;
            G[v2][v1] = len;
            GT[v1][v2] = tim;
            GT[v2][v1] = tim;
        }
    }
    int q1, q2;
    cin >> q1 >> q2;
    path1.push_back(q1);
    path2.push_back(q2);
    dfs(q1, q2);
    //cout << mind << mint;
    int flag = 1;
    for (int i = 1; i < min(rest.size(), resd.size()) ; i++)
    {
        if (rest.size() != resd.size())
        {
            flag = 0;
            //cout<<"!";
            break;
        }
        if (rest[i] != resd[i])
        {
            flag = 0;
            // cout<<i;
            // cout<<rest[i]<<resd[i];
            break;
        }
    }
    if (flag)
    {
        printf("Distance = %d; Time = %d: ", mind, mint);
        cout << q1;
        for (int i = 1; i < resd.size() - 1; i++)
        {
            cout << " -> " << resd[i];
        }
    }
    else
    {
        printf("Distance = %d: ", mind);
        cout << q1;
        for (int i = 1; i < resd.size() - 1; i++)
        {
            cout << " -> " << resd[i];
        }
        printf("\nTime = %d: ", mint);
        cout << q1;
        for (int i = 1; i < rest.size() - 1; i++)
        {
            cout << " -> " << rest[i];
        }
    }
}
////别人的 来自https://blog.csdn.net/liuchuo/article/details/52487847
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 999999999;
int dis[510], Time[510], e[510][510], w[510][510], dispre[510],Timepre[510], weight[510],NodeNum[510];
bool visit[510];
vector<int> dispath, Timepath, temppath;
int st, fin, minnode = inf;
void dfsdispath(int v) {
    dispath.push_back(v);
    if(v == st) return ;
    dfsdispath(dispre[v]);
}
void dfsTimepath(int v) {
    Timepath.push_back(v);
    if(v == st) return ;
    dfsTimepath(Timepre[v]);
}
int main() {
    fill(dis, dis + 510, inf);
    fill(Time, Time + 510, inf);
    fill(weight, weight + 510, inf);
    fill(e[0], e[0] + 510 * 510, inf);
    fill(w[0], w[0] + 510 * 510, inf);
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b, flag, len, t;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &a, &b, &flag, &len, &t);
        e[a][b] = len;
        w[a][b] = t;
        if(flag != 1) {
            e[b][a] = len;
            w[b][a] = t;
        }
    }
    scanf("%d %d", &st, &fin);
    dis[st] = 0;
    for(int i = 0; i < n; i++)
        dispre[i] = i;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(e[u][v] + dis[u] < dis[v]) {
                    dis[v] = e[u][v] + dis[u];
                    dispre[v] = u;
                    weight[v] = weight[u] + w[u][v];
                } else if(e[u][v] + dis[u] == dis[v] && weight[v] > weight[u] + w[u][v]) {
                    weight[v] = weight[u] + w[u][v];
                    dispre[v] = u;
                }
            }
        }
    }
    dfsdispath(fin);
    Time[st] = 0;
    fill(visit, visit + 510, false);
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && minn > Time[j]) {
                u = j;
                minn = Time[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && w[u][v] != inf) {
                if(w[u][v] + Time[u] < Time[v]) {
                    Time[v] = w[u][v] + Time[u];
                    Timepre[v]=(u);
                    NodeNum[v]=NodeNum[u]+1;
                } else if(w[u][v] + Time[u] == Time[v]&&NodeNum[u]+1<NodeNum[v]) {
                    Timepre[v]=(u);
                    NodeNum[v]=NodeNum[u]+1;
                }
            }
        }
    }
    dfsTimepath(fin);
    printf("Distance = %d", dis[fin]);
    if(dispath == Timepath) {
        printf("; Time = %d: ", Time[fin]);
    } else {
        printf(": ");
        for(int i = dispath.size() - 1; i >= 0; i--) {
            printf("%d", dispath[i]);
            if(i != 0) printf(" -> ");
        }
        printf("\nTime = %d: ", Time[fin]);
    }
    for(int i = Timepath.size() - 1; i >= 0; i--) {
        printf("%d", Timepath[i]);
        if(i != 0) printf(" -> ");
    }
    return 0;
}
