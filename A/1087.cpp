/*
 * File: 1087.cpp
 * Project: A
 * File Created: Friday, 1st March 2019 4:23:08 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 1st March 2019 4:23:14 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
vector<string> v;
int num, maxtotalhappy;
double maxavghappy;
int path[205] = {0};
int G[205][205] = {0};
int dis[205] = {0};
int vis[205] = {0};
int w[205] = {0};
int h[205];     //原点到i点的快乐值总数
int nums[205];  //原点到i点的城市总数
int route[205]; //最短的路线总数
int pre[205];   //i点的前驱结点
void dfs(int t){
	if(t==0){
		cout<<v[0];
		return;
	}
	dfs(pre[t]);
	cout<<"->"<<v[t];
}
int main()
{
    fill(G[0], G[0] + 205 * 205, INT_MAX);
    fill(dis, dis + 205, INT_MAX);
    int N, K;
    cin >> N >> K;
    string t;
    cin >> t;
    int cnt = 0;
    mp[t] = cnt;
    v.push_back(t);
    cnt++;
    int tt;
    for (; cnt < N; cnt++)
    {
        cin >> t;
        mp[t] = cnt;
        v.push_back(t);
        cin >> tt;
        w[cnt] = tt;
    }
    for (int i = 0; i < K; i++)
    {
        string a, b;
        int ttt;
        cin >> a >> b >> ttt;
        G[mp[a]][mp[b]] = ttt;
        G[mp[b]][mp[a]] = ttt;
    }
    dis[0] = 0;
    h[0] = 0;
    nums[0] = 1;
    pre[0] = 0;
    route[0] = 1;
    for (int i = 0; i < N; i++)
    {
        int u = -1;
        int min = INT_MAX;
        for (int j = 0; j < N; j++)
        {
            if (vis[j] == false && dis[j] < min)
            {
                min = dis[j];
                u = j;
            }
        }
        if (u == -1)
            break;
        vis[u] = true;
        for (int j = 0; j < N; j++)
        {
            if (vis[j] == false && G[u][j] != INT_MAX)
            {
                if (dis[j] > dis[u] + G[u][j])
                {
                    dis[j] = dis[u] + G[u][j];
                    route[j] = route[u];
                    // pre[v].clear();
                    // pre[v].push_back(u);
                    h[j] = h[u] + w[j];
                    nums[j] = nums[u] + 1;
                    pre[j] = u;
                }
                else if (dis[j] == dis[u] + G[u][j])
                {
                    route[j] += route[u];
                    if (h[j] < h[u] + w[j])
                    { //如果新路径快乐值更大，更新
                        h[j] = h[u] + w[j];
                        nums[j] = nums[u] + 1;
                        pre[j] = u;
                    }
                    else if (h[j] == h[u] + w[j])
                    { //如果连快乐值也相等
                        if (nums[j] > nums[u] + 1)
                        { //如果路经的城市更少，则平均快乐值更高，更新
                            nums[j] = nums[u] + 1;
                            pre[j] = u;
                        }

                        // pre[v].push_back(u);
                    }
                }
            }
        }
    }
    int rom = mp["ROM"];
    printf("%d %d %d %d\n", route[rom], dis[rom], h[rom], h[rom] / (nums[rom] - 1));
    //for (int i = path.size() - 1; i > 0; --i)
    //    cout << v[path[i]] << "->";
    //cout << "ROM";
    dfs(rom);
}